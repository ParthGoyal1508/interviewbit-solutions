#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string A)
{
    int length = A.size();
    int ans = 0;
    for(int i=length-1; i>=0;i--){
        ans += ((int)A[i] - 64) * pow(26, ((length-1) - i));
    }
    return ans;
}

int main()
{
    string S;
    cin >> S;
    int a = titleToNumber(S);
    cout << a << endl;
    return 0;
}
