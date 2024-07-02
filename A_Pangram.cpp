#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set <char> st;
    for(int i=0;i<s.size();i++){
        s[i]=tolower(s[i]);
        st.insert(s[i]);
    }
    if(st.size()==26) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}