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

  ListNode* removeNthFromEnd(ListNode* head, int n) { 

    ListNode* front = head;
    for (int i = 0; i < n; i++) {
      front = front->next;
    }

    if (front == nullptr) { 
      ListNode* toDelete = head;
      head = head->next; 
      delete toDelete; 
      return head;
    }

    ListNode* back = head;
    while (front->next != nullptr) {
      front = front->next; 
      back = back->next;
    }

    ListNode* toDelete = back->next;
    back->next = back->next->next;
    delete toDelete;
    return head;
  }

};


