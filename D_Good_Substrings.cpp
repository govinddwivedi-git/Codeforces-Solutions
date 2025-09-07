#include <bits/stdc++.h>
using namespace std;

// Macros and constants
#define endl ("\n")
#define pi (3.141592653589)
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mini(a, b, c) min(c, min(a, b))
#define mini2(a, b, c, d) min(d, min(c, min(a, b))) 
#define rrep(i,s,n) for(int i=n-1;i>=s;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define scin(str) getline(cin, str)

// Debugging Macros
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl

// Aliases and Types
using vec = vector<int>;
using pii=pair<int,int>;
using mapi=map<int,int>;
using si=set<int>;

const int mod = 1e9+7;

// Global Constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int N=2e5+5;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }

    bool containsKey(char ch) {
        return (children[ch - 'a'] != nullptr);
    }

    TrieNode* get(char ch) {
        return children[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }

    void setEnd() {
        isEndOfWord = true;
    }

    bool isEnd() {
        return isEndOfWord;
    }

};

// class Trie {
// private:
//     TrieNode* root;
// public:
//     Trie() {
//         root = new TrieNode();
//     }

//     void insert(string word) {
//         TrieNode* node = root;
//         for (char ch : word) {
//             if (!node->containsKey(ch)) {
//                 node->put(ch, new TrieNode());
//             }
//             node = node->get(ch);
//         }
//         node->setEnd();
//     }

//     bool search(string word) {
//         TrieNode* node = root;
//         for (char ch : word) {
//             if (!node->containsKey(ch)) {
//                 return false;
//             }
//             node = node->get(ch);
//         }
//         return node->isEnd();
//     }

//     bool startsWith(string prefix) {
//         TrieNode* node = root;
//         for (char ch : prefix) {
//             if (!node->containsKey(ch)) {
//                 return false;
//             }
//             node = node->get(ch);
//         }
//         return true;
//     }
// };



void solve(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    unordered_map<char, int> mp;
    for(int i = 0; i < 26; i++) mp['a' + i] = (t[i] == '1');
    int n = s.size();

    TrieNode* root = new TrieNode();


    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int bad = 0;
        TrieNode *node = root;
        for(int j = i; j < n; j++) {
            if(mp[s[j]] == 0) bad++;
            if(bad > k) break;
            if(!node->containsKey(s[j])) {
                node->put(s[j], new TrieNode());
                cnt++;
            }
            node = node->get(s[j]);
        }
    }

    cout << cnt << endl;

    
}


int32_t main(){
    fast

    int t = 1;
    while(t--){
        
        
        solve();


    }
    return 0;
}