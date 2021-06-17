#include <bits/stdc++.h>
using namespace std;

int isPalindrome(int A)
{
  if(A < 0){
      return 0;
  }
  else{
      string S = to_string(A);
      int length = S.size();
      for(int i=0;i<(S.size()/2);i++){
          if(S[i] != S[length-1-i]){
              return 0;
          }
      }
      return 1;
  }
}

int main()
{
    int n;
    cin >> n;
    int a = isPalindrome(n);
    cout << a <<endl;
    return 0;
}
