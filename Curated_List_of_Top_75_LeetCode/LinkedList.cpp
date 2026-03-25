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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, 
        function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

        for(auto node : lists) {
            if(node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if(node->next) pq.push(node->next);
        }

        return dummy->next;
    }
};



19. Remove Nth Node From End of List

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if(fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return head;
    }
};



143. Reorder List

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
    
    ListNode* reverse(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverse(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }
    void reorderList(ListNode* head) {
        ListNode* middle = findMiddle(head);

        ListNode* secondHalf = reverse(middle->next);
        middle->next = nullptr;

        ListNode* first = head;
        ListNode* second = secondHalf;

        while(second) {
            ListNode* firstFront = first->next;
            ListNode* secondFront = second->next;

            first->next = second;
            second->next = firstFront;

            first = firstFront;
            second = secondFront;
        }

    }
};


























*/