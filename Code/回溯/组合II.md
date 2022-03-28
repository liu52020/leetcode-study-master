> 别看本篇选的是组合总和III，而不是组合总和，本题和上一篇[回溯算法：求组合问题！](https://mp.weixin.qq.com/s/OnBjbLzuipWz_u4QfmgcqQ)相比难度刚刚好！

# 216.组合总和III

[力扣题目链接](https://leetcode-cn.com/problems/combination-sum-iii/)

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：
* 所有数字都是正整数。
* 解集不能包含重复的组合。 

示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]

示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]





代码如下:
```CPP
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k,int n,int index,int sum){
        // 终止条件
        if(path.size()==k){
            if(sum==n){
                result.push_back(path);
            }
            return;
        }

        // 回溯
        for(int i=index;i<=9-(k-path.size())+1;i++){  // 剪枝
            sum+=i; // 处理
            path.push_back(i); // 处理
            // 一次只能改变一个条件  横向 还是纵向 
            backtracking(k,n,i+1,sum); 
            sum -= i; // 回溯
            path.pop_back();// 回溯
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(k,n,1,0);
        return result;
    }
};
```
