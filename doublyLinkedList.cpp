#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};


void printDLL(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* convert2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head; 
}

Node* deleteTail(Node* head) {
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    
    temp -> next -> back = nullptr;
    delete temp->next;
    temp -> next = nullptr;
    return head;
    
}

//          BETTER APPROACH
Node* deleteTail2(Node* head) {
    if(head==nullptr) return nullptr;
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* tail = head;
    while(tail->next) {
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}


Node* deleteKthElement(Node* head, int k) {
    if(head == nullptr) return nullptr;
    if(k <= 0) return head;

    Node* kNode = head;
    int count = 0;
    while(kNode) {
        count++;
        if(count == k) break;
        kNode = kNode->next;
    }
    if(kNode == nullptr) return head;

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == nullptr && front == nullptr) {
        return nullptr;
    }
    else if(prev == nullptr) {
        head = head->next;
        head->back = nullptr;
        delete kNode;
        return head;
    }
    else if(front == nullptr) {
        prev->next = nullptr;
        delete kNode;
        return head;
    }

    prev->next = front;
    front->back = prev;

//      there is no need of this as you are deleting the node
//      at the end 
    // kNode->next = nullptr;
    // kNode->back = nullptr;

    delete kNode;
    return head;
}

Node* deleteNodeN(Node* head, int nodeN) {
    if(head == NULL) return head;
    Node* temp = head;

    while(temp) {
        if(temp->data == nodeN) break;
        temp = temp->next;
    }

    if(temp == nullptr) return head;

    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == nullptr) {
        prev->next = nullptr;
        delete temp;
        return head;
    }
    
    prev->next = front;
    front->back = prev;

    delete temp;
    return head;
}

void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == nullptr) {
        prev->next = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    delete temp;
}

Node* insertBeforeHead(Node* head, int value) {
    Node* newHead = new Node(value, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int value) {
    if(head->next == NULL) {
        return insertBeforeHead(head, value);
    }
    Node* tail = head;
    while(tail->next) {
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(value, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int value) {
    if(k==1) return insertBeforeHead(head, value);

    Node* temp = head;
    int count = 0;
    while(temp) {
        count++;
        if(count == k) break;
        temp = temp->next;
    }
    if(temp == nullptr) return head;

    Node* prev = temp->back;
    Node* newNode = new Node(value, temp, prev);
    
    prev->next = newNode;
    temp->back = newNode;

    return head;
}


void insertBeforeGivenNode(Node* node, int value) {
    
    Node* prev = node->back;
    Node* newNode = new Node(value, node, prev);
    
    node->back = newNode;
    prev->next = newNode;
}


// Reverse a DLL


int main() {
    vector<int> arr = {12,5,8,7};
    Node* head = convert2DLL(arr);
    // deleteHead(head);
    // deleteTail2(head);
    // deleteKthElement(head, 9);
    // deleteNodeN(head, 8);
    // deleteNode(head->next->next);
    // head = insertBeforeHead(head, 10);
    // head = insertBeforeTail(head, 10);
    // head = insertBeforeKthElement(head, 3, 10);
    insertBeforeGivenNode(head->next->next->next, 10);
    printDLL(head);
}