#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int  n ;
        cin >> n;
        string s;
        cin >> s;
        string res = "NO";
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                res="YES";
                break;
            }
        }
        cout << res << endl;
        
    }
    return 0;
}
