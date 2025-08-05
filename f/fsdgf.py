import math
from typing import List
import time

def containsDuplicate(nums: List[int]) -> bool:
    nums.sort()
    tmp = []

    for i in range(len(nums)):
        print()
        if i > 0:
            if nums[i] == tmp[i - 1]:
                print(tmp)
                return True

        tmp.append(nums[i])
    return False

def isAnagram( s: str, t: str) -> bool:
    if len(s) != len(t):
        return False

    s_count = [0] * 26
    t_count = [0] * 26
    for i in range(len(s)):
        s_count[ord(s[i]) - 97] += 1
        t_count[ord(t[i]) - 97] += 1
    if s_count == t_count:
        return True
    return False

def twoSum( nums: List[int], target: int) -> List[int]:
    orig_index = list(enumerate(nums))
    sorted_indexed_list = sorted(orig_index, key=lambda item: item[1])
    for i in range(1, len(sorted_indexed_list)):
        desired = target - sorted_indexed_list[i - 1][1]
        ind = binsearch(sorted_indexed_list,desired, i)
        if ind != -1:
            return [sorted_indexed_list[i - 1][0],ind]


def binsearch(nums, target, index=0):
    low = index
    high = len(nums)-1
    while low <= high:
        mid = (low+high)//2
        if nums[mid][1] == target:
            return nums[mid][0]
        elif nums[mid][1] > target:
            high = mid - 1
        else:
            low = mid+1
    return -1

def twoSum2( nums: List[int], target: int) -> List[int]:
    tmp = {}
    for i, number in enumerate(nums):
        desired = target - number
        if desired in tmp:
            return [i, tmp[desired]]
        tmp[number] = i

def groupAnagrams(strs: List[str]) -> List[List[str]]:
    ret = []
    ret.append([strs[0]])
    char_list = list(strs[0])
    char_list.sort()
    sorted_string = "".join(char_list)
    profiles = {sorted_string: 0}
    for idx,string in enumerate(strs[1:]):
        char_list = list(string)
        char_list.sort()
        sorted_string = "".join(char_list)
        if sorted_string in profiles:
            ret[profiles[sorted_string]].append(string)
        else:
            profiles[sorted_string] = len(ret)
            ret.append([string])
    return ret

def topKFrequent(nums: List[int], k: int) -> List[int]:
    counter = {}

    for num in nums:
        if num in counter:
            counter[num] +=1
        else:
            counter[num] = 1
    sorted_keys = sorted(counter, key=counter.get, reverse=True)
    return sorted_keys[:k]

def encode( strs: List[str]) -> str:
    tmp_string = ""
    for string in strs:
        len_string = ""
        if len(string) >= 100:
            len_string = str(len(string))
        elif len(string) >= 10:
            len_string = "0" +str(len(string))
        else:
            len_string = "0" + "0" +str(len(string))
        tmp_string += len_string
        tmp_string += string
    return tmp_string

def decode(s: str) -> List[str]:
    tmp_list = []
    i = 0
    while i < len(s):
        # print("loop: ", i)
        # print("1: ", s[i:i+3])
        # print("2: ",int(s[i:i+3]))
        # print("3: ",s[i+3:i+3 +int(s[i:i+3])])
        tmp_list.append(s[i+3:i+3 + int(s[i:i+3])])
        i =int(s[i:i+3]) + 3 + i
        # print(i)
    return tmp_list

def productExceptSelf(nums: List[int]) -> List[int]:
    ret = [1] * len(nums)

    counter = 1
    for i in range(len(nums)):
        ret[i] *= counter
        counter *= nums[i]

    counter = 1
    for i in range(len(nums)-1,-1,-1):
        ret[i] *= counter
        counter *= nums[i]

    return ret

def longestConsecutive( nums: List[int]) -> int:
    tmp = set(nums)
    count = 0
    for i in tmp:
        if i-1 not in tmp:
            current_streak = 1
            while i + current_streak in tmp:
                current_streak += 1
            count = max(count, current_streak)
    return count

st = time.time()
# print(containsDuplicate([1,2,3,4]))
# print(isAnagram("ggii","eekk"))
# print(twoSum2([3,2,4],6))
# print(twoSum2([2,11,7,15],9))
# print(twoSum2([3,3],6))
# print(groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
# print(topKFrequent([1,1,1,2,2,3], 2))
# x = encode(["neet","code","love","you"])
# print(x)
# print(decode(x))

# print(productExceptSelf(x))
# print(productExceptSelf([1,2,3,4]))
print(longestConsecutive([100,4,200,1,3,2]))
print(st-time.time())