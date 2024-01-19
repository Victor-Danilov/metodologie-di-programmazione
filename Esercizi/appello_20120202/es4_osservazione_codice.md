
### Osservazione codice (Polimorfismo)

Una applicazione di rete prevede la gestione di sessioni di comunicazione di due tipologie distinte,
ognuna caratterizzata da uno specifico protocollo di comunicazione. Siccome i due protocolli hanno
alcune somiglianze (in termini di dati memorizzati e di operazioni di basso livello da eseguire),
il programmatore ha usato il seguente progetto per incapsulare le parti comuni in una classe

BasicProtocol:
```c++
    class BasicProtocol{
    private:
        /*...*/
    public:
        BasicProtocol();
        virtual ~BasicProtocol();
        bool BasicMsgA(/*...*/);
        bool BasicMsgB(/*...*/);
        bool BasicMsgC(/*...*/);
    };

    class Protocol1 : public BasicProtocol{
    public:
        Protocol1();
        ~Protocol1();
        bool DoMsg1(/*...*/);
        bool DoMsg2(/*...*/);
        bool DoMsg3(/*...*/);
    };

    class Protocol2 : public BasicProtocol{
    public:
        Protocol2();
        ~Protocol2();
        bool DoMsg1(/*...*/);
        bool DoMsg2(/*...*/);
        bool DoMsg3(/*...*/);
        bool DoMsg4(/*...*/);
        bool DoMsg5(/*...*/);
    };
```
Le funzioni membro delle classi derivate invocano le funzioni della classe base quando necessario,
ma gestiscono la trasmissione indipendentemente. In particolare, gli utenti della gerarchia di classi
tipicamente decidono di utilizzare uno dei due protocolli specifici. Discutere brevemente se il
progetto delle classi suddette e' appropriato rispetto all'uso che ne viene fatto. Elencare le eventuali
modifiche da apportare, indicandone i motivi.
_______________________________________________________

#### Risposta

Per ottimizzare i protocolli delle classi derivate dovremmo rendere la classe base BasicProtocol virtuale pura.
Inoltre sarebbe opportuno dichiarare virtuali anche i distruttori delle classi derivate.
```c++
    class BasicProtocol{
    private:
        /*...*/
    public:
        BasicProtocol();
        virtual ~BasicProtocol();
        virtual bool BasicMsgA(/*...*/) = 0;
        virtual bool BasicMsgB(/*...*/) = 0;
        virtual bool BasicMsgC(/*...*/) = 0;
        virtual bool BasicMsgD(/*...*/) = 0;
        virtual bool BasicMsgE(/*...*/) = 0;
    };
   class Protocol1 : public BasicProtocol{
    public:
        Protocol1();
        virtual ~Protocol1();
        bool BasicMsgA(/*...*/) override;
        bool BasicMsgB(/*...*/) override;
        bool BasicMsgC(/*...*/) override;
    };

    class Protocol2 : public BasicProtocol{
    public:
        Protocol2();
        virtual ~Protocol2();
        bool BasicMsgA(/*...*/) override;
        bool BasicMsgB(/*...*/) override;
        bool BasicMsgC(/*...*/) override;
        bool BasicMsgD(/*...*/) override;
        bool BasicMsgE(/*...*/) override;
    };
```