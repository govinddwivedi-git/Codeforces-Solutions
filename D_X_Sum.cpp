#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> board(n, vector<int>(m));
        vector<int> diag1(400), diag2(400);

        // Reading the board values and populating the diagonals' sum
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> board[i][j];
                diag1[i - j + m] += board[i][j];
                diag2[i + j] += board[i][j];
            }
        }

        // Finding the maximum sum of diagonals
        int maxSum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxSum = max(maxSum, diag1[i - j + m] + diag2[i + j] - board[i][j]);
            }
        }

        cout << maxSum << endl;
    }
    return 0;
}
