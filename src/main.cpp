#include <advent_of_code/common.h>
#include <advent_of_code/day1.h>
#include <advent_of_code/day2.h>
#include <advent_of_code/day3.h>
int main() {
//    print(day3_part2());
    std::vector<int> nums = {1,1,1,2,2,3};
//    print(containsDuplicate(nums));
//    print(isAnagram("ggii", "eekk"));
//    std::vector<int> nre = twoSum(nums, 9);
//    for (const auto& p : nre ){
//        std::cout << p << std::endl;
//    }
//    std::vector<string> strings = {"eat","tea","tan","ate","nat","bat"};
//
//    vector<vector<string>> nre = groupAnagrams(strings);
//    for (const auto& p : nre ){
//        for (const auto& pp : p )
//            std::cout << pp << ", ";
//        std::cout << std::endl;
//    }
//    std::vector<int> nre = topKFrequent(nums, 2);
//    for (const auto& p : nre ){
//        std::cout << p << std::endl;
//    }
//    std::vector<string> strings = {"Hello","World"};
//    string x = encode(strings);
//    std::vector<string> nre = decode(x);
//    for (const auto& p : nre ){
//        std::cout << p << std::endl;
//    }

    std::vector<int> nums2 = {1,2,3,4};

    std::vector<int> nre = productExceptSelf(nums2);
    for (const auto& p : nre ){
        std::cout << p << std::endl;
    }

    return 0;
}

bool containsDuplicate(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> tmp;
    for (int i = 0; i < nums.size(); i++){
        if (i >0){
            if (nums[i] == tmp[i-1])
                return true;
        }
        tmp.push_back(nums[i]);
    }
    return false;

}

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    int s_count[26] = {0};
    int t_count[26] = {0};

    for (int i = 0; i < s.length(); i++){
        s_count[int(s[i]) - 97] += 1;
        t_count[int(t[i]) - 97] += 1;
    }
    if (std::equal(s_count, std::end(s_count), t_count))
        return true;
    return false;

}

int bin_search(vector<std::pair<int, int>>& nums, int target, int index){
    int low = index;
    int high = nums.size() - 1;
    int mid;
    while (low <= high){
        mid =(low + high)/2;
        if (nums[mid].first == target){
            return nums[mid].second;
        }
        else if (nums[mid].first > target){
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> indexed;
    for (int i = 0; i < nums.size(); i++){
        indexed.push_back({nums[i], i});
    }
    std::sort(indexed.begin(), indexed.end());
//    for (const auto& p : indexed ){
//        std::cout << p.first << "    " << p.second << std::endl;
//    }
    for (int i = 1; i < nums.size(); i++){
        int desired = target - indexed[i-1].first;
        int ind = bin_search(indexed, desired, i);
        if (ind != -1){
            std::vector<int> ret = {indexed[i-1].second, ind};
            return ret;
        }
    }
}
vector<int> twoSum2(vector<int>& nums, int target) {
    std::unordered_map<int, int> tmp;

    for (int i = 0; i < nums.size(); i++){
        int desired = target - nums[i];
        if (tmp.find(desired) != tmp.end() ) {
            std::vector<int> ret = {tmp[desired], i};
            return ret;
        }
        tmp[nums[i]] = i;
    }
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret = {{strs[0]}};
//    ret.push_back(strs[0])
    std::string tmp = strs[0];
    std::sort(tmp.begin(), tmp.end());
//    print(strs[0]);
    std::unordered_map<string, int> profiles = {{tmp,0}};
    vector<string> sliced_str(strs.begin()+1, strs.end());
    for (auto& str : sliced_str ){
        std::string tmp2 = str;
        std::sort(tmp2.begin(), tmp2.end());
        if (profiles.find(tmp2) != profiles.end()){
            ret[profiles[tmp2]].push_back(str);

        }
        else{
            profiles[tmp2] = int(ret.size());
            ret.push_back({str});
        }

    }

    return ret;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int,int> counter;
    for(auto& i : nums){
        if (counter.find(i) != counter.end())
            counter[i] +=1;
        else{
            counter[i] = 1;
        }
    }
    vector<std::pair<int,int>> sorted_counter(counter.begin(), counter.end());
    std::sort(sorted_counter.begin(), sorted_counter.end(), [](const std::pair<int,int> &a, const std::pair<int,int> &b){
        return a.second > b.second;
    });
    vector<int> ret;
    for (const auto& p : sorted_counter ){
//        std::cout << p.second << std::endl;
        ret.push_back(p.first);
    }
    vector<int> ret2(ret.begin(),ret.begin()+k);
    return ret2;

}

string encode(vector<string>& strs) {
    string tmp_string;
    for (auto& str: strs){
        string len_str;
        if (str.length() >= 100){
             len_str = std::to_string((str.length()));
        }
        else if (str.length() >= 10){
             len_str = "0" + std::to_string((str.length()));
        }
        else {
             len_str = "00" + std::to_string((str.length()));
        }
        tmp_string += len_str + str;
    }
    return tmp_string;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) {
    vector<string> ret;
    int i = 0;
    while(i < s.length()){
        int str_len = std::stoi(s.substr(i,3));
        string slice = s.substr(i+3, str_len);

        ret.push_back(slice);
        i += 3 + str_len;
    }
    return ret;

}
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret(nums.size(), 1);
    int counter = 1;
    for (int i = 0; i < nums.size(); i++){
        ret[i] *= counter;
        counter *= nums[i];
    }
    counter =1;
    for (int i = nums.size()-1; i > -1; i--){
        ret[i] *= counter;
        counter *= nums[i];
    }
    return ret;
}
