#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(v[i]&1) cnt++;
    }
    if(cnt>=2){
        for(int i=0;i<n;i++){
            if((v[i]&1)==0){
                cout << i+1 << endl;
                break;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(v[i]&1){
                cout << i+1 << endl;
                break;
            }

        }
    }
    


    return 0;
}