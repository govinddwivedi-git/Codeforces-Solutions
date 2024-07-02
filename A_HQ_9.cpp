#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    if(s.find('H')!= string::npos) cout << "YES" << endl;
    else if (s.find('Q') != string::npos) cout << "YES" << endl;
    else if (s.find('9') != string::npos) cout << "YES" << endl;
    //else if (s.find('+') != string::npos) cout << "YES" << endl;
    else cout<<"NO" << endl; 
    return 0;
}