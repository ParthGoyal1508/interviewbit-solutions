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

vector<int> arr;

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
}


int t2Sum(Node* A, int B) {
    inorder(A);
    int ans = 0;
    int left=0,right=arr.size()-1;

    for(int i=0;i<arr.size();i++)
        cout << arr[i]<< " ";
        cout << endl;
    while(left < right){
        if(arr[left] + arr[right] == B){
            cout << "arr is "<< arr[left]<< " "<< arr[right]<< endl;
            ans = 1;
            break;
        }
        else if (arr[left]+ arr[right] < B){
            left++;
        }
        else{
            right--;
        }
    }
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
    cout << t2Sum(root, 40)<< endl;
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