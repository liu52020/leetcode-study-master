> 在一个串中查找是否出现过另一个串，这是KMP的看家本领。

# 28. 实现 strStr()

[力扣题目链接](https://leetcode-cn.com/problems/implement-strstr/)

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1

说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。


# 思路

本题是KMP 经典题目。

KMP的经典思想就是:**当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。**


# 什么是KMP
说到KMP，先说一下KMP这个名字是怎么来的，为什么叫做KMP呢。

因为是由这三位学者发明的：Knuth，Morris和Pratt，所以取了三位学者名字的首字母。所以叫做KMP

# KMP有什么用
KMP主要应用在字符串匹配上。

KMP的主要思想是当出现字符串不匹配时，可以知道一部分之前已经匹配的文本内容，可以利用这些信息避免从头再去做匹配了。

所以如何记录已经匹配的文本内容，是KMP的重点，也是next数组肩负的重任。

其实KMP的代码不好理解，一些同学甚至直接把KMP代码的模板背下来。

没有彻底搞懂，懵懵懂懂就把代码背下来太容易忘了。

不仅面试的时候可能写不出来，如果面试官问：next数组里的数字表示的是什么，为什么这么表示？

估计大多数候选人都是懵逼的。



代码如下：
```CPP
class Solution {
public:
    int strStr(string haystack, string needle) {
        //这道题没太弄懂  只能用自己的话去解释
        // KMP算法

        if(needle.size()==0) return 0;
        int next[needle.size()];  // 创建next数组
        getNext(next,needle);

        // 遍历
        int j=-1; 
        for(int i=0;i<haystack.size();++i){
            while(j>=0 && haystack[i]!=needle[j+1]){
                j = next[j]; // 回退
            }

            if(haystack[i]==needle[j+1]){
                j++;
            }

            if(j==needle.size()-1){  // 从-1开始的  所以j只需要到needle.size()-1
                return i-needle.size()+1;
            }
        }

        return -1;
        
    }

    // 计算next数组
    void getNext(int *next,string &s){  // next数组以指针的形式传入   
        // 以指针传入是为了不必要的复制开销
        // 构建两个指针 i、j
        // 本函数 采用-1操作  即next数组整体右移动 即开头为-1
        // 初始化 j从-1开始  next[0] 必是0
        // next数组代表的是 字符串最长相等前后缀
        int j = -1;
        next[0] = j;
        for(int i=1;i<s.size();++i){
            while(j>=0 && s[i]!=s[j+1]){ //  前后缀不相同了  不太理解
                j = next[j]; // 回退j
            }
            if(s[i]==s[j+1]){
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }



    }
};
```
