#include <bits/stdc++.h>
using namespace std;
bool check(string &s){
    bool res = true;
    if((s[0]=='y' || s[0]=='Y') && (s[1]=='e' || s[1]=='E') && (s[2]=='s' || s[2]=='S')) res = true;
    else res = false;
    
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        bool ans = check(s);
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}