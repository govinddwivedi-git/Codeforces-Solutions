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

// Define cell structure
struct Cell {
    int distance, x, y;
    // Comparator for sorting by distance, then x, then y
    bool operator<(const Cell& other) const {
        if (distance != other.distance) return distance < other.distance;
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// Generate table cells using BFS
vector<Cell> generate_table_cells(int max_coord, int required_count) {
    set<pii> visited;
    set<pii> table_cells_set;
    vector<Cell> table_cells;
    queue<pair<int, pii>> q;
    q.push({0, {0, 0}});
    visited.insert({0, 0});
    
    int current_level_distance = -1;
    
    while (!q.empty()) {
        int d = q.front().first;
        if (d != current_level_distance) {
            if (!table_cells.empty() && table_cells.size() >= required_count)
                break;
            current_level_distance = d;
        }
        
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx <= max_coord && ny >= 0 && ny <= max_coord) {
                if (visited.find({nx, ny}) == visited.end() && (nx == 0 || ny == 0 || nx % 3 == 0 || ny % 3 == 0)) {
                    visited.insert({nx, ny});
                    q.push({d + 1, {nx, ny}});
                } else if (nx >= 1 && ny >= 1 && nx % 3 != 0 && ny % 3 != 0) {
                    if (table_cells_set.find({nx, ny}) == table_cells_set.end()) {
                        table_cells.push_back({d + 1, nx, ny});
                        table_cells_set.insert({nx, ny});
                    }
                }
            }
        }
    }
    
    sort(all(table_cells));
    return table_cells;
}

void solve(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    
    static vector<Cell> table_cells;
    if (table_cells.empty()) {
        // Generate table cells only once
        int max_coord = 10000;
        int required_count = 50000;
        table_cells = generate_table_cells(max_coord, required_count);
    }
    
    map<pii, int> table_occupancy;
    set<pii> occupied_cells;
    int pointer = 0;
    
    for (int ti : t) {
        while (pointer < table_cells.size()) {
            int a = table_cells[pointer].x;
            int b = table_cells[pointer].y;
            
            int x_table = (a - 1) / 3;
            int y_table = (b - 1) / 3;
            pii table_key = {x_table, y_table};
            int current_occupancy = table_occupancy[table_key];
            
            if (ti == 0) {
                if (current_occupancy == 0) {
                    cout << a << " " << b << endl;
                    table_occupancy[table_key] = 1;
                    occupied_cells.insert({a, b});
                    ++pointer;
                    break;
                }
                ++pointer;
            } else {
                if (occupied_cells.find({a, b}) == occupied_cells.end() && current_occupancy < 4) {
                    cout << a << " " << b << endl;
                    table_occupancy[table_key] = current_occupancy + 1;
                    occupied_cells.insert({a, b});
                    ++pointer;
                    break;
                }
                ++pointer;
            }
        }
    }
}

int32_t main(){
    fast

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}