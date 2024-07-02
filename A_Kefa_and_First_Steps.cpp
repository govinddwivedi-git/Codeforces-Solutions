#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0, x=0, z=0, y=0, a=0;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x >= a)
            y++;
        else
            y = 1;
        if (y >= z)
            z = y;
        a = x;
    }
    cout << z << endl;
}