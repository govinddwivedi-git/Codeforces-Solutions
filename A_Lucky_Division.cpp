#include <bits/stdc++.h>
using namespace std;

int Lucky(int n){
    while(n){
        int d = n%10;
        if(!( d==4 || d==7 )) return 0;
        n /= 10;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int flag = 0;
    for(int i=1; i*i <= n; i++){
        if((n%i) == 0){
            if(Lucky(i) || Lucky(n/i)) flag = 1;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}