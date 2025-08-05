//
// Created by jonat on 2023-12-09.
//

#ifndef COMMON_H
#define COMMON_H


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

bool containsDuplicate(vector<int>& nums);
bool isAnagram(string s, string t);
vector<int> twoSum(vector<int>& nums, int target);
vector<int> twoSum2(vector<int>& nums, int target);
int bin_search(vector<int>& nums, int target, int index);
vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<int> topKFrequent(vector<int>& nums, int k);
string encode(vector<string>& strs);

// Decodes a single string to a list of strings.
vector<string> decode(string s) ;
vector<int> productExceptSelf(vector<int>& nums) ;
#endif
