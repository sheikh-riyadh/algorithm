#include <bits/stdc++.h>
using namespace std;

const long long int N = 1e6 + 5;
long long int dp[N];

long long int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    long long int result = fibo(n - 1) + fibo(n - 2);
    dp[n] = result;
    return result;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n);
    return 0;
}