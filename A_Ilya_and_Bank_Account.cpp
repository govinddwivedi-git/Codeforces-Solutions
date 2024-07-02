#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if(n>0) cout << n << endl;
    else{
        string s = to_string(abs(n));
        string s1 = s;
        string s2 = s;
        s1.erase(s1.end()-2,s1.end()-1);
        s2.erase(s2.end()-1,s2.end());
        if(stoi(s1)>stoi(s2)) cout << "-" << s2 << endl;
        else if(stoi(s1)==0 || stoi(s2)==0) cout << 0 << endl;
        else cout << "-" << s1 << endl;
    }

    return 0;
}