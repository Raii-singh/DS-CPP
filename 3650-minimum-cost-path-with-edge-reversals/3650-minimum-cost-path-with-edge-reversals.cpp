class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using ll = long long;
        const ll INF = LLONG_MAX;

        vector<vector<pair<int,int>>> adj(n);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});       // normal
            adj[v].push_back({u, 2 * w});   // reversed using switch
        }

        // Dijkstra
        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] == INF ? -1 : dist[n-1];
    }
};
