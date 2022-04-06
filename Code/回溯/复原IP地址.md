# 93.复原IP地址

[力扣题目链接](https://leetcode-cn.com/problems/restore-ip-addresses/)

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

示例 1：
* 输入：s = "25525511135"
* 输出：["255.255.11.135","255.255.111.35"]

示例 2：
* 输入：s = "0000"
* 输出：["0.0.0.0"]

示例 3：
* 输入：s = "1111"
* 输出：["1.1.1.1"]

示例 4：
* 输入：s = "010010"
* 输出：["0.10.0.10","0.100.1.0"]

示例 5：
* 输入：s = "101023"
* 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

提示：
* 0 <= s.length <= 3000
* s 仅由数字组成


# 思路

做这道题目之前，最好先把[131.分割回文串](https://programmercarl.com/0131.分割回文串.html)这个做了。

这道题目相信大家刚看的时候，应该会一脸茫然。

其实只要意识到这是切割问题，**切割问题就可以使用回溯搜索法把所有可能性搜出来**，和刚做过的[131.分割回文串](https://programmercarl.com/0131.分割回文串.html)就十分类似了。

切割问题可以抽象为树型结构，如图：

![93.复原IP地址](https://img-blog.csdnimg.cn/20201123203735933.png)



代码如下：
```CPP
class Solution {
private:
    vector<string> result;
    // 回溯参数 分割问题
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string &s,int startIndex,int pointNum){
        // 终止条件
        // 逗点的数量等于3 并且第四段满足合法条件
        if(pointNum==3){
            if(isValid(s,startIndex,s.size()-1)){
                result.push_back(s); // 直接加了.
            }
            return;
        }

        // 单回溯
        // 要加上.
        for(int i=startIndex;i<s.size();++i){
            if(isValid(s,startIndex,i)){ // 如果合法 回溯
                s.insert(s.begin()+i+1,'.');
                pointNum++;
                backtracking(s,i+2,pointNum);  // 因为加了.
                // 递归
                pointNum--;
                s.erase(s.begin()+i+1);
            }else{
                break; // 如果不合法  直接退出
            }
        }
    }

    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string &s,int begin,int end){
        if(begin > end){
            return false;
        }
        // 不能含有前导0
        if(s[begin]=='0' && begin!=end){
            return false;
        }

        int num = 0;
        // 不能含有其他字符  并且每个整数位于 0 到 255
        for(int i=begin;i<=end;++i){
            if(s[i]>'9' && s[i]<'0'){
                return false;
            }
            
            num = num*10 + (s[i] - '0');
            if(num>255 || num<0){
                return false;
            }

        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        // 就是给一串字符串  判定字符串能组成怎样的有效ip地址
        // 回溯
        result.clear();
        if (s.size() > 12) return result; // 算是剪枝了
        backtracking(s,0,0);
        return result;

    }
};
```
