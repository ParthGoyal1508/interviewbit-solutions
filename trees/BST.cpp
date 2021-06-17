#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int val) {
    if (root == NULL) {
        Node *temp = new Node;
        temp->val = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (root->val > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
}

// void inorder(Node *root) {
//     if (root != NULL) {
//         inorder(root->left);
//         cout << root->val << " ";
//         inorder(root->right);
//     }
// }

void preorder(Node *root) {
    if (root != NULL) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

int i;
int ans;
 
 void inorder(Node *root, int B) {
    if (root != NULL) {
        inorder(root->left, B);
        i++;
        if(i == B)
            ans = root->val;
        inorder(root->right, B);
    }
}

int ub = -1;

void upper_bound(Node *x,int value)
{
    if(x!=NULL){
        upper_bound(x->left, value);
        if(x->val > value && (ub == -1))
            ub = x->val;
        upper_bound(x->right, value);
    }
    return;
}
 
int kthsmallest(Node* A, int B) {
    inorder(A, B);
    return ans;
}

int main() {
    int n;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        root = insert(root, a);
    }
    upper_bound(root, 11);
    cout << ub << endl;
    ub = -1;
    upper_bound(root, 2);
    cout << ub << endl;
    ub = -1;
    upper_bound(root,3);
    cout << ub << endl;
    ub = -1;
    upper_bound(root, 8);
    cout << ub << endl;
    ub = -1;

    // cout << upper_bound(root, 2) << endl;
    // cout << upper_bound(root, 3) << endl;
    // cout << upper_bound(root, 8) << endl;
    // cout << kthsmallest(root, 2)<< endl;
    // cout << "inorder\n";
    // inorder(root);
    // cout << endl;
    // cout << "preorder\n";
    // preorder(root);
    // cout << endl;
    // cout << "postorder\n";
    // postorder(root);
    // cout << endl;
    return 0;
}