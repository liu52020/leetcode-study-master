## 59.螺旋矩阵II

[力扣题目链接](https://leetcode-cn.com/problems/spiral-matrix-ii/)

给定一个正整数 n，生成一个包含 1 到 $n^2$ 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

## 思路

这道题目可以说在面试中出现频率较高的题目，**本题并不涉及到什么算法，就是模拟过程，但却十分考察对代码的掌控能力。**

要如何画出这个螺旋排列的正方形矩阵呢？

相信很多同学刚开始做这种题目的时候，上来就是一波判断猛如虎。

结果运行的时候各种问题，然后开始各种修修补补，最后发现改了这里哪里有问题，改了那里这里又跑不起来了。

大家还记得我们在这篇文章[数组：每次遇到二分法，都是一看就会，一写就废](https://programmercarl.com/0704.二分查找.html)中讲解了二分法，提到如果要写出正确的二分法一定要坚持**循环不变量原则**。


代码如下：
```CPP
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 将数据排列进去
        vector<vector<int>> res(n,vector<int>(n,0));

        // 创建四个边界
        int count = 0;
        int right = n-1, left=0, up=0, down=n-1;
        while((right>=left)&&(up<=down)){
            // 从左到右
            for(int i=left;i<right;++i){
                res[up][i] = ++count;
            }
            

            // 从上到下
            for(int i=up;i<down;++i){
                res[i][right] = ++count;
            }
           

            // 从右到左
            for(int i=right;i>left;--i){
                res[down][i] = ++count;
            }

            // 从下到上
            for(int i=down;i>up;--i){
                res[i][left] = ++count;
            }

            // 修改边界
            up++;
            down--;
            right--;
            left++;

        }

        // 如果n是奇数的话  中间会落下一个
        if(n%2!=0){
            res[n/2][n/2] = ++count;   // 中间那个数据
        }
        
        return res;

    }
};
```
