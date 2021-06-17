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
vector<pair<int, int>> ans;

void inorder(Node *root, int left_moves) {
    if (root != NULL) {
        inorder(root->left, left_moves + 1);
        ans.push_back({left_moves, root->val});
        inorder(root->right, left_moves);
    }
}

void solve(Node *root) {
    ans.clear();
    inorder(root, 0);
    vector<int> finalans;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        finalans.push_back(ans[i].second);
    }
    for (int i = 0; i < finalans.size(); i++) 
        cout << finalans[i] << " ";
    cout << endl;
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
    solve(root);

    return 0;
}