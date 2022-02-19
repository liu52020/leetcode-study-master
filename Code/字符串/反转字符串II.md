> 简单的反转还不够，我要花式反转

# 541. 反转字符串II

[力扣题目链接](https://leetcode-cn.com/problems/reverse-string-ii/)

给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

如果剩余字符少于 k 个，则将剩余字符全部反转。

如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2    
输出: "bacdfeg"    

# 思路

这道题目其实也是模拟，实现题目中规定的反转规则就可以了。

一些同学可能为了处理逻辑：每隔2k个字符的前k的字符，写了一堆逻辑代码或者再搞一个计数器，来统计2k，再统计前k个字符。

其实在遍历字符串的过程中，只要让 i += (2 * k)，i 每次移动 2 * k 就可以了，然后判断是否需要有反转的区间。

因为要找的也就是每2 * k 区间的起点，这样写，程序会高效很多。

**所以当需要固定规律一段一段去处理字符串的时候，要想想在在for循环的表达式上做做文章。**

性能如下：
<img src='https://code-thinking.cdn.bcebos.com/pics/541_反转字符串II.png' width=600> </img></div>

那么这里具体反转的逻辑我们要不要使用库函数呢，其实用不用都可以，使用reverse来实现反转也没毛病，毕竟不是解题关键部分。


代码如下：
```CPP
class Solution {
public:
    string reverseStr(string s, int k) {

        // 也就是对于s来说  隔k个元素  反转一次
        int length = s.size();
        
        for(int i=0;i<length;i+=2*k){
            int left=i,right=i+k-1;
            // 反转字符串
            if(right<length){
                revStr(s,left,right);
                continue;
            }

            revStr(s,i,length-1);
            

        }

        return s;
    }

    // 反转字符串
    void revStr(string &s, int left,int right){  // 改变s
        while(left<=right){
            int tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;

        }
    }
};
```
