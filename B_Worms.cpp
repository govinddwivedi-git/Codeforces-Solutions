#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        int x;
        if (i == 0)
            cin >> arr[i];
        else
        {
            cin >> x;
            arr[i] = arr[i - 1] + x;
        }
    }
    int s = arr[n - 1];
    int has[s + 1];
    int k = 0;
    for (i = 0; i <= s; i++)
    {
        if (i <= arr[k])
            has[i] = k + 1;
        else
        {
            k++;
            has[i] = k + 1;
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int q;
        cin >> q;
        cout << has[q] << endl;
    }
}