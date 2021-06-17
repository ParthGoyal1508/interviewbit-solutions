#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {
    int ans = 0;
    int finalans = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] == ' ') ans = 0;
        else ans++;
        if(ans > 0) finalans = ans;
    }
    return finalans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string A;
    cin >> A;
    cout <<lengthOfLastWord(A)<<endl;
    return 0;
}