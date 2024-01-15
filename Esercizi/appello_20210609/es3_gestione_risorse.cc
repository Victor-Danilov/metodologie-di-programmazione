/*
    Il codice seguente contiene errori inerenti la corretta gestione delle risorse.
    Individuare almeno un problema, indicando con precisione la sequenza di eventi che
    porta alla sua occorrenza.
*/

void job(){
    Res* r1 = new Res("res1");
    Res* r2 = new Res("res2");
    try{
        do_task(r1, r2);
    }catch(...){
        delete res1;
    }
}