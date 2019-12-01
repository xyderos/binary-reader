#include "bin.h"

template<size_t N, typename T>std::vector<std::array<char, N>> bin<N, T>::getFile(const std::string &fileName) {

    std::ifstream in(fileName, std::ios::in|std::ios::binary);

    std::vector<std::array<char,N>> result;

    assert(in);

    std::array<char,N> arr{};

    char ch;

    size_t counter = 0;

    while(in.get(ch)){

        if(counter == N){

            result.emplace_back(arr);

            counter = 0;
        }
        arr.at(counter++) = ch;
    }

    in.close();

    return result;
}

template<size_t N, typename T> void bin<N, T>::extractRecords(std::vector<T> *vector, const std::vector<std::array<char, N>> &data) {

    for(auto e: data) vector->emplace_back(T(e));
}

template<size_t N, typename T> void bin<N, T>::writeToTXT(const std::vector<T> &data, const std::string &fileName){

    std::string newName;

    std::replace_copy(std::begin(fileName),std::end(fileName),newName,BIN,BIN);

    std::ofstream out(newName);

    for(const auto &e : data) T::write(e,out);

    out.close();
}