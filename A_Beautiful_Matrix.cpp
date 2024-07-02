#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[5][5];
    int idx = -1;
    int jdx = -1;
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                idx = i;
                jdx = j;
            }
        }
    }
    if(idx > 2) idx = idx-2;
    else idx = 2 - idx;
    if(jdx > 2) jdx = jdx - 2;
    else jdx = 2 - jdx;

    cout << idx + jdx << endl;
    return 0;
}