#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << n << " ";
    for(int i=2;i<=n;i++){
        while(n%i==0){
            n/=i;
            cout<<n<<" ";
        }
    }

    return 0;
}