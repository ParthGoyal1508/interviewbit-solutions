#include <bits/stdc++.h>
using namespace std;

long long int printNcR(int n, int r)
{

    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            long long m = __gcd(p, k);

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

int uniquePaths(int A, int B)
{
    return printNcR(A+B-2, A-1);
}

int main()
{
    int A, B;
    cin >> A >> B;
    int a = uniquePaths(A, B);
    cout << a << endl;
    return 0;
}
