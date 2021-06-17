#include <bits/stdc++.h>
using namespace std;

int gcd(int A, int B)
{
   for(int i=min(A,B); i >=1; i--){
       if((A%i == 0) && (B%i==0)){
           return i;
       }
   }
}

int main()
{
    int n,m;
    cin >> n >> m;
    int a = gcd(n, m);
    cout << a << endl;
    return 0;
}
