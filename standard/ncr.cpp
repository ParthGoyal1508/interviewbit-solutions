#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll printNcR(ll n, ll r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

int main()
{
    int n = 5, r = 3;
    cout << printNcR(n, r) << endl;
    return 0;
}