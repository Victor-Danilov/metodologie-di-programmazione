/*
    Individuare il problema che si potrebbe presentare nel codice seguente. Fornire un’implementazione alternativa in grado di porvi soluzione.
*/

/************ Inizio file Costante.hh ************/
class Costante {
public:
    static double pi;
    static double e;

};

/************ Inizio file Costante.cc ************/
#include "Costante.hh"
Costante::pi = 3.1415;
Costante::e = 2.72;

/************ Inizio file Angolo.hh ************/
class Angolo {
public:
    static double piatto;
    static double retto;
    static double giro;
};

/************ Inizio file Angolo.cc ************/
#include "Angolo.hh"
#include "Costante.hh"
Angolo::retto = Costante::pi / 2;
Angolo::piatto = Costante::pi;
Angolo::giro = Costante::pi * 2;

// --------------------------------------------------- RISOLUZIONE

/*
    Il problema che potrebbe sorgere e' quando vogliamo aggiungere un altro tipo di angolo,
    Aggiungendo un'altro angolo dobbiamo modificare Angolo.hh e Angolo.cc, invece noi vogliamo
    un'estensione della classe Angolo e non una sua modifica.
    Per fare cio' bisogna rendere l'interfaccia Angolo virtuale.
*/

/************ Inizio file Costante.hh ************/
class Costante {
public:
    static double pi;
    static double e;

};

/************ Inizio file Costante.cc ************/
#include "Costante.hh"
Costante::pi = 3.1415;
Costante::e = 2.72;


/************ Inizio file Angolo.hh ************/

class Angolo{
public:
    virtual static double angolo()=0;
};

/************ Inizio file Retto.hh ************/
#include "Angolo.hh"
#include "Costante.hh"
class Retto: public Angolo{
    static double angolo() override {Costante::pi/2;}
};

/************ Inizio file Piatto.hh ************/
#include "Angolo.hh"
#include "Costante.hh"
class Piatto: public Angolo{
    static double angolo() override {Costante::pi;}
};

/************ Inizio file Giro.hh ************/
#include "Angolo.hh"
#include "Costante.hh"
class Giro: public Angolo{
    static double angolo() override {Costante::pi*2;}
};

/************ Inizio file Angolo.cc ************/
#include "Angolo.hh"
#include "Costante.hh"
#include "Retto.hh"
#include "Giro.hh"
#include "Piatto.hh"

Retto::angolo;
Giro::angolo;
Piatto::angolo;




