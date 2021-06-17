#include <bits/stdc++.h>
using namespace std;

int n;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void print_inorder(TreeNode *root) {
    if (root != NULL) {
        print_inorder(root->left);
        cout << root->val << " ";
        print_inorder(root->right);
    }
}

int get_root(int inorder[], int val) {
    for (int i = 0; i < n; i++) {
        if (inorder[i] == val) return i;
    }
}

TreeNode *insert_array(int inorder[], int postorder[], int s1, int e1, int *pindx) {
    if (s1 > e1) return NULL;
    int val = postorder[*pindx];
    TreeNode *temp = new TreeNode;
    temp->val = val;
    temp->left = temp->right = NULL;
    if (s1 == e1) return temp;
    *pindx--;
    int ind = get_root(inorder, val);
    temp->right = insert_array(inorder, postorder, ind + 1, e1, pindx);
    temp->left = insert_array(inorder, postorder, s1, ind - 1, pindx);
    return temp;
}

int main() {
    cin >> n;
    TreeNode *root = NULL;
    int inorder[100000];
    int postorder[100000];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    int index = n - 1;
    root = insert_array(inorder, postorder, 0, n - 1, &index);
    print_inorder(root);
    cout << endl;
    return 0;
}