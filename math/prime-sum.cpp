#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void sieveSundaram(long long int A)
{

    vector<bool> marked(A / 2 + 2);

    for (int i = 1; i <= (sqrt(A) - 1) / 2; i++)
        for (long long int j = (i * (i + 1)) << 1; j <= A / 2; j = j + 2 * i + 1)
            marked[j] = true;

    primes.push_back(2);

    for (int i = 1; i <= A / 2; i++)
        if (marked[i] == false)
            primes.push_back(2 * i + 1);
}

vector<int> findPrimes(int n)
{
    vector<int> ans;
    for (int i = 0; primes[i] <= n / 2; i++)
    {
        int diff = n - primes[i];
        if (binary_search(primes.begin(), primes.end(), diff))
        {
            ans.push_back(primes[i]);
            ans.push_back(n - primes[i]);
            return ans;
        }
    }
}

vector<int> primesum(int A)
{
    vector<int> ans = findPrimes(A);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    sieveSundaram(n);
    vector<int> ans = primesum(n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
