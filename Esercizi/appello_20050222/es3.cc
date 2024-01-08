/*
    Individuare il problema che si potrebbe presentare nel codice seguente. Fornire un’implementazione alternativa in grado di porvi soluzione.
*/

/************ Inizio file Costante.hh ************/
class Costante {
public:
static double pi;
static double e;
// ...
};
/************ Inizio file Costante.cc ************/
#include "es3_Costante.hh"
Costante::pi = 3.1415;
Costante::e = 2.72;
// ...
/************ Inizio file Angolo.hh ************/
class Angolo {
public:
static double piatto;
static double retto;
static double giro;
// ...
};
/************ Inizio file Angolo.cc ************/
#include "es3_Angolo.hh"
#include "es3_Costante.hh"
Angolo::retto = Costante::pi / 2;
Angolo::piatto = Costante::pi;
Angolo::giro = Costante::pi * 2;
// ...