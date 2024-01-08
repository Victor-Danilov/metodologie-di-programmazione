/*
    Indicare l’output prodotto dal seguente programma.
*/

/*
    Aggiungo stampe sui distruttori per capire il loro percorso di vita
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
    virtual ~ZooAnimal() {std::cout<<"Destructor ZooAnimal"<<std::endl;}
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
    virtual ~Bear() {std::cout<<"Destructor Bear"<<std::endl;}
};

class Raccoon : virtual public ZooAnimal
{
    public:
    Raccoon()
    {
        std::cout << "Constructor Raccoon" << std::endl;
    }
    virtual ~Raccoon() {std::cout<<"Destructor Raccoon"<<std::endl;}
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
    virtual ~Endangered() {std::cout<<"Destructor Endangered"<<std::endl;}
};

class Panda : public Endangered, public Raccoon, public Bear  // il primo virtual ha la precedenza
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
    virtual ~Panda() {std::cout<<"Destructor Panda"<<std::endl;}
};

int main()
{
    Panda ying_yang;
    ying_yang.print();                              // Panda::print
    Bear b = ying_yang;
    b.print();                                      // Bear::print
    ZooAnimal *pz = &ying_yang;
    pz->print();                                    // Panda::print
    Endangered &re = ying_yang;                     
    re.print();                                     // Endangered::print
    return 0;
}

/*
    NOTE:
    - Una volta creato l'oggetto con il costruttore questo non viene ricreato
    - L'ordine di distruzione avviene in base alla Ereditarieta'
        Esempio:    Panda quando viene creato eredita da Endangered, Raccoon e Bear,
                    è importante notare che il costruttore virtuale più derivato (ZooAnimal) viene chiamato prima degli altri
*/

/*
    OUTPUT sbagliato first try
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
    ----------------------------------------second attempt
    Constructor ZooAnimal
    Constructor Endangered
    Constructor Raccoon
        Constructor ZooAnimal? non lo ricostruisce perche' gia' costruito nella riga 102
    Constructor Bear
    Constructor Panda
    Panda::print
    Constructor ZooAnimal
    Panda::print
    Constructor Endangered
    Endangered::print
    ----------------------------------------third attempt
    Constructor ZooAnimal
    Constructor Endangered
    Constructor Raccoon
    Constructor Bear
    Constructor Panda
    Panda::print
    Bear::print
    Panda::print
        Constructor Endangered?
    Endangered::print
    ----------------------------------------first attempt with destructor cout
    Constructor ZooAnimal   : ordine di distruzione; ZooAnimal
    Constructor Endangered  : ordine di distruzione; Endangered
    Constructor Raccoon     : ordine di distruzione; Raccoon, ZooAnimal
    Constructor Bear        : ordine di distruzione; Bear, ZooAnimal
    Constructor Panda       : la prima distruzione comincia con Panda che e' un Bear che e' un ZooAnimal, quindi ordine di distruzione Bear, ZooAnimal, Panda
    Panda::print
    Bear::print
    Panda::print
    Endangered::print
    Destructor Bear
    Destructor ZooAnimal
    Destructor Panda
    Destructor Bear
        Destructor ZooAnimal? questo non entra in funzione a causa della distruzione precedente di Bear ZooAnimal Panda riga 143
    Destructor Raccoon
        Destructor ZooAnimal?
    Destructor Endangered
    Destructor ZooAnimal
    ----------------------------------------second attempt with destructor cout
    Constructor ZooAnimal
    Constructor Endangered
    Constructor Raccoon
    Constructor Bear
    Constructor Panda
    Panda::print
    Bear::print
    Panda::print
    Endangered::print
    Destructor Bear
    Destructor ZooAnimal
    Destructor Panda
    Destructor Bear
    Destructor Raccoon
    Destructor Endangered
    Destructor ZooAnimal
*/