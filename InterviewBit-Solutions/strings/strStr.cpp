#include<bits/stdc++.h>
using namespace std;

int check(string A, string B, int start){
    int end = start + B.size();
    for(int i=start;i<end;i++){
        if(A[i] != B[i-start]) return -1;
    }
    return 1;
}

int strStr(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    for(int i=0;i<=n-m;i++){
        if(A[i]==B[0] && check(A,B,i)==1) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string A, B;
    cin >> A >> B;
    cout << strStr(A,B)<<endl;
    return 0;
}