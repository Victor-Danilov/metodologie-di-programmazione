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
    #2:  candidate: 1,2 utilizzabile: 1,2 migliore: 1
    #3:  candidate: 2 utilizzabile: 2  migliore: 2
    #4:  candidate: 3 utilizzabile: 3 migliore: 3
    #5:  candidate: 4 utilizzabile: 4 migliore: 4
    #6:  candidate: 5,6 utilizzabile: 5,6 migliore: 5
    #7:  candidate: 4 utilizzabile: 4 migliore: 4
    #8:  candidate: 4,6 utilizzabile: 4,6 migliore: 6
    #9:  candidate: 7 utilizzabile: 7 migliore: 7
    #10: candidate: 7,8 utilizzabile: 7,8 migliore: 8
    #11: candidate: 7,8 utilizzabile: 7 migliore: 7
    #12: candidate: 7,8 utilizzabile: 7,8 migliore: 7
*/