#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int lengthOfLL(Node* head) {
    Node* temp = head;
    int count=0;
    while(temp) {
        temp = temp->next;
        count++;
    }
    return count;
}


Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

bool checkIfPresent(Node* head, int value) {
    Node* temp = head;
    while(temp) {
        if(temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}


Node* removesHead(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp -> next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* removeK(Node* head, int k) {
    if(head == NULL) return head;

    if(k==1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count=0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp) {
        count++;
        if(count == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


Node* removeElement(Node* head, int element) {
    if(head == NULL) return head;

    if(head->data == element) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp) {
        if(temp->data == element) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int value) {
    Node* temp = new Node(value, head);
    return temp;
}

Node* insertTail(Node* head, int value) {
    if(head == NULL) return new Node(value);
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;       
    }
    Node* element = new Node(value);
    temp->next = element;
    return head;
}

Node* insertK(Node* head, int value, int k) {
    if(head == NULL) {
        if(k==1) return new Node(value);
        else return head;
    }
    if(k==1) {
        return new Node(value, head);
    }
    
    int count=0; 
    Node* temp = head;
    while(temp) {
        count++;
        if(count == k-1) {
            Node* element = new Node(value, temp->next);
            temp->next = element;
            break;
        }
        temp = temp->next;
    }
    return head;
}


Node* insertBeforeValue(Node* head, int value, int element) {
    if(head == NULL) {
        return head;
    }
    if(head->data == value) {
        return new Node(element, head);
    }
    
    Node* temp = head;
    while(temp->next) {

        if(temp->next->data == value) {
            Node* n = new Node(element, temp->next);
            temp->next = n;
            break;
        }
        temp = temp->next;
    }
    return head;
}


int main() {
    vector<int> arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);
    // head = removeTail(head);
    // head = removeElement(head, 7);
    head  = insertBeforeValue(head, 7, 10);
    print(head);
    // cout<<endl<<lengthOfLL(head);
    // cout<<endl<<boolalpha<<checkIfPresent(head, 8);
}