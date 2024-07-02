#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure to represent a tree node
struct TreeNode {
    int value;
    vector<int> children;
};

// Function to find the path from root to a given node
void findPath(int u, int parent, vector<int>& path, vector<TreeNode>& tree) {
    path.push_back(tree[u].value);
    for (int child : tree[u].children) {
        if (child != parent) {
            findPath(child, u, path, tree);
        }
    }
}

// Function to process queries
void processQueries(int q, vector<TreeNode>& tree) {
    while (q--) {
        int u1, v1, u2, v2, k;
        cin >> u1 >> v1 >> u2 >> v2 >> k;
        u1--; v1--; u2--; v2--; // Adjusting index to 0-based

        vector<int> path1, path2;
        findPath(u1, -1, path1, tree);
        findPath(u2, -1, path2, tree);

        unordered_map<int, int> freq1, freq2;
        for (int val : path1) freq1[val]++;
        for (int val : path2) freq2[val]++;

        vector<int> diff;
        for (auto& p : freq1) {
            if (freq2[p.first] != p.second) {
                diff.push_back(p.first);
            }
        }

        for (auto& p : freq2) {
            if (freq1.find(p.first) == freq1.end()) {
                diff.push_back(p.first);
            }
        }

        sort(diff.begin(), diff.end());
        int z = min((int)diff.size(), k);
        cout << z;
        for (int i = 0; i < z; i++) {
            cout << " " << diff[i];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].value;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Adjusting index to 0-based
        tree[u].children.push_back(v);
        tree[v].children.push_back(u);
    }

    int q;
    cin >> q;
    processQueries(q, tree);

    return 0;
}

