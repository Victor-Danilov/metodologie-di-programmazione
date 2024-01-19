
### Gestione delle risorse

La classe seguente contiene errori inerenti la corretta gestione delle risorse. Individuare almeno due
problemi logicamente distinti, indicando la sequenza di operazioni che porta alla loro occorrenza.
Fornire quindi una soluzione alternativa e discutere brevemente i motivi per i quali tale soluzione
si puo' ritenere corretta.

```c++
    #include <string>
    class A{
        int *pi;
        std::string str;
        double *pd;
    public:
        A(const std::string &s) : pi(new int), str(s), pd(new double) {}
        ~A(){
            delete pi;
            delete pd;
        }
    };
```
Il problema di questa classe e' che inizializza i metodi in modo dinamico dove c'e' la possibilita' di memory leak.
___________________________

#### Risoluzione

Per risolvere il problema di memory leak usiamo exception safe con smart pointers.

```c++
    #include <string>
    class A{
        std::unique_ptr<int> pi;
        std::string str;
        std::unique_ptr<double>pd;
    public:
        A(const std::string &s) 
        try : pi(std::make_unique<int>()), str(s), pd(std::make_unique<double>()) {}
        catch(...){
            /*...*/
            throw;
        }
        ~A() noexcept{}
    };
```