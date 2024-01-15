namespace ND{
    class D{};
} // namespace ND

namespace NC{
    class C{
        public:
        C();
        C(double); // non explicit quindi fa conversione da double a C
    };
    void foo(int i);                                // Funzione #1
    void foo(double d, C c = C());                  // Funzione #2 
    void bar(C c = C(), ND::D d = ND::D());         // Funzione #3
    void zen(C c);                                  // Funzione #4
} // namespace NC

namespace ND{
        void foo(double d);                         // Funzione #5
        void bar(NC::C c = NC::C(), D d = D());     // Funzione #6
        void zen(NC::C c, D d);                     // Funzione #7
} // namespace ND

void foo(NC::C c, ND::D d);                         // Funzione #8

int main(){
    NC::C c;        
    ND::D d;        
    foo(2.0);       // Chiamata A
    NC::foo(2.0);   // Chiamata B
    foo(2.0, c);    // Chiamata C :il secondo argomento passato apre il namespace NC dove abbiamo altre funzioni
    foo(2.0, d);    // Chiamata D
    ND::foo(1.0);   // Chiamata E
    bar();          // Chiamata F
    bar(c);         // Chiamata G
    bar(c, d);      // Chiamata H : ambiguita' (risoluzione: modificare chiamata)
    zen(c);         // Chiamata I
}
//---------------------------------------------------------------------
/*
        ____________
        Risoluzione
        ____________

    A:: cand: 8     util: 0   migl: 0 in questo caso abbiamo un erroe dal compilatore perche' la chiamata passa un argomento mentre
                                      la funzione ne richiede due
    B:: cand: 1,2   util: 1,2 migl: 2 per match perfetto:  la funzione con un argomento di default non entra in gara
    C:: cand: 1,2,8 util: 2   migl: 2 per match perfetto
    D:: cand: 5,8   util: 8   migl: 8 nel namespace NC un oggetto di tipo C ha una converisione di tipo implicita C(double),
                                      quindi la chiamata C utilizza la funzione #8 convertendo il 2.0 in C(double) e passa d come oggetto
                                      di tipo D
    E:: cand: 5     util: 5   migl: 5
    F:: cand: 0     util: 0   migl: 0 errore di compilazione perche' bar non e' visibile
    G:: cand: 3     util: 3   migl: 3
    H:: cand: 3,6   util: 3,6 migl: ambiguo
    I:: cand: 4     util: 4   migl: 4 
*/