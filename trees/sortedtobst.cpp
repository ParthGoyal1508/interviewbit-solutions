#include <bits/stdc++.h>
using namespace std;

int arr[100000];

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;



Node *insert(Node *root, int val) {
    cout << "value for insert is "<< val << endl;
    if (root == NULL) {
        Node *temp = new Node;
        temp->val = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (root->val > val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

Node* insert_array(Node *root, int start, int end) {
    if (end < start) return root;
    if (start == end) {
        root = insert(root, arr[start]);
        return root;
    } else {
        int mid = (start + end) / 2;
        root = insert(root, arr[mid]);
        root->left = insert_array(root->left, start, mid - 1);
        root->right = insert_array(root->right, mid + 1, end);
        return root;
    }
}

int main() {
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++) cin >> arr[i];
    root = insert_array(root, 0, n-1);
    inorder(root);
    cout << endl;
    return 0;
}