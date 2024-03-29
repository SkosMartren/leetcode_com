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

 class Solution { // == https://walkccc.me/LeetCode/problems/0021/

 public:

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (list1 == nullptr || list2 == nullptr){ return list1 != nullptr ? list1 : list2; }

    if (list1->val > list2->val){ swap(list1, list2); }
    
    assert(list1->val <= list2->val);

    list1->next = mergeTwoLists(list1->next, list2);

    return list1;
    
  }

};
