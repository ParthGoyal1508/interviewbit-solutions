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

int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            swap(A[i], A[j]);
            j++;
        }
    }
    for (int p = j; p < n; p++) {
        if (((abs(A[p]) + j - 1) < n) && (A[abs(A[p]) + j - 1] > 0)) {
            A[abs(A[p]) + j - 1] *= -1;
        }
    }
    for (int i = j; i < n; i++) {
        if (A[i] > 0) return (i - j + 1);
    }
    return n - j + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = firstMissingPositive(arr);
    return 0;
}