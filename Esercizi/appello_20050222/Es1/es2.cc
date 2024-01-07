/*
    Indicare l’output prodotto dal seguente programma.
*/


#include <iostream>
class ZooAnimal
{
    public:
    ZooAnimal()
    {
        std::cout << "Constructor ZooAnimal" << std::endl;
    }
    virtual void print()
    {
        std::cout << "ZooAnimal::print" << std::endl;
    }
    virtual ~ZooAnimal() {}
};

class Bear : virtual public ZooAnimal
{
    public:
    Bear()
    {
        std::cout << "Constructor Bear" << std::endl;
    }
    void print()
    {
        std::cout << "Bear::print" << std::endl;
    }
    virtual ~Bear() {}
};

class Raccoon : virtual public ZooAnimal
{
    public:
    Raccoon()
    {
        std::cout << "Constructor Raccoon" << std::endl;
    }
    virtual ~Raccoon() {}
};

class Endangered
{
    public:
    Endangered()
    {
        std::cout << "Constructor Endangered" << std::endl;
    }
    void print()
    {
        std::cout << "Endangered::print" << std::endl;
    }
    virtual ~Endangered() {}
};

class Panda : public Endangered, public Raccoon, public Bear // il primo virtual ha la precedenza
{
    public:
    Panda()
    {
        std::cout << "Constructor Panda" << std::endl;
    }
    void print()
    {
        std::cout << "Panda::print" << std::endl;
    }
    virtual ~Panda() {}
};

int main()
{
    Panda ying_yang;
    ying_yang.print();
    // Bear b = ying_yang;
    // b.print();
    ZooAnimal *pz = &ying_yang;
    pz->print();
    Endangered &re = ying_yang;
    re.print();
    return 0;
}

/*
    OUTPUT sbaglaito
    Constructor Endangered
    Constructor ZooAnimal
    Constructor Bear
    Constructor ZooAnimal
    Constructor Raccoon
    Panda::print
    Constructor ZooAnimal
    Constructor Bear
    Bear::print
    Constructor ZooAnimal
    Panda::print
    Constructor Endangered
    Panda::print

*/