### 0002 两数相加

> **题目：**
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
<br>**示例：**
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

#### （1）第一次提交

按链表从头到尾相加，保留余数到下一轮进位，直到两个链表都到尽头。

```cpp
while (p1 != NULL || p2 != NULL){}
```

结果：**不通过**。

比如两个加和数列为{5}、{5}，得到了错误的结果{0}。原因是循环结束条件不对，不能用加和数列到尾做判断，即使加和数列到尾，如果还有进位，也要再做一次计算。真正的结束条件是**加和列表和进位均为零**。

#### （2）第二次提交

把进位为零补充到循环结束条件中。

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode *p1, *p2, *p3;
        int i1, i2, i3;
        int carry, remainder;
        int is_empty;

        p1 = l1;
        p2 = l2;
        carry = 0;
        is_empty = 1;

        while (p1 != NULL || p2 != NULL || carry != 0){
            if (p1 != NULL){
                i1 = p1->val;
                p1 = p1->next;
            }
            else
                i1 = 0;

            if (p2 != NULL){
                i2 = p2->val;
                p2 = p2->next;
            }
            else
                i2 = 0;

            i3 = i1 + i2 + carry;
            carry = i3 / 10;
            remainder = i3 % 10;

            if(is_empty){
                p3 = new ListNode(remainder);
                result = p3;
                is_empty = 0;
            }
            else
            {
                p3->next = new ListNode(remainder);
                p3 = p3->next;
            }
        }

        return result;
    }
};
```

再提交，通过。

| 提交结果 | 执行用时 (pctl%) | 内存消耗 (pctl%) | 语言 |
|:---------|:-----------------|:-----------------|:-----|
| 通过     | 28 ms (54.53%)   | 72.5 MB (5.23%)  | cpp  |

#### （3）收获

思考过程务必要严密，尤其对需要特殊对待的地方，要格外留心。
