# 559.n叉树的最大深度

[力扣题目链接](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/)

给定一个 n 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :

![559.n叉树的最大深度](https://img-blog.csdnimg.cn/2021020315313214.png)

我们应返回其最大深度，3。

思路：

依然可以提供递归法和迭代法，来解决这个问题，思路是和二叉树思路一样的，直接给出代码如下：

## 递归法

c++代码：

```CPP
class solution {
public:
    int maxdepth(node* root) {
        if (root == 0) return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++) {
            depth = max (depth, maxdepth(root->children[i]));
        }
        return depth + 1;
    }
};
```
## 迭代法

代码如下：
```CPP
class Solution {
public:
    int maxDepth(Node* root) {
        // 跟二叉树的最大深度一样  同样是用层序遍历的方法
        int depth=0;
        queue<Node*> que;
        if(root!=nullptr) que.push(root);

        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i=0;i<size;++i){
                Node* cur = que.front();
                que.pop();
                for(int j=0;j<cur->children.size();++j){
                    if(cur->children[j]!=nullptr) que.push(cur->children[j]);
                }
            }
            
        }

        return depth;
        
    }
};
```
