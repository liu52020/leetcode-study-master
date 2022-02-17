## 19.删除链表的倒数第N个节点

[力扣题目链接](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

示例 1：

![19.删除链表的倒数第N个节点](https://img-blog.csdnimg.cn/20210510085957392.png)

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]


## 思路

双指针的经典应用，如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，直到fast指向链表末尾。删掉slow所指向的节点就可以了。

思路是这样的，但要注意一些细节。

分为如下几步：

* 首先这里我推荐大家使用虚拟头结点，这样方面处理删除实际头结点的逻辑，如果虚拟头结点不清楚，可以看这篇： [链表：听说用虚拟头节点会方便很多？](https://programmercarl.com/0203.移除链表元素.html)

* 定义fast指针和slow指针，初始值为虚拟头结点，如图：

<img src='https://code-thinking.cdn.bcebos.com/pics/19.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.png' width=600> </img></div>

* fast首先走n + 1步 ，为什么是n+1呢，因为只有这样同时移动的时候slow才能指向删除节点的上一个节点（方便做删除操作），如图：
<img src='https://code-thinking.cdn.bcebos.com/pics/19.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B91.png' width=600> </img></div>

* fast和slow同时移动，直到fast指向末尾，如题：
<img src='https://code-thinking.cdn.bcebos.com/pics/19.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B92.png' width=600> </img></div>

* 删除slow指向的下一个节点，如图：
<img src='https://code-thinking.cdn.bcebos.com/pics/19.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B93.png' width=600> </img></div>

**思路1： 倒数变正数解决问题**

代码如下：
```CPP
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // 删除链表的倒数第n个结点   首先需要找到这个结点
        // 找到正数第size-n的结点 

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        int size = 0; // 链表的结点数
        ListNode* tmp = dummyNode;
        while(tmp){
            size++;
            tmp = tmp->next;
        }

        std::cout<<"结点数为："<<size<<std::endl;  // 加上虚拟节点

        int num = size-n;  //3  

        // 找到正数第num个结点  删除其后面的结点
        while(num>1){  // 找到第n个结点前面那个结点
            cur = cur->next;
            num--;
        }
        
        // 分析情况  
        // 如果删除的是第一个结点  使用虚拟头结点就可以解决问题 
        // 如果删除的是最后一个结点  那么只需要将cur指向nulptr
        if(cur->next->next!=nullptr){
            cur->next = cur->next->next;
        }else{
            cur->next = nullptr;
        }
        

        return dummyNode->next;


    }
};
```

**思路2： 快慢指针解决问题**

```CPP

```

