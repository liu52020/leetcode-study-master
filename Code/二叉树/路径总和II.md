> 递归函数什么时候需要返回值

相信很多同学都会疑惑，递归函数什么时候要有返回值，什么时候没有返回值，特别是有的时候递归函数返回类型为bool类型。

那么接下来我通过详细讲解如下两道题，来回答这个问题：

* 112.路径总和
* 113.路径总和ii

# 112. 路径总和

[力扣题目链接](https://leetcode-cn.com/problems/path-sum/)

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

![112.路径总和1](https://img-blog.csdnimg.cn/20210203160355234.png)

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

# 思路

这道题我们要遍历从根节点到叶子节点的的路径看看总和是不是目标和。

## 递归

可以使用深度优先遍历的方式（本题前中后序都可以，无所谓，因为中节点也没有处理逻辑）来遍历二叉树

1. 确定递归函数的参数和返回类型

参数：需要二叉树的根节点，还需要一个计数器，这个计数器用来计算二叉树的一条边之和是否正好是目标和，计数器为int型。

再来看返回值，递归函数什么时候需要返回值？什么时候不需要返回值？这里总结如下三点：

* 如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。（这种情况就是本文下半部分介绍的113.路径总和ii）
* 如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。 （这种情况我们在[236. 二叉树的最近公共祖先](https://programmercarl.com/0236.二叉树的最近公共祖先.html)中介绍）
* 如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。（本题的情况）

而本题我们要找一条符合条件的路径，所以递归函数需要返回值，及时返回，那么返回类型是什么呢？

如图所示：

![112.路径总和](https://img-blog.csdnimg.cn/2021020316051216.png)

图中可以看出，遍历的路线，并不要遍历整棵树，所以递归函数需要返回值，可以用bool类型表示。

所以代码如下：

```
bool traversal(treenode* cur, int count)   // 注意函数的返回类型
```


2. 确定终止条件

首先计数器如何统计这一条路径的和呢？

不要去累加然后判断是否等于目标和，那么代码比较麻烦，可以用递减，让计数器count初始为目标和，然后每次减去遍历路径节点上的数值。

如果最后count == 0，同时到了叶子节点的话，说明找到了目标和。

如果遍历到了叶子节点，count不为0，就是没找到。

递归终止条件代码如下：

```
if (!cur->left && !cur->right && count == 0) return true; // 遇到叶子节点，并且计数为0
if (!cur->left && !cur->right) return false; // 遇到叶子节点而没有找到合适的边，直接返回
```

3. 确定单层递归的逻辑

因为终止条件是判断叶子节点，所以递归的过程中就不要让空节点进入递归了。

递归函数是有返回值的，如果递归函数返回true，说明找到了合适的路径，应该立刻返回。

代码如下：

```cpp
if (cur->left) { // 左 （空节点不遍历）
    // 遇到叶子节点返回true，则直接返回true
    if (traversal(cur->left, count - cur->left->val)) return true; // 注意这里有回溯的逻辑
}
if (cur->right) { // 右 （空节点不遍历）
    // 遇到叶子节点返回true，则直接返回true
    if (traversal(cur->right, count - cur->right->val)) return true; // 注意这里有回溯的逻辑
}
return false;
```

以上代码中是包含着回溯的，没有回溯，如何后撤重新找另一条路径呢。

回溯隐藏在`traversal(cur->left, count - cur->left->val)`这里， 因为把`count - cur->left->val` 直接作为参数传进去，函数结束，count的数值没有改变。

为了把回溯的过程体现出来，可以改为如下代码：

```cpp
if (cur->left) { // 左
    count -= cur->left->val; // 递归，处理节点;
    if (traversal(cur->left, count)) return true;
    count += cur->left->val; // 回溯，撤销处理结果
}
if (cur->right) { // 右
    count -= cur->right->val;
    if (traversal(cur->right, count)) return true;
    count += cur->right->val;
}
return false;
```


整体代码如下：

```cpp
class solution {
private:
    bool traversal(treenode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; // 遇到叶子节点，并且计数为0
        if (!cur->left && !cur->right) return false; // 遇到叶子节点直接返回

        if (cur->left) { // 左
            count -= cur->left->val; // 递归，处理节点;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // 回溯，撤销处理结果
        }
        if (cur->right) { // 右
            count -= cur->right->val; // 递归，处理节点;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; // 回溯，撤销处理结果
        }
        return false;
    }

public:
    bool haspathsum(treenode* root, int sum) {
        if (root == null) return false;
        return traversal(root, sum - root->val);
    }
};
```

以上代码精简之后如下：

```cpp
class solution {
public:
    bool haspathsum(treenode* root, int sum) {
        if (root == null) return false;
        if (!root->left && !root->right && sum == root->val) {
            return true;
        }
        return haspathsum(root->left, sum - root->val) || haspathsum(root->right, sum - root->val);
    }
};
```

**是不是发现精简之后的代码，已经完全看不出分析的过程了，所以我们要把题目分析清楚之后，在追求代码精简。** 这一点我已经强调很多次了！


## 迭代

如果使用栈模拟递归的话，那么如果做回溯呢？

**此时栈里一个元素不仅要记录该节点指针，还要记录从头结点到该节点的路径数值总和。**

c++就我们用pair结构来存放这个栈里的元素。

定义为：`pair<treenode*, int>` pair<节点指针，路径数值>

这个为栈里的一个元素。



代码如下：
```CPP
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 使用迭代  遍历即可
        stack<pair<TreeNode*,int>> s1;
        if(root) s1.push(pair(root,root->val));

        while(!s1.empty()){
            TreeNode* tmp = s1.top().first;
            int value = s1.top().second;  // 当前的总和
            s1.pop();

            if(tmp->right==nullptr && tmp->left==nullptr && value==targetSum) return true;

            if(tmp->left) s1.push(pair(tmp->left,tmp->left->val+value));
            if(tmp->right) s1.push(pair(tmp->right,tmp->right->val+value));
        }

        return false;
    }
};
```


# 113. 路径总和ii

[力扣题目链接](https://leetcode-cn.com/problems/path-sum-ii/)

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，


![113.路径总和ii1.png](https://img-blog.csdnimg.cn/20210203160854654.png)

## 思路


113.路径总和ii要遍历整个树，找到所有路径，**所以递归函数不要返回值！**

如图：

![113.路径总和ii](https://img-blog.csdnimg.cn/20210203160922745.png)


为了尽可能的把细节体现出来，我写出如下代码（**这份代码并不简洁，但是逻辑非常清晰**）

代码如下：
```CPP
class solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // 递归函数不需要返回值，因为我们要遍历整个树
    void traversal(treenode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) { // 遇到了叶子节点且找到了和为sum的路径
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return ; // 遇到叶子节点而没有找到合适的边，直接返回

        if (cur->left) { // 左 （空节点不遍历）
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);    // 递归
            // 递归后面肯定有一个回溯
            count += cur->left->val;        // 回溯
            path.pop_back();                // 回溯
        }
        if (cur->right) { // 右 （空节点不遍历）
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);   // 递归
            count += cur->right->val;       // 回溯
            path.pop_back();                // 回溯
        }
        return ;
    }

public:
    vector<vector<int>> pathsum(treenode* root, int sum) {
        result.clear();
        path.clear();
        if (root == null) return result;
        path.push_back(root->val); // 把根节点放进路径
        traversal(root, sum - root->val);
        return result;
    }
};
```
