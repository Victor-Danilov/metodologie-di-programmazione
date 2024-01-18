/*
    Si forniscano il prototipo e l'implementazione della funzione generica count_if, che dati in ingresso
    una sequenza ed un predicato unario, restituisce il numero di elementi di quella sequenza per i quali
    quel predicato e' soddisfatto.
*/
#include<string>
#include<vector>
#include<iostream>
#include<iterator>

template<typename Iter, typename Pred>
int count_if(Iter first, Iter last, Pred pred){
    int count;
    for(; first!=last; ++first){
        if(pred) ++count;
    }
    return count;
}

bool ten(const std::vector<std::string>& s){
    return (s.size()>=10) ? true : false;
}

/*
    Utilizzando la funzione suddetta, scrivere un programma che legge dallo standard input una sequen-
    za di std::string e scrive sullo standard output il numero di stringhe lette aventi una lunghezza
    maggiore di 10.
*/

int main(){

    const std::vector<std::string> v{
        "1.dsadsad",
        "2.dsadasdasdasdsa",
        "3.dsadasddsa",
        "4.dsadsdsdsdsadsadasdsa"
    };

    int i=count_if(v.begin(),v.end(),ten(v));
    std::cout<<i;
    

    return 0;
}
