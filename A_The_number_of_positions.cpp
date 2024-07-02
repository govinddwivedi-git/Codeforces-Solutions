
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b;
    cin >> n >> a >> b;
    if(n-a>=b+1) cout << b+1;
    else cout << n-a;
    
    return 0;
}