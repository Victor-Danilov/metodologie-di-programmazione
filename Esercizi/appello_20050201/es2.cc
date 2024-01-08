/* Indicare l'output prodotto dal seguente programma */
#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Constructor Base::Base()" << std::endl;
    }
    virtual void f(int)
    {
        std::cout << "Base::f(int)" << std::endl;
    }
    virtual void f(double)
    {
        std::cout << "Base::f(double)" << std::endl;
    }
    virtual void g(int)
    {
        std::cout << "Base::g(int)" << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "Destructor Base::~Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Constructor Derived::Derived()" << std::endl;
    }
    void f(char c)
    {
        std::cout << "Derived::f(char)" << std::endl;
    }
    void g(int)
    {
        std::cout << "Derived::g(int)" << std::endl;
    }
    ~Derived()
    {
        std::cout << "Destructor Derived::~Derived()" << std::endl;
    }
};

int main()
{
    Base b;
    Derived d;
    Base &rb = b;  // biding reference: alias per oggetto b
    Base *pb = &d; // nota: upcast
    std::cout << "=== 1 ===" << std::endl;
    b.f(1); // candidate: f(double), f(int) utilizzabile: f(int)
    rb.f('a');
    rb.g(1);
    std::cout << "=== 2 ===" << std::endl;
    d.f(1);
    d.f(1.0);
    d.g(3.3);
    std::cout << "=== 3 ===" << std::endl;
    pb->f(1.0);
    pb->f('a');
    pb->g(3.3);
    return 0;
}

/*
La mia previsione
Constructor Base::Base()
Constructor Base::Base()
Constructor Derived::Derived()
=== 1 ===
Base::f(int)
Base::g(int) giusto
Destructor Base::~Base()
Destructor Derived::~Derived()
=== 2 ===
Constructor Derived::Derived()
Constructor Base::Base()
Constructor Base::Base()
Base::f(int)
Base::f(double)
Derived::g(int)  giusto
Destructor Derived::~Derived()
Destructor Base::~Base()
Destructor Base::~Base()
=== 3 ===
Constructor Derived::Derived()
Constructor Base::Base()
Constructor Base::Base()
Base::f(double)
Derived::f(char)
Base::g(int)
Destructor Derived::~Derived()
Destructor Base::~Base()
Destructor Base::~Base()
*/

/*
Output giusto
Constructor Base::Base()
Constructor Base::Base()
Constructor Derived::Derived()
=== 1 ===
Base::f(int)
Base::f(int)
Base::g(int)
=== 2 ===
Derived::f(char)
Derived::f(char)
Derived::g(int)
=== 3 ===
Base::f(double)
Base::f(int)
Derived::g(int)
Destructor Derived::~Derived()
Destructor Base::~Base()
Destructor Base::~Base()
*/