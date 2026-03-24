/*

206. Reverse Linked List
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head; 
        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }
};


141. Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast  = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};



21. Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(t1 && t2) {
            if(t1->val <= t2->val) {
                temp->next = t1;
                temp = temp->next;
                t1 = t1->next;
            }
            else if(t2->val < t1->val) {
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
            }
        }
        if(t1)  temp->next = t1;
        if(t2)  temp->next = t2;
        return dummyNode->next;
    }
};


23. Merge k Sorted Lists






























*/