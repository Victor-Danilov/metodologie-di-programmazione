/*
    (Risoluzione Overloding)

    Mostrare il processo di risoluzione dell'overloading per le seguenti chiamate di funzione. Per ogni chiamata, indicare:
    1. l'insieme delle funzioni candidate
    2. l'insieme delle funzioni utilizzabili
    3. la migliore funzione utilizzabile (se esiste)
*/

namespace N{
    void foo(int, double);              // funzione #1
    void foo(double, int);              // funzione #2
} // namespace N

void foo(double, double);               // funzione #3

int main(){
    foo(42, 3.14);                      // chiamata A
    N::foo(42, 3.14);                   // chiamata B
    using namespace N;
    foo(4.14, 42);                      // chiamata C
    /*
        Cerco la foo, se non la trovo il compilatore la cerchera'
        nel namespace N, se la funzione foo viene trovata non entra nel namespace N
    */
    using N::foo;
    foo(42, 3.14);                      // chiamata D
    /*
        Qui diciamo che vogliamo le funzioni foo() del namespace N
    */
}
// ---------------------------------------------------------------------------
/*
    ___________
    RISOLUZIONE
    ___________

    A: cand: 3     utli: 3     migl: 3
    B: cand: 1,2   utli: 1,2   migl: 1
    C: cand: 3     utli: 3     migl: 3
    D: cand: 1,2   utli: 1,2   migl: 1
*/