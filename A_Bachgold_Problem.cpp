#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << n/2 << endl;
    //vector<int> v(n/2);
    for(int i=0; i<n/2-1; i++){
        cout << 2 <<" ";
    }
    if(n&1) cout << 3 << endl;
    else cout << 2 << endl;

    
    return 0;
}