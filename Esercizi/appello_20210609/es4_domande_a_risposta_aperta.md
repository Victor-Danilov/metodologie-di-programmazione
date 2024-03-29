
### Domande a risposta aperta

> [!NOTE]
> Riferimenti ai paragrafi di Stroustrup quarta edizione

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
3. Se la postcondizione e' violata significa che anche la precondizione e' violata, se l’utente non soddisfa una precondizione l’implementatore non ha alcun obbligo.
4. Per il contenitore std::vector abbiamo il metodo `[]` per accedere a un elemento qualsiasi della lista ed e' possibile fare sia la push back cioe' aggiungere elementi solo alla fine della sequenza. Mentre con std::list per accedere ad un elemento della lista lo dobbiamo "raggiungere" scorrendo tutta la lista, il che e' poco efficiente, ma d'altro canto si possono aggiungere elementi sia all'inizio della lista (push_front) che alla fine (push_back).
5. Il tipo di valore std::map<K, M> e' std::pair<K, M> ma con questo abbiamo un problema, che possiamo modificare il valore mappato e anche la chiave. Il problema con la modifica della chiave e' che rompo l'invariante della classe. Quindi dentro alla mappa ci sara' scritto qualcosa del tipo;
   ```c++
   using value_type = std::pair<const K, M>;
   ```
   Per modificare la chiave devo togliere la coppia dalla mappa, la elimino e la reinserisco con la chiave modificata.
6. Con gli iteratori bidirezionali possiamo usare solo gli operatori di confronto `==` e `!=`, mentre gli iteratori random access possono usare gli operatori di:
   1.  **addizione `(+)` e sottrazione `(-)`**: quindi si possono spostare avanti o indietro nella sequenza di un numero specificato di posizioni.
   ```c++
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator iter = myVector.begin();

    // Gli iteratori random access supportano l'operatore di addizione
    std::vector<int>::iterator nuovoIter = iter + 2;
   ```
   2. **differenza `(-)`**: consentono di calcolare la differenza tra due iteratori, restituendo il numero di posizioni tra di essi.
   ```c++
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator iter1 = myVector.begin();
    std::vector<int>::iterator iter2 = myVector.begin() + 3;

    // Gli iteratori random access supportano l'operatore di differenza
    int differenza = iter2 - iter1;
   ```
   3. **confronto (`<`,`<=`,`>`,`>=`)**: gli iteratori random access possono essere confrontati tra loro utilizzando gli operatori di confronto per determinare la relazione tra le posizioni nella sequenza.
   ```c++
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator iter1 = myVector.begin();
    std::vector<int>::iterator iter2 = myVector.begin() + 3;

    // Gli iteratori random access supportano gli operatori di confronto
    if (iter1 < iter2) {
        // ...
    }
   ```
7. Nel codice utente se si usa una classe concreta,si viola il principio DIP quando quella ha delle dipendenze verso il basso, se viene previsto che questa dovra' avere flessibilita' in futuro.  La cosa giusta sarebbe di creare un'interfaccia astratta in modo che il codice utente dipenda da questa quindi dipendenza verso l'alto.
8. L'istanziazione genera una versione specifica della funzione o classe template per il tipo di dati specificato, la specializzazione di un template offre la possibilita' di fornire un'implementazione specifica per un tipo di dati particolare. La specializzazione consente di definire un comportamento personalizzato per il template quando viene utilizzato con un certo tipo.
```c++
    template<typename T>
    const T& min(const T& a, const T& b){
        return (a<b) ? a : b;
    }

    template<>
    const const char*& min(const char* const& a, const char* const& b){
        return; // diversa
    }

    void pippo(){
        auto a = min(4, 7);
        auto b = min("aaa", "zzz");
    }
```