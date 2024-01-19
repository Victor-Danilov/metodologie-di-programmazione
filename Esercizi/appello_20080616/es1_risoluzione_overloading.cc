#include <string>
namespace N{
    class C{
    private:
        std::string &first();             // funzione #1
    public:
        const std::string &first() const; // funzione #2
        std::string &last();              // funzione #3
        const std::string &last() const;  // funzione #4
        C(const char *);                  // funzione #5
    };                                    // class C
    void print(const C &);                // funzione #6
    std::string &f(int);                  // funzione #7
} // namespace N

class A{
public:
    explicit A(std::string &);            // funzione #8
    /*
        explicit indica che il cosrtuttore
        puo' essere utilizzato solo per
        conversioni esplicite ma non implicite
    */
};

void print(const A &);                    // funzione #9

void f(N::C &c)                           // funzione #10
{
    const std::string &f1 = c.first();    // chiamata A
    std::string &f2 = c.first();          // chiamata B
    const std::string &l1 = c.last();     // chiamata C
    std::string &l2 = c.last();           // chiamata D
}

void f(const N::C &c)                     // funzione #11
{
    const std::string &f1 = c.first();    // chiamata E
    std::string &f2 = c.first();          // chiamata F
    const std::string &l1 = c.last();     // chiamata G
    std::string &l2 = c.last();           // chiamata H
}

int main(){
    N::C c("begin");                      // chiamata I
    f(c);                                 // chiamata J
    f("middle");                          // chiamata L
    print("end");                         // chiamata M
}

/*  ___________
    Risoluzione
    ___________

    A: cand: 1,2    util: 2      migl: 2
    B: cand: 1,2    util: null   migl: null
    C: cand: 3,4    util: 4      migl: 4
    D: cand: 3,4    util: 3      migl: 3
    E: cand: 1,2    util: 2      migl: 2
    F: cand: errore util: errore migl: errore (oggetto richiesto const ma non dichiarato const)
    G: cand: 3,4    util: 4      migl: 4
    H: cand: errore util: errore migl: errore (oggetto richiesto const ma non dichiarato const)
    I: cand: 5      util: 5      migl: 5
    J: cand: 7      util: 7      migl: 7
    L: cand: 7      util: 7      migl: 7
    M: cand: 9      util: null   migl: null
*/