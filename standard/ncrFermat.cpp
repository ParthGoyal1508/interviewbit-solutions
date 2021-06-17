#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long int ll;

ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll modInverse(ll n)
{
    return power(n, mod - 2);
}

ll nCrModPFermat(ll n, ll r)
{
    if (r == 0)
        return 1;
    int fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod;
}

int main()
{
    int n = 5, r = 3;
    cout << nCrModPFermat(n, r) << endl;
    return 0;
}