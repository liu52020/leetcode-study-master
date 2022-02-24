> 前K个大数问题，老生常谈，不得不谈

# 347.前 K 个高频元素

[力扣题目链接](https://leetcode-cn.com/problems/top-k-frequent-elements/)

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:
* 输入: nums = [1,1,1,2,2,3], k = 2
* 输出: [1,2]

示例 2:
* 输入: nums = [1], k = 1
* 输出: [1]

提示：
* 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
* 你的算法的时间复杂度必须优于 $O(n \log n)$ , n 是数组的大小。
* 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
* 你可以按任意顺序返回答案。

# 思路

这道题目主要涉及到如下三块内容：
1. 要统计元素出现频率
2. 对频率排序
3. 找出前K个高频元素

首先统计元素出现的频率，这一类的问题可以使用map来进行统计。
然后我们可以使用pair<int,int>结构对map的value进行排序，
再获取前k个高频元素

代码如下：
```CPP
class Solution {
public:

    // 这个要用静态的  
    static bool cmp(const pair<int,int> &l1,const pair<int,int> &l2){
        return l1.second > l2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto num:nums){
            map[num]++;
        }

        // 再将map的key和value放入pair中
        unordered_map<int,int>::iterator it;
        vector<pair<int,int>>  arr;
        for(it=map.begin();it!=map.end();it++){
            arr.push_back(make_pair(it->first,it->second));
        }

        sort(arr.begin(),arr.end(),cmp);

        vector<int> result;
        for(int i=0;i<k;++i){
            result.push_back(arr[i].first);
        }

        return result;


    


    }
};
```
