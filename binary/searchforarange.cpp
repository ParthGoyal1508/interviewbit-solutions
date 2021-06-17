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

vector<int> searchRange(const vector<int> &A, int B) {
    vector<int> ans;
    auto it = lower_bound(A.begin(), A.end(), B);
    if (it == A.end()) {
        ans.push_back(-1);
    } else {
        if (A[it - A.begin()] == B)
            ans.push_back(it - A.begin());
        else
            ans.push_back(-1);
    }
    it = upper_bound(A.begin(), A.end(), B - 1);
    if (it == A.end()) {
        ans.push_back(ans[0]);
    } else {
        if (ans[0] == -1)
            ans.push_back(-1);
        else {
            while (A[it - A.begin()] == B && it != A.end()) {
                it++;
            }
            ans.push_back(it - A.begin() - 1);
        }
    }
    return ans;
}

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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int b;
    cin >> b;
    vector<int> ans;
    ans = searchRange(arr, b);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}