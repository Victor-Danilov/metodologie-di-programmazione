#include<vector>
#include<iterator>
#include<iostream>


template<typename InputIter1, typename InputIter2, typename OutputIter, typename BiOperation>
void transform(InputIter1 first1, InputIter1 last1, InputIter2 first2, OutputIter out_iter, BiOperation bi_operation){
    for(; first1!=last1; ++first1, ++first2, ++out_iter)
        *out_iter = bi_operation(*first1, *first2);
}

int main(int argc, char const *argv[])
{
    std::vector<int> seq1{1, 2, 3, 6, 7, 8};
    std::vector<double> seq2{2.3, 4.2, 4.5, 2.7};

    std::vector<double> out(seq1.size());

    if(seq1.size()+seq2.size()<0){
        std::cerr<<"Sequenze differenti"<<std::endl;
    }

    auto sum = [](int a, double b){return static_cast<double>(a)+b;};

    transform(seq1.begin(), seq1.end(), seq2.begin(), out.begin(), sum);

    return 0;
}


template<typename Iter, typename Pred>
typename std::iterator_traits<Iter>::difference_type
count_if(Iter first, Iter last, Pred& pred){
    typename std::iterator_traits<Iter>::difference_type count=0;
    for(; first!=last; ++first;){
        if(pred(*first)){
            ++count;
        }
    }
    return count;
}