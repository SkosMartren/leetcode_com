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

private:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b){

        if(a == nullptr){
            return b;
        }
        if(b == nullptr){
            return a;
        }

        if(a->val < b->val){

            a->next = mergeTwoLists(a->next, b);
            return a;

        }else{

            b->next = mergeTwoLists(a, b->next);
            return b;

        }
    }   

public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Example 2
        if(lists.empty()){
            return nullptr;
        }

        while(lists.size() != 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            
            lists.erase(lists.begin()); lists.erase(lists.begin());
        } 

        return lists.back();
    }
};
// more slow
/*
class Solution {

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == nullptr){
            return list2;
        }

        if(list2 == nullptr){
            return list1;
        }

        if(list1->val < list2->val){

            list1->next = mergeTwoLists(list1->next , list2);
            return list1;
        }

        list2->next = mergeTwoLists(list1 , list2->next);
        return list2;

    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()){
            return nullptr;
        }

        while(lists.size() != 1){

            ListNode* list1 = lists.back();  lists.pop_back(); 
            ListNode* list2 = lists.back();  lists.pop_back(); 
            lists.push_back(mergeTwoLists(list1, list2));
        }

        return lists.front();
    }
};
*/
