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
    TrieNode* links[2];
    int cnt;
    bool isEnd ;

    TrieNode() {
        links[0] = links[1] = NULL;
        isEnd = false;
        cnt = 0;
    }

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }
    TrieNode* get(int bit) {
        return links[bit];
    }
    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }
    void setEnd() {
        isEnd = true;
    }
    bool isEndNode() {
        return isEnd;
    }
    void unsetEnd() {
        isEnd = false;
    }

};


class Trie {

    private:
    TrieNode* root;

    public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
            node->cnt++;
        }
        node->setEnd();
    }
    
    void remove(int num) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                return;
            }
            node = node->get(bit);
            node->cnt--;
        }
        node->unsetEnd();    
    }
    
    int findMaxXor(int num) {
        int ans = 0;
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit) && node->get(1 - bit)->cnt > 0) {
                ans = ans | (1 << i);
                node = node->get(1 - bit);
            }
            else node = node->get(bit);
        }
        return ans;
    }

};



void solve(){
    int q;
    cin >> q;

    Trie trie;
    trie.insert(0);

    for(int i = 0; i < q; i++) {
        char type;
        int num;
        cin >> type >> num;
        if (type == '+') trie.insert(num);
        else if (type == '-') trie.remove(num);
        else cout << trie.findMaxXor(num) << endl;

    }

}


int32_t main(){
    fast

    int t = 1;
    // cin >> t;
    while(t--){
        
        
        solve();


    }
    return 0;
}