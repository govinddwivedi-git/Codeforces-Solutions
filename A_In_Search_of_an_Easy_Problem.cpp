#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    bool b=false;
    for(int i=0;i<n;i++){
        if(s.find(1)!=s.end()){
            b = true;
        }
    }
    if(b) cout << "HARD" << endl;
    else cout << "EASY" << endl;
    return 0;
}