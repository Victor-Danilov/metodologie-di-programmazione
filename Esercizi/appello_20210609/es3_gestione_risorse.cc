/*
    Il codice seguente contiene errori inerenti la corretta gestione delle risorse.
    Individuare almeno un problema, indicando con precisione la sequenza di eventi che
    porta alla sua occorrenza.
*/

void job(){
    Res* r1 = new Res("res1");
    Res* r2 = new Res("res2"); // qui abbiamo un potenziale problema se si lancia un'eccezione
    /*
        Il problema su r2 e' che se non si riesce ad acquisire la seconda risorsa
        la prima andra' in memory leak
    */
    try{
        do_task(r1, r2);
    }catch(...){ // qui abbiamo il secondo problema, se non lancio nessuna eccezione non entro in catch e non rilascio le risorse
        delete res1;
        delete res2; // la delete deve riferisi al letterale non al nome quind r2 non res2
        throw;
    }
}
/*
    Correggere il probelma individuato e fornire una soluzione cha sia exception safe
    e basata sull'idioma try/catch.
    ___________
    Risoluzione
    ___________
*/
void job(){
    Res* r1 = new Res("res1");
    try{ // risoluzione primo problema
        Res* r2 = new Res("res2"); 
        try{
            do_task(r1, r2);
            delete r2; // risoluzione secondo problema
            delete r1;
        }catch(...){
            delete r2;
            throw;
        }
    }catch(...){
        delete r1;
        throw;
    }
}
/*
    Fornire quindi una soluzione alternativa, basata sull'uso degli smart pointer
    della libreria standard.
    ___________
    Risoluzione
    ___________
    
    RAII-RRID? No solo RRID!
*/
void job(){
    // auto r1 = std::make_unique<Res>("res1");
    std::unique_ptr<Res> r1(new Res("res1"));
    /*
        Quando si usa uno smart pointer, una volta che questo va fuori scope viene
        invocato il suo distruttore sia in modalita' normale che eccezionale quindi non abbiamo
        bisogno dei blocchi try/catch
    */
    std::unique_ptr<Res> r2(new Res("res2"));
    do_task(r1.get(), r2.get());
}