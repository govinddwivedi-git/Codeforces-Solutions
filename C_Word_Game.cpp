#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<vector<string>> a(3);
        map<string, int> m;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string x;
                cin >> x;
                m[x]++;
                a[i].push_back(x);
            }
        }

        for (int i = 0; i < 3; i++)
        {
            int ans = 0;
            for (auto x : a[i])
            {
                if (m[x] == 1)
                    ans += 3;
                else if (m[x] == 2)
                    ans++;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;

}