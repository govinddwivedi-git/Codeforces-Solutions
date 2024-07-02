#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p,q,r,s;
    cin >> p >> q >> r >> s;
    int maxi = max(max(p,max(q,r)),s);
    if(maxi==p) cout << maxi-s << " " << maxi-q << " " << maxi-r << endl;
    else if(maxi==q) cout << maxi-s << " " << maxi-p << " " << maxi-r << endl;
    else if(maxi==s) cout << maxi-p << " " << maxi-q << " " << maxi-r << endl;
    else if(maxi==r) cout << maxi-p << " " << maxi-q << " " << maxi-s << endl;
   
    return 0;
}