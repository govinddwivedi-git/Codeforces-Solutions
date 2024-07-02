#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[v[i]]++;
    }

    int res = 0;
    res += m[4];
    int t = min(m[3],m[1]);
    res += t;
    m[3] -= t;
    m[1] -= t;
    res += m[3];
    res += m[2]/2;
    m[2] %= 2;
    if(m[2]==1){ 
        res++;
        m[1] = max(m[1]-2,0LL);
    }
    if(m[1]) res += ceil(m[1]/4.0);
    cout << res << endl;


    

    
    

    return 0;
}