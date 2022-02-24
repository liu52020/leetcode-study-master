> KMP算法还能干这个

# 459.重复的子字符串

[力扣题目链接](https://leetcode-cn.com/problems/repeated-substring-pattern/)

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:    
输入: "abab"    
输出: True      
解释: 可由子字符串 "ab" 重复两次构成。   

示例 2:     
输入: "aba"  
输出: False       

示例 3:      
输入: "abcabcabcabc"   
输出: True      
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

# 思路

这又是一道标准的KMP的题目。

如果KMP还不够了解，可以看我的B站：

* [帮你把KMP算法学个通透！（理论篇）](https://www.bilibili.com/video/BV1PD4y1o7nd/)
* [帮你把KMP算法学个通透！（求next数组代码篇）](https://www.bilibili.com/video/BV1M5411j7Xx)


我们在[字符串：KMP算法精讲](https://programmercarl.com/0028.实现strStr.html)里提到了，在一个串中查找是否出现过另一个串，这是KMP的看家本领。

那么寻找重复子串怎么也涉及到KMP算法了呢？

这里就要说一说next数组了，next 数组记录的就是最长相同前后缀( [字符串：KMP算法精讲](https://programmercarl.com/0028.实现strStr.html) 这里介绍了什么是前缀，什么是后缀，什么又是最长相同前后缀)， 如果 next[len - 1] != -1，则说明字符串有最长相同的前后缀（就是字符串里的前缀子串和后缀子串相同的最长长度）。

最长相等前后缀的长度为：next[len - 1] + 1。(这里的next数组是以统一减一的方式计算的，因此需要+1)

数组长度为：len。

如果len % (len - (next[len - 1] + 1)) == 0 ，则说明 (数组长度-最长相等前后缀的长度) 正好可以被 数组的长度整除，说明有该字符串有重复的子字符串。

**数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。**


**强烈建议大家把next数组打印出来，看看next数组里的规律，有助于理解KMP算法**

代码如下：
```CPP
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0) return false;

        int next[s.size()];
        getNext(next,s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;

    }

    // 首先获取next数组
    void getNext(int *next,const string & s){
        int j=0;
        next[0] = j;
        for(int i=1;i<s.size();++i){
        while(j>0 && s[i]!=s[j]){
            j = next[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }

        next[i] = j;
        }
    }
};
```
