#include<iostream>
using namespace std;

struct A{
    A(){cout<<"Constructor A::A()"<<endl;}
    virtual void m1() const {cout<<"A::m1() const"<<endl;}
    virtual void m2() const {cout<<"A::m2() const"<<endl;}
    virtual ~A() {cout<<"Destructor A::~A()"<<endl;}
};

struct B : public A{
    void m1() const {cout<<"B::m1()"<<endl;}
    void m2() {cout<<"B::m2()"<<endl;}
};

struct C : public B{
    C(){cout<<"Constructor C::C()"<<endl;}
    void m1() const {cout<<"C::m1() const"<<endl;}
    virtual ~C(){cout<<"Destructor C::~C()"<<endl;}
};

int main(){
    A* pa=new B();
    const B* pb=new C();
    pa->m1();
    pa->m2();
    pb->m1();
    delete pb;  // normalmente si andrebbe su' all'ereditarieta' di B con la distruzione ma dato che pb e' un tipo C e ha
                // distruttore virtuale si scende direttamente a C
    delete pa;
    return 0;
}

/*  ___________
    Risoluzione
    ___________

    Constructor A::A() : creazione del tipo B
    Constructor A::A() : creazione del tipo C
    Constructor C::C() : creazione del tipo C
    B::m1()
    A::m2() const
    C::m1() const
    Destructor C::~C() : si distrugge subito C perche' ha distruttore virtuale poi si sale rispetto all'ereditarieta'
    Destructor A::~A()
    Destructor A::~A()
*/
