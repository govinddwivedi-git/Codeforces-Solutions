class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int source) {
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
    
        while (!pq.empty()) {
            int distance = pq.top().first;
            int u = pq.top().second;
            pq.pop();
    
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
    
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    
        return dist;
    }

    int dfs(vector<vector<pair<int, int>>>& adj, int node, vector<int>& dp) {
        if(node == 0) return 0;
        if(dp[node] != -1) return dp[node];
        
        int minMaxWeight = INT_MAX;
        for(auto& edge : adj[node]) {
            int nextNode = edge.first;
            int weight = edge.second;
            
            // Get minimum max weight path to node 0
            int pathWeight = dfs(adj, nextNode, dp);
            if(pathWeight != INT_MAX) {
                // Maximum weight in this path is max of current edge and path
                int maxInPath = max(weight, pathWeight);
                // Take minimum among all possible paths
                minMaxWeight = min(minMaxWeight, maxInPath);
            }
        }
        
        return dp[node] = minMaxWeight;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // Check threshold condition and build graph
        vector<int> outDegree(n, 0);
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& e : edges) {
            outDegree[e[0]]++;
            if(outDegree[e[0]] > threshold) return -1;
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        // Check reachability using Dijkstra
        vector<vector<pair<int, int>>> revAdj(n);
        for(auto& e : edges) {
            revAdj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dist = dijkstra(n, revAdj, 0);
        for(int d : dist) {
            if(d == INT_MAX) return -1;
        }
        
        // Find minimum maximum weight paths
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        int result = 0;
        for(int i = 1; i < n; i++) {
            int weight = dfs(adj, i, dp);
            if(weight == INT_MAX) return -1;
            result = max(result, weight);
        }
        
        return result;
    }
};