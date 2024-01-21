/*
    Mostrare il processo di risoluzione dell'overloading per le seguenti chiamate di funzione.
    Per ogni chiamata, indicare: l'insieme delle funzioni candidate; l'insieme delle funzioni utilizzabili;
    la migliore funzione utilizzabile (se esiste); il motivo di eventuali errori di compilazione.
*/

#include <iostream>
class Base{
public:
    void f(int, double);                                // funzione #1
    void f(double, int) const;                          // funzione #2
    void g(double);                                     // funzione #3
    void print(std::ostream &) const;                   // funzione #4
};

class Derived : public Base{
public:
    using Base::f;
    void f(double, double);                             // funzione #5
    void g(double) const;                               // funzione #6
private:
    void print(std::ostream &);                         // funzione #7
};

int main(){
    Base b;
    Derived d;
    Base *pb = &d;
    const Derived *pd = &d;
    pb->print(std::cerr);                               // chiamata (a)
    pd->print(std::cout);                               // chiamata (b)
    b.f('a', 0.7);                                      // chiamata (c)
    d.f(12.5, 1.4);                                     // chiamata (d)
    pb->f(2, 0);                                        // chiamata (e)
    pd->f(7.2, 7);                                      // chiamata (f)
    const Base *pb2 = static_cast<const Base *>(pd);
    pb2->g(0.0);                                        // chiamata (g)
    pd->g(0.0);                                         // chiamata (h)
}

/*  ___________
    Risoluzione
    ___________

    A: cand: 4     util: 4       migl: 4
    B: cand: 7     util: nessuna migl: nessuna ; print di Derived non accessibile
    C: cand: 1,2   util: 1,2     migl: 1
    D: cand: 1,2,5 util: 1,2,5   migl: 5
    E: cand: 1,2,5 util: 1,5   migl: ambiguo
    F: cand: 1,2,5 util: 2       migl: 2
    G: cand: 3,6   util: 6       migl: 6
    H: cand: 6     util: 6       migl: 6
*/