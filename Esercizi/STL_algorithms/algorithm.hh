#include<vector>
#include<iterator>
#include<iostream>


template<typename InputIter1, typename InputIter2, typename OutputIter, typename BiOperation>
void transform(InputIter1 first1, InputIter1 last1, InputIter2 first2, OutputIter out_iter, BiOperation bi_operation){
    for(; first1!=last1; ++first1, ++first2, ++out_iter)
        *out_iter = bi_operation(*first1, *first2);
}

template<typename Iter, typename Pred>
typename std::iterator_traits<Iter>::difference_type
count_if(Iter first, Iter last, Pred& pred){
    typename std::iterator_traits<Iter>::difference_type count=0;
    for(; first!=last; ++first){
        if(pred(*first)){
            ++count;
        }
    }
    return count;
}

template<typename Iter, typename Pred>
typename std::iterator_traits<Iter>::difference_type
print_count_if(Iter first, Iter last, Pred& pred){
    typename std::iterator_traits<Iter>::difference_type count=0;
    for(; first!=last; ++first){
        if(pred(*first)){
            std::cout<<*first<<std::endl;
        }
    }
    return count;
}