#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string A) {
    string modified;
    modified.resize(0);
    for(int i=0;i<A.size();i++){
        if(int(A[i]) >=48 && int(A[i] <=57))
            modified.push_back(A[i]);
        else if(int(A[i]) >=65 && int(A[i] <=90))
            modified.push_back(tolower(A[i]));
        else if(int(A[i]) >=97 && int(A[i] <=122))
            modified.push_back(A[i]);
    }
    for(int i=0;i<modified.size();i++){
        if(modified[i]!=modified[modified.size()-1-i]){
            return 0;
        }
    }
        return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string A = "A man, a plan, a canal: Panama";
    cout << isPalindrome(A)<< endl;
    return 0;
}