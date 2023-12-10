//
// Created by jonat on 2023-12-09.
//

#ifndef COMMON_H
#define COMMON_H


#include <iostream>
#include <string>

using namespace std;

template <typename T, typename... Tail>
void print_impl(const T& t, const Tail&... tail) {
    using namespace std::literals;
    std::cout << t;
    (..., (std::cout << " "sv << tail));
}

template <typename... Tail>
void print(const Tail&... tail) {
    if constexpr (sizeof...(tail) != 0) {
        print_impl(tail...);
    }
    std::cout << std::endl;
}

string trim(const string&);


#endif
