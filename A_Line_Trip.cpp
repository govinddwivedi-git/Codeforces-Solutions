#include <bits/stdc++.h>
using namespace std;


int main(){


    int t = 1;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vector <int> v(n);
        vector <int> diff(n+1);
        for(int i=0; i<n; i++) cin >> v[i];
        diff[0] = v[0];
        diff[n] = 2*(x-v[n-1]);
        for(int i=1; i<n; i++){
            diff[i]=v[i]-v[i-1];
        }
        int maxi = diff[0];
        for(int i=0;i<n+1;i++){
            maxi = max(maxi,diff[i]);
        }
        cout << maxi << endl;
        
    }
    return 0;
}