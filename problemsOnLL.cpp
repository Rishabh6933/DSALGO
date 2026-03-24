// 2. Add Two Numbers
/*

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;

        while(t1!=nullptr || t2!=nullptr) {
            int sum = 0 + carry;
            if(t1) {
                sum += t1->val;
                t1 = t1->next;                    
            }
            if(t2) {
                sum += t2->val;
                t2 = t2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            curr->next = new ListNode(sum);
            curr = curr->next;
            
        }

        if(carry) {
            curr->next = new ListNode(carry);
        }
        return dummyNode->next; 
    }
};
*/


// 328. Odd Even Linked List
/*
    first store the odd element in an array and then store the even elements in the array
    then at the end store the elements in the same order as stored in the array

<----------------------BASIC APPROACH---------------------->
class Solution {
    public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        vector<int> arr;
        ListNode* temp = head;
        
        while(temp && temp->next) {
            arr.push_back(temp->val);
            temp = temp -> next -> next;
            }
            if(temp) arr.push_back(temp->val);
        temp = head->next;

        while(temp && temp->next)  {
            arr.push_back(temp->val);
            temp = temp -> next -> next;
            }
            if(temp) arr.push_back(temp->val);
            
            int i = 0;
            temp = head;
            while(temp) {
                temp -> val = arr[i];
                i++;
                temp = temp -> next;
                }
                return head;
                }
                };
                
                
<----------------------OPTIMISED APPROACH---------------------->
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* even = head->next;
        ListNode* odd = head;
        ListNode* evenHead = head->next;

        while(even && even->next) {
            odd->next = odd->next->next;
            even -> next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};              
*/



//  Sort a LinkedList of 0's, 1's and 2's
/*

<----------------------BASIC APPROACH---------------------->
take three counters count0, count1, count2 and count the number of 0s, 1s & 2s
now traverse throught the array and place the values in order of decreasing as per the count

<----------------------OPTIMISED APPROACH---------------------->
Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;
    
    while(temp) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1) {
            one->next = temp;
            one = temp;
        }    
        else {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;                    
    }
                    
                    
    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
                    
    Node* newHead = zeroHead->next;
    delete zeroHead; 
    delete oneHead;
    delete twoHead;

    return newHead;

}
*/
                   
                   
                   
                   


/*
    19. Remove Nth Node From End of List
<----------------------BASIC APPROACH---------------------->


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) {
            delete head;
            return nullptr;
        }
        
        ListNode* temp = head;
        int size=0;
        while(temp) {
            size++;
            temp = temp->next;
        }

        if(size == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int count = 0;
        temp = head;
        while(temp) {
            count++;
            if(count == size-n) break;
            temp = temp->next;
        }

        if(temp == nullptr) return head;
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        return head;
    }
};


<----------------------OPTIMISED APPROACH---------------------->

###################################
#     fast n steps                #
#     Move fast + slow together   #
#     Delete slow->next           #
###################################


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
        
        */

       
// 206. Reverse Linked List
/*
Basic approach is that create a stack and store all the elements
and make a new then put those elements back in the linked list
as stack follows the rule of LIFO the linked list will automatically 
be reversed
But it so basic that.....!!!!!


<----------------------OPTIMISED APPROACH---------------------->


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front;
        
        while(temp) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

<----------------------RECURSIVE APPROACH---------------------->

Original: 1 -> 2 -> 3 -> 4 -> 5

reverseList(1) calls reverseList(2)
  reverseList(2) calls reverseList(3)
    reverseList(3) calls reverseList(4)
      reverseList(4) calls reverseList(5)
        returns 5  ← this is newHead, ALWAYS 5
      newHead = 5, fix 4->5 to 5->4, return 5
    newHead = 5, fix 3->4 to 4->3, return 5
  newHead = 5, fix 2->3 to 3->2, return 5
newHead = 5, fix 1->2 to 2->1, return 5


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
*/


/*
876. Middle of the Linked List

<----------------------BASIC APPROACH---------------------->

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp) {
            size++;
            temp = temp->next;
        }
        int midNode = (size/2)+1;
        temp = head;

        while(temp) {
            midNode--;
            if(midNode == 0) break;
            temp = temp->next;
        }
        return temp;
    }
};


<----------------------OPTIMISED APPROACH---------------------->
                    [TortoiseHare Method]
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
};
*/

/*
        141. Linked List Cycle


    basic approach can be if use a map and check for the node if it
    is visited or not before if the node is already visited return true
    otherwise return false
<----------------------OPTIMISED APPROACH---------------------->

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

*/


/*
142. Linked List Cycle II
        Given the head of a linked list, 
        return the node where the cycle begins. 
        If there is no cycle, return null.

<----------------------BASIC APPROACH---------------------->
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp) {
            if(mpp.find(temp) != mpp.end()) return temp;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
    }
};


<----------------------OPTIMISED APPROACH---------------------->
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
*/


/*
        find the length of a loop in LL

<----------------------BASIC APPROACH---------------------->
#include <bits/stdc++.h>
int lengthOfLoop(Node *head) {
    Node* temp = head;
    unordered_map<Node* , int> mpp;
    int timer = 1;
    while(temp) {
        if(mpp.find(temp) != mpp.end()) {
            int value = mpp[temp];
            return timer-value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;

    }
    return 0;
}

<----------------------OPTIMISED APPROACH---------------------->
int lengthOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            int count=1;
            fast = fast->next;
            while(slow != fast) {
                fast = fast->next;
                count++;
            }
            return count;
        }
    }
    return 0;
}

*/



/*
234. Palindrome Linked List
<----------------------BASIC APPROACH---------------------->

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            if(temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};

<----------------------OPTMISED APPROACH---------------------->
class Solution {
public:
    // reverses list and returns new head
    ListNode* reverseLL(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = reverseLL(head->next); // recurse to last node

        // reverse the link
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead; // always the last node, bubbled up
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        // step 1: find middle — slow stops at end of first half
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // step 2: reverse second half
        ListNode* newHead = reverseLL(slow->next);

        // step 3: compare both halves
        ListNode* first = head;
        ListNode* second = newHead;
        while(second) {
            if(first->val != second->val) {
                slow->next = reverseLL(newHead); // restore before return
                return false;
            }
            first = first->next;
            second = second->next;
        }

        slow->next = reverseLL(newHead); // restore original list
        return true;
    }
};
*/


/*
        2095. Delete the Middle Node of a Linked List

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;
        return head;
    }
};
*/


/*
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
        if(t1) {
            temp->next = t1;
        }
        if(t2) {
            temp->next = t2;
        }
        return dummyNode->next;
    }
};
*/


/*
        148. Sort List

#####   Most basic approach that can be used is 
        put the linked list inside an array
        then sort the array and put it back into the 
        Linked list

<----------------------OPTIMISED APPROACH---------------------->

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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next; 
            }
            else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge(leftHead, rightHead);

    }
};

*/