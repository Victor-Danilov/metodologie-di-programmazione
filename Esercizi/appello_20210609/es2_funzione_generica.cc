/*
    Funzione generica

    Definire la funzione generica none_of che prende in input una sequenza ed un predicato unario
    e restituisce in output un booleano: la funzione restiruisce il valore true se e solo se nessuno
    degli elementi della sequenza soddisfano il predicato.
*/
#include<vector>
#include<string>
template<typename Iter, typename Pred>
// una sequenza generica e' definita dall'iteratore first e last
bool none_of(Iter first, Iter last, Pred pred){
    // dobbiamo scorrere la sequenza 
    for(; first!=last; ++first){
        // nessun membro della sequenza deve soddisfare il predicato, quindi se uno lo soddisfa restituisce false
        // i predicati unari sono callable quindi funzioni che restituiscono true o false
        if(pred(*first)) // *first e' l'elemento puntato da first
            return false;
    }
    // se non entro nel ciclo o esco immediatamente i casi sono due:
    // 1. non c'erano elementi
    // 2. first==last
    return true;
}
// ELENCARE I REQUEISITI DEI PARAMETRI DELLA FUNZIONE
/*
    I parametri sono: quelli dei template e quelli della funzione
    Requisiti:
        1. template: -Iter: deve essere qualcosa che si comporta come un input iterator.
                            deve dare la possibilita' di confrontare gli oggetti,
                            di incrementare e di andare a leggere con la differenziazione.
                     -Pred: deve essere qualcosa che si comporta come un predicato.
                            deve essere un callable in particolare che prenda un argomento
                            del tipo per il quale esiste una conversione dal tipo degli oggetti incontrati da Iter verso Pred.
                            deve restituire qualcosa che sia convertibile a bool.
        2. funzione: first/last: specificano una sequenza

*/


/*
    Scrivere inoltre una funzione che prende in input un vettore di stinghe, e usando la funzione none_of appena deifinita,
    controlla se nessuna delle stringhe contenute nel vettore inizia con una cifra decimale.
*/

// visto che una stringa e' potenzialmente pesante da copiare, e' ancora peggio copiare un vettore di stringhe
// quindi il vettore di stringhe lo passiamo per riferimento, e siccome lo dobbiamo solo leggere il vettore lo passiamo
// come riferimento costante
bool inizia_con_cifra(const std::string& s){
    // la stringa potrebbe anche essere vuota
    if(s.size()==0)
        return false;
    return std::isdigit(s[0]);
}
bool foo(const std::vector<std::string>& s){ 
    return none_of(s.begin(), s.end(), inizia_con_cifra); // alla funzione none_of viene passato il puntatore a funzione inizia_con_cifra
    //return none_of(std::begin(s), std::end(s), pred);
}