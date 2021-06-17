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

string solve(string A) {
    long long int n = A.size();
    long long int count[26];
    for (int i = 0; i < 26; i++) count[i] = 0;
    queue<char> q;
    string ans;
    for (long long int i = 0; i < n; i++) {
        cout << A[i] << endl;
        if (count[A[i] - 'a'] == 0) q.push(A[i]);
        count[A[i] - 'a']++;
        while (count[q.front() - 'a'] > 1) q.pop();
        q.empty() ? ans.push_back('#') : ans.push_back(q.front());
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}