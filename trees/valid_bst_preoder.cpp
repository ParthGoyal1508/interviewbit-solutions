#include<bits/stdc++.h>
using namespace std;
int A[100005];

void solve(int n){
    stack<int> S;
    int root = INT_MIN;

    for(int i=0;i<n;i++){
        if(A[i] < root){
            cout << "0\n"; 
            return;
        }
        while((!S.empty()) && (A[i] > S.top())){
            root = S.top();
            S.pop();
        }
        S.push(A[i]);
    }
    cout << "1\n";
    return;
}

int main(){
    int n;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    solve(n);
    return 0;
}