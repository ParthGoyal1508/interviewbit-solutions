#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* insert_at_end(Node* head, int n) {
    Node* temp = new Node;
    temp->val = n;
    temp->next = NULL;
    Node* curr = head;
    if (head == NULL) {
        head = temp;
        return head;
    } else {
        while (curr->next != NULL) curr = curr->next;
        curr->next = temp;
        return head;
    }
}

Node* insert_at_front(Node* head, int n){
    Node* temp = new Node;
    temp->val = n;
    temp->next = head;
    return temp;
}

Node* reverse(Node* head, int k){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;
    while(curr!=NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
        head->next = reverse(next, k);
    return prev;
}
int print_list(Node* head) {
    Node* curr = head;
    int count = 0;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
        count++;
    }
    cout << endl;
    return count;
}

int main() {
    Node* head = NULL;
    while (1) {
        int n, count;
        cin >> n;
        head = insert_at_front(head, n);
        count = print_list(head);
        // cout << count << endl;
        head = reverse(head, 3);
        count = print_list(head);
    }
    return 0;
}