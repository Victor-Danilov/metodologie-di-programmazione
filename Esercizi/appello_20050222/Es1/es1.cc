void f(const char *s);          // funzione #1

template <typename T>
void f(T t);                    // funzione #2

template <typename T>
void f(T t1, T t2);             // funzione #3

template <typename T, typename U>
void f(T t, U u);               // funzione #4

template <typename T>
void f(T *pt, T t);             // funzione #5

template <typename T, typename U>
void f(T *pt, U u);             // funzione #6

template <typename T>
void g(T t, double d);          // funzione #7

template <typename T>
void g(T t1, T t2);             // funzione #8

struct S { 
    private:
        void foo(int);
};
struct T : public S { void foo(char); };
T t; // tipo statico e dinamico coincidono (T)
t.foo(5);
// la ricerca inizia nello scope di T; la funzione S::foo
// non va in overloading, perché viene nascosta (hiding);

int test()
{
    f('a');   // chiamata #1

    f("aaa"); // chiamata #2

    int i;
    f(i);     // chiamata #3
    f(i, i);  // chiamata #4
    f(i, &i); // chiamata #5
    f(&i, i); // chiamata #6

    double d;
    f(i, d);  // chiamata #7
    f(&d, i); // chiamata #8

    long l;
    g(l, i); // chiamata #9
    g(l, l); // chiamata #10
    g(l, d); // chiamata #11
    g(d, d); // chiamata #12
}

/* 
    #1:  candidate: 1,2 utilizzabile: 1,2 migliore: 1
    #2:  candidate: 1,2 utilizzabile: 1,2 migliore:  
    #3:  candidate:  utilizzabile:  migliore:
    #4:  candidate:  utilizzabile:  migliore:
    #5:  candidate:  utilizzabile:  migliore:
    #6:  candidate:  utilizzabile:  migliore:
    #7:  candidate:  utilizzabile:  migliore:
    #8:  candidate:  utilizzabile:  migliore:
    #9:  candidate:  utilizzabile:  migliore:
    #10: candidate:  utilizzabile:  migliore:
    #11: candidate:  utilizzabile:  migliore:
    #12: candidate:  utilizzabile:  migliore:
*/