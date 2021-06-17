#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var, start, end) for (ll var = start; var < end; ++var)
#define rlp(var, start, end) for (ll var = start; var >= end; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(), X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))

const ll N = 1e5 + 5, inf = 1e18;

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y % 2) res = (res * x) % p;
        y = y / 2;
        x = (x * x) % p;
    }
    return res;
}
void rotate(vector<vector<int>> &A) {
    int n = A.size();
    int count = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j <= n - 2 - i; j++) {
            count += 1;
            int temp = A[j][n - 1 - i];
            A[j][n - 1 - i] = A[i][j];
            int temp2 = A[n - i - 1][n - j - 1];
            A[n - i - 1][n - j - 1] = temp;
            int temp3 = A[n - 1 - j][i];
            A[n - 1 - j][i] = temp2;
            A[i][j] = temp3;
        }
    }
    cout << "COUNT::" << count << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    rotate(arr);
    return 0;
}