
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

Per ottimizzare i protocolli delle classi derivate 
```c++
    #include <iostream>

    // Classe astratta con un'interfaccia più chiara
    class AbstractProtocol {
    public:
        virtual ~AbstractProtocol() = default;
        virtual void HandleMessage(/*...*/) = 0;
    };

    // Classe di base condivisa
    class BasicProtocol : public AbstractProtocol {
    public:
        BasicProtocol() = default;
        ~BasicProtocol() override = default;

        // Alcuni metodi comuni
        void CommonOperation(/*...*/) {
            // Implementazione comune
        }

        // Override del metodo virtuale puro
        void HandleMessage() override {
            // Implementazione di base
            CommonOperation();
        }
    };

    // Primo protocollo
    class Protocol1 : public BasicProtocol {
    public:
        Protocol1() = default;
        ~Protocol1() override = default;

        void HandleMessage() override {
            // Implementazione specifica di Protocol1
            BasicProtocol::HandleMessage(); // Chiamata all'implementazione di base
        }
    };

    // Secondo protocollo
    class Protocol2 : public BasicProtocol {
    public:
        Protocol2() = default;
        ~Protocol2() override = default;

        void HandleMessage() override {
            // Implementazione specifica di Protocol2
            BasicProtocol::HandleMessage(); // Chiamata all'implementazione di base
        }
    };

    int main() {
        Protocol1 protocol1;
        Protocol2 protocol2;

        // Utilizzo generico attraverso l'interfaccia AbstractProtocol
        AbstractProtocol* protocols[] = {&protocol1, &protocol2};

        for (auto protocol : protocols) {
            protocol->HandleMessage();
        }

        return 0;
    }

```