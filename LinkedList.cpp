#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

//Node* head;

Node* InsertNodeAtBegin(Node* head, int x){
    // Node* tmp = (Node*)malloc(sizeof(Node)); -- C style, cast needed since malloc returns void ptr
    Node* tmp = new Node(); // C++ way
    
    tmp->data = x; // (*tmp).data = 2; in C
    tmp->next = head;
    head = tmp;
    return head;
}

Node* InsertNodeAtN(Node* head, int data, int n) {
    Node* tmp1 = new Node();
    tmp1->data = data;
    tmp1->next = NULL;
    if (n == 1){
        tmp1->next = head;
        head = tmp1;
        return head;
    }
    Node* tmp2 = head;
    for(int i = 0; i < n-2; i++) {
        tmp2 = tmp2->next;
    }
    tmp1->next = tmp2->next;
    tmp2->next = tmp1;
    return head;
}

void DeleteNodeAtN(Node* head, int n) {

    Node* tmp1 = head;
    if (n == 1) {
        head = tmp1->next; //head now points to second node
        delete(tmp1);
        return;
    }
    for (int i = 0; i < n-2; i++){
        tmp1 = tmp1->next; //tmp1 now points to (n-1)th Node
    }
    Node* tmp2 = tmp1->next; //nth node
    tmp1->next = tmp2->next; // (n+1)th Node
    delete(tmp2);
}

Node* ReverseList(Node* head) {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void PrintList(Node* head){
    Node* tmp = head;
    std::cout << "List: ";
    while(tmp != NULL) {
        std::cout << tmp->data;
        tmp = tmp->next;
    }
    std::cout << "\n";
}

void PrintListRecursion(Node* p) {
    if(p == NULL) return;
    cout << p->data;
    PrintListRecursion(p->next);
}

void ReversePrintListRecursion(Node* p) {
    if(p == NULL) return;  
    PrintListRecursion(p->next); 
    cout << p->data;
}

int main(){

    Node* head = NULL; 

    head = InsertNodeAtBegin(head, 2);
    head = InsertNodeAtBegin(head, 4);
    head = InsertNodeAtBegin(head, 7);
    head = InsertNodeAtBegin(head, 1);
    PrintListRecursion(head); cout << "\n";
    head = ReverseList(head);
    PrintListRecursion(head); cout << "\n";
}