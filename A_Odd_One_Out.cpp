#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int n = 3;

    int t;
    cin >> t;
    while(t--){
        int arr[n];
        int ans = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            ans^=arr[i];
        } 
        cout << ans << endl;
        
    }
    return 0;
}