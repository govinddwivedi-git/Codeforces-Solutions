#include <bits/stdc++.h>
using namespace std;

string solve(int n, int k, int m, string s) {
    vector<string> possible_strings;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    do {
        possible_strings.push_back(alphabet.substr(0, n));
    } while (next_permutation(alphabet.begin(), alphabet.begin() + k));

    for (string p : possible_strings) {
        int i = 0;
        for (char c : s) {
            if (c == p[i]) {
                i++;
                if (i == n) break;
            }
        }
        if (i != n) return "NO\n" + p;
    }
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        cout << solve(n, k, m, s) << "\n";
    }
    return 0;
}
