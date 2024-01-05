/*
    Vecchia maniera, polimorfismo statico

class Scheda_Prepagata{
public:
    enum Tipo_Scheda{
        PAGA_DI_PIU,
        COSTO_RANDOM,
        PAGA_LA_MAMMA
    };
    Tipo_Scheda tipo_scheda() const;
    void addebita_chiamata(const Chiamata &call);
    // ...
private:
    void fai_la_cosa_giusta_1(const Chiamata &call);
    void fai_la_cosa_giusta_2(const Chiamata &call);
    void fai_la_cosa_giusta_3(const Chiamata &call);
    // ...
};

void Scheda_Prepagata::addebita_chiamata(const Chiamata &call){
    switch (tipo_scheda())
    {
    case PAGA_DI_PIU:
        fai_la_cosa_giusta_1(call);
        break;
    case COSTO_RANDOM:
        fai_la_cosa_giusta_2(call);
        break;
    case PAGA_LA_MAMMA:
        fai_la_cosa_giusta_3(call);
        break;
    }
}
*/
#include<string>
class Chiamata{};
/*
    Polimorfismo dinamico
*/

/* Scheda_Prepagata.hh */
class Scheda_Prepagata{
    public:
        virtual std::string tipo_scheda() const=0;
        virtual void addebita_chiamata(const Chiamata& call)=0;
        ~Scheda_Prepagata(){ }
};
///////////////////////////////////////////////////////////////////////////////

/* PAGA_DI_PIU.cc */
class Paga_di_piu : public Scheda_Prepagata{
    public:
        std::string tipo_scheda() const override{
            return "PAGA_DI_PIU";
        }
        void addebita_chiamata(const Chiamata& call) override{
            fai_la_cosa_giusta_1(call);
        }
    private:
        void fai_la_cosa_giusta_1(const Chiamata &call){}
};

/* COSTO_RANDOM.cc */
class Costo_Random : public Scheda_Prepagata{
    public:
        std::string tipo_scheda() const override{
            return "COSTO_RANDOM";
        }
        void addebita_chiamata(const Chiamata& call) override{
            fai_la_cosa_giusta_2(call);
        }
    private:
        void fai_la_cosa_giusta_2(const Chiamata &call){}
};

/* PAGA_LA_MAMMA.cc */
class Paga_la_mamma : public Scheda_Prepagata{
    public:
        std::string tipo_scheda() const override{
            return "PAGA_LA_MAMMA";
        }
        void addebita_chiamata(const Chiamata& call) override{
            fai_la_cosa_giusta_3(call);
        }
    private:
        void fai_la_cosa_giusta_3(const Chiamata &call){}
};