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

void solve(int A) {
    vector<vector<int>> arr(A, vector<int>(A, 0));
    for (int i = 0; i < A; i++) arr[i].resize(i + 1);
    for (int i = 0; i < A; i++) arr[i][0] = 1;
    for (int i = 1; i < A; i++) {
        for (int j = 1; j < arr[i].size(); j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void getRow(int n) {
    vector<int> result;

    result.push_back(1);

    for (int k = 1; k <= n; k++) {
        result.push_back((result[k - 1] * (n - k + 1)) / (k));
    }

    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    getRow(n);
    return 0;
}