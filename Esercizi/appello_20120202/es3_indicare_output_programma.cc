#include <iostream>
using namespace std;

struct A{
    virtual void f(int) { cout << "A::f(int)" << endl; }
    virtual void f(double) { cout << "A::f(double)" << endl; }
    virtual void g() { cout << "A::g(double)" << endl; }
    virtual ~A() { cout << "Destructor A::~A()" << endl; }
};

struct B : public A{
    void f(int) { cout << "B::f(int)" << endl; }
    virtual void f(double) const { cout << "B::f(double) const" << endl; }
    virtual void g(int) { cout << "B::g(int)" << endl; }
    ~B() { cout << "Destructor B::~B()" << endl; }
};

struct C : public B{
    void f(int) const { cout << "C::f(int) const" << endl; }
    void g(int) { cout << "C::g(int)" << endl; }
    ~C() { cout << "Destructor C::~C()" << endl; }
};

int main(){
    A *a = new A; // puntatore a che punta a un tipo A e crea dinamicamente A
    B b;
    C c;
    A &ra_b = b;
    B &rb_b = b; // rb_b diventa un alias per l'oggetto b
    A &ra_c = c;
    B &rb_c = c;
    cout << "=== 1 ===" << endl;
    ra_b.f(1);
    rb_b.g(1);
    ra_c.f(1);
    rb_c.g(1);
    cout << "=== 2 ===" << endl;
    static_cast<A *>(&b)->f(1.2);
    /*
        '&b': Ottiene l'indirizzo di B denominato b
        'static_cast<A *>(&b)': Esegue un cast statico di tipo, convertendo l'indirizzo di b a un puntatore di tipo A*.
            Questo e' possibile poiche' B e' una classe derivata pubblicamente da A, quindi un puntatore a B puo' essere convertito a un puntatore
            a A senza problemi,
    */
    static_cast<A *>(&c)->f(1);
    static_cast<B *>(&c)->g(1.2);
    cout << "=== 3 ===" << endl;
    b.f(2);
    c.g(3);
    cout << "=== 4 ===" << endl;
}

/*  ___________
    Risoluzione
    ___________

    Costruzione A
    Costruzione B
    Costruzione C

    === 1 ===
    B::f(int)
    B::g(int)
    C::f(int) const :: sbagliata
    C::g(int)
    === 2 ===
    A::f(double)    :: entrambe le f di A e B sono virtuale e il compilatore sceglie quella non const
    B::f(int)       :: partendo da C una f const, andando in su da B abbiamo un override della A quindi viene scelta la f di B
    C::g(int)
    === 3 ===
    B::f(int)
    C::g(int)
    === 4 ===

    // distruzione C
    Destructor C::~C()
    Destructor B::~B()
    Destructor A::~A()

    // distruzione B
    Destructor B::~B()
    Destructor A::~A()


*/