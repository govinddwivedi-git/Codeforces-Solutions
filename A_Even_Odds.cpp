#include <bits/stdc++.h>
using namespace std;
#define int long long

int_fast32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    n = k-++n/2;
    cout << (n>0?2*n:2*k-1);

    return 0;
}
