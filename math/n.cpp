#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B, int C)
{
    string c = to_string(C);
    int ans = 1;
    int flag = 0;
    if (c.size() < B)
        ans = 0;
    else
    {
        for (int i = 0; i < B; i++)
        {
            int val = int(c[i])- 48;
            cout << "val "<<val <<endl;
            int smaller = upper_bound(A.begin(), A.end(), val) - A.begin();
            if(i==0 && A[0]==0)
                smaller -= 1;
            else if(i== B-1){
                for(int j=0;j<A.size();j++){
                    if(A[i] == val){
                        flag = 1;
                        break;
                    }
                }
            }
            else{
                smaller = A.size();
            }
            cout << "smaller "<<smaller << endl;
            ans = ans * smaller;
        }
        if(flag == 1)
            ans = ans - 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int b, c;
    cin >> b >> c;

    int ans = solve(arr, b, c);
    cout << ans << endl;
    return 0;
}