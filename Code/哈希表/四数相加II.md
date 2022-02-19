> 需要哈希的地方都能找到map的身影

# 第454题.四数相加II

[力扣题目链接](https://leetcode-cn.com/problems/4sum-ii/)

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

**例如:**

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:
2
**解释:**
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


# 思路

本题咋眼一看好像和[0015.三数之和](https://programmercarl.com/0015.三数之和.html)，[0018.四数之和](https://programmercarl.com/0018.四数之和.html)差不多，其实差很多。

**本题是使用哈希法的经典题目，而[0015.三数之和](https://programmercarl.com/0015.三数之和.html)，[0018.四数之和](https://programmercarl.com/0018.四数之和.html)并不合适使用哈希法**，因为三数之和和四数之和这两道题目使用哈希法在不超时的情况下做到对结果去重是很困难的，很有多细节需要处理。

**而这道题目是四个独立的数组，只要找到A[i] + B[j] + C[k] + D[l] = 0就可以，不用考虑有重复的四个元素相加等于0的情况，所以相对于题目18. 四数之和，题目15.三数之和，还是简单了不少！**

如果本题想难度升级：就是给出一个数组（而不是四个数组），在这里找出四个元素相加等于0，答案中不可以包含重复的四元组，大家可以思考一下，后续的文章我也会讲到的。

本题解题步骤：

1. 首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
2. 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
3. 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
4. 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
5. 最后返回统计值 count 就可以了



代码如下：
```CPP
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //四数相加
        // nums1+nums2 = -(nums3+nums4)
        // 1.定义一个哈希表 key记录nums1+nums2的值  value记录次数 
        // 因为可以有重复 
        unordered_map<int,int> map;
        for(int a:nums1){
            for(int b:nums2){
                map[a+b]++;
            }
        }

        // map.count(x)   查找map中是否有x 有返回1 没有返回0
        // map.find(x)    查找map中x的位置 有x返回索引 没有返回end()
        int result = 0;
        // 遍历nums3和nums4 看-(nums3+nums4)在map里存不存在
        for(int c:nums3){
            for(int d:nums4){
                if(map.find(-(c+d))!=map.end()){
                    result+=map[-(c+d)];
                }
            }
        }

        return result;


    }
};
```
