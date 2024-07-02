#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int c1 = count(s.begin(),s.end(),'7');
    int c2 = count(s.begin(),s.end(),'4');

    if(c1+c2 == 7 || c1+c2==4) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}