#include<bits/stdc++.h>
using namespace std;

string getNextSequence(string s){
    string ans;
    for(int i=0;i<s.size();){
        int count = 1;
        while((i!=s.size()-1) && s[i+1]==s[i]){
            count++;
            i++;
        }
        ans.push_back(count+'0');
        ans.push_back(s[i]);
        i++;
    }
    return ans;
}

string countAndSay(int A) {
    int i=1;
    string ans;
    ans = "1";
    while(i<A){
        i++;
        ans = getNextSequence(ans);
    }
   return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int A;
    cin >> A;
    cout << countAndSay(A)<<endl;
    return 0;
}