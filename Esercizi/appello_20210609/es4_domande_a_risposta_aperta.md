
### Domande a risposta aperta

1. Fornire un esempio di violazione della ODR (One Definition Rule) che genera un errore diagnosticabile in fase di compilazione in senso stretto (cioe' prima della fase di collegamento).
2. Fornire un esempio di chiamata di funzione nella quale si applica una conversione implicita definita dall'utente (senza usare tipi definiti nella libreria standard).
3. Durante una sessione di debugging, per una specifica invocazione di un metodo di una classe si osserva che la postcondizione e' violata, mentre la proprieta' invariante e' sempre soddisfatta; il programmatore ipotizza che l'errore sia nell'implementazione del metodo. Sotto quali condizioni tale ipotesi e' corretta? (<font color="red">Studiare i contratti</font>)
4. I template di classe **std::vector** e **std::list** hanno interfacce simili, ma non identiche. Indicare almeno un metodo di **std::vector** che non e' supportato da **std::list** e, viceversa. (<font color="red">Studiare i contenitori</font>, in paritcolare <font color="red">std::vector ⁋4.4.1, std::list ⁋4.4.2 e altri</font>)
5. Dati i tipi di dato K e M, come e' definito il tipo di dato **std::map<K, M>::value_type**, cioe' il tipo di dato degli elementi di una mappa della libreria standard? (<font color="red">Studiare std::map ⁋4.4.3</font>)
6. Elencare gli operatori che si possono applicare agli iteratori random access, ma non si possono applicare agli iteratori bidirezionali.
7. Fornire un semplice esempio di violazione del principio DIP (Dependency Inversion Principle), spiegando brevemente in cosa consiste la violazione.
8. Spiegare brevemente la differenza esistente tra la istanziazione e la specializzazione di un template di funzone.
   
#### Risposte

1. ```c++
    int a;
    int a;
    // Oppure
    void foo();
    void foo();
2. ```c++
    struct S{
        S(double);// conversione implicita definita dall'utente
    };
    
    void foo(S s);
    void foo(const std::string& s); // esempio di conversione implicita definita da STL

    int main(){
        //...
        foo(4.2); // conversione implicita definita dall'utente
        foo("pippo"); // esempio di conversione implicita definita da STL
        //...
    }
3. Per std::list non abbiamo il metodo `[]` per accedere a un elemento qualsiasi della lista ed e' possibile fare sia la push back che la push front, mentre nei std::vector abbiamo il metodo `[]` per accedere a un elemento qualsiasi e per aggiungere elemento possiamo fare solo al push back.
4. 

> [!NOTE]
> Riferimenti ai paragrafi di Stroustrup quarta edizione