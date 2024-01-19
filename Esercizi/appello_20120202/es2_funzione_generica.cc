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
typename std::iterator_traits<Iter>::difference_type
    count_if(Iter first, Iter last, Pred pred)
{
    typename std::iterator_traits<Iter>::difference_type count=0;
    for(; first!=last; ++first){
        if(pred(*first)){
            ++count;
        }
    }
    return count;
}

/*
    Utilizzando la funzione suddetta, scrivere un programma che legge dallo standard input una sequen-
    za di std::string e scrive sullo standard output il numero di stringhe lette aventi una lunghezza
    maggiore di 10.
*/

int main(){
    std::vector<std::string> v;
    std::string input;

    std::cout << "Inserisci le stringhe (termina con una riga vuota):\n";
    while(std::getline(std::cin, input) && !input.empty()){
        v.push_back(input);
    }

    auto ten = [](const std::string& str){ // funzione lambda che restituisce un valore booleano se la lunghezza della stringa e' >10
        return str.length() > 10;
    };

    int i=count_if(v.begin(),v.end(),ten);
    std::cout<<i;
    

    return 0;
}
