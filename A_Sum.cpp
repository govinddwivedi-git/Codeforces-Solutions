#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a+b==c || b+c==a || a+c==b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}