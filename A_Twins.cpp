#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int sum = 0;
    for(int i=0;i<n;i++) sum += a[i];
    int rev = 0;
    int idx = 0;
    for(int i=n-1;i>=0;i--){
        sum -= a[i];
        rev += a[i];
        idx++;
        if(rev>sum){
            break;
        }
    }
    cout << idx << endl;

    return 0;
}