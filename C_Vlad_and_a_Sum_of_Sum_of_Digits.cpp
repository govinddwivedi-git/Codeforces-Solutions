#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const long long M = 1e9 + 7;
const long long N = 200000;
long long dig[N] = {0};

int sum(long long n)
{
    long long sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void prefix()
{
    for (long long i = 1; i <= N; i++)
    {
        dig[i] = dig[i - 1] + sum(i);
    }
}

int digitsum(long long x)
{
    if (x > N)
        return -1; 
    return dig[x];
}
void solve()
{
long long x;
        cin >> x;
        cout << digitsum(x) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prefix(); 

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}