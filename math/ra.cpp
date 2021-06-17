#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> &A)
{
    int n = A.size();
    for(int i=0;i<n;i++){
        A[i] += (A[A[i]]%n)*n;
    }
    for(int i=0;i<n;i++){
        A[i] = A[i]/n;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arrange(arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
