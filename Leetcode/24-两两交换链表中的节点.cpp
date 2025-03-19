// 1.迭代
// 2.模拟
// 可以使用虚拟头结点去做这道题(其实可以设置一个虚拟头结点，这样原链表的所有节点就都可以按照统一的方式进行移除了。)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* cur = dummynode;
        while(cur->next != NULL && cur->next->next != NULL){
            ListNode* temp1 = cur->next;
            ListNode* temp2 = cur->next->next;
            cur->next = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            cur = temp1;
        }
        ListNode* res = dummynode->next;
        delete dummynode;
        return res;
    }
};
