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

int getPivotIndex(vector<int> &A) {
    int n = A.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end) {
        mid = start + (end - start) / 2;
        if ((mid < end) && (A[mid] > A[mid + 1])) {
            return mid;
        }
        if ((mid > start) && (A[mid - 1] > A[mid])) {
            return mid - 1;
        }
        if (A[start] >= A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return n;
}

int search(vector<int> &A, int B) {
    int pivotIndex = getPivotIndex(A);
    cout << "pivotIndex::" << pivotIndex << endl;
    int ans;
    if (B > A[0]) {
        auto it = lower_bound(A.begin(), A.begin() + pivotIndex, B);
        if (it != A.begin() + pivotIndex) {
            ans = it - A.begin();
            if (A[ans] != B) ans = -1;
        } else
            ans = -1;
    } else if (B < A[0]) {
        auto it = lower_bound(A.begin() + pivotIndex + 1, A.end(), B);
        if (it != A.end()) {
            ans = it - A.begin();
            if (A[ans] != B) ans = -1;
        } else
            ans = -1;
    } else {
        return 0;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int b;
    cin >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << search(arr, b) << endl;
    return 0;
}