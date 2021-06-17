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

typedef struct Interval {
    int start;
    int end;
} Interval;

bool comparefunc(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), comparefunc);
    int n = A.size();
    vector<Interval> ans;
    ans.push_back(A[0]);
    for (int i = 1; i < n; i++) {
        Interval f = ans.back();
        Interval s = A[i];
        if (s.start <= f.end) {
            ans.pop_back();
            Interval temp;
            temp.start = min(f.start, s.start);
            temp.end = max(f.end, s.end);
            ans.push_back(temp);
        } else {
            ans.push_back(s);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].start << " " << ans[i].end << endl;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<Interval> arr;
    for (int i = 0; i < n; i++) {
        Interval it;
        cin >> it.start >> it.end;
        arr.push_back(it);
    }
    arr = merge(arr);
    return 0;
}