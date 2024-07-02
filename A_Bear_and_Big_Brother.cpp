#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> a >> b;
    int cnt = 0;
    while(a<=b){
        a = 3*a;
        b =b*2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}