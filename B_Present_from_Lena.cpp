#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        for(int sp=0;sp<=n-i-1;sp++){
            cout << "  ";
        }
        for(int j=0;j<=i;j++){
            if(i==0) cout << j;
            else cout << j << " ";
        }
        for(int m=i-1;m>=0;m--){
            if(m==0) cout << m;
            else cout << m << " ";
        }
        cout << endl;
    }
    for(int i = n-1 ; i>=0 ;i--){
        for(int sp =i; sp<n; sp++){
            cout << "  ";
        }
        for(int j=0;j<=i;j++){
            if(i==0) cout << j;
            else cout << j << " ";
        } 
        for(int m=i-1;m>=0;m--){
            if(m==0) cout << m;
            else cout << m << " ";
        }
        
        cout << endl;
    }
    return 0;
}