class Solution {
public:
    using ll = long long;
    ll minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> strToId;
        int idCount = 0;

    
        for (const string& s : original) if (strToId.find(s) == strToId.end()) strToId[s] = idCount++;
        for (const string& s : changed) if (strToId.find(s) == strToId.end()) strToId[s] = idCount++;

        const ll INF = 1e15;
        vector<vector<ll>> dist(idCount, vector<ll>(idCount, INF));
        for (int i = 0; i < idCount; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = strToId[original[i]], v = strToId[changed[i]];
            dist[u][v] = min(dist[u][v], (ll)cost[i]);
        }

        for (int k = 0; k < idCount; k++) {
            for (int i = 0; i < idCount; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < idCount; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int n = source.length();
        vector<ll> dp(n + 1, INF);
        dp[0] = 0;

        set<int> uniqueLens;
        for (const string& s : original) uniqueLens.insert(s.length());

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

 
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

        
            for (int len : uniqueLens) {
                if (i + len > n) continue;
                string subS = source.substr(i, len);
                string subT = target.substr(i, len);

                if (strToId.count(subS) && strToId.count(subT)) {
                    int u = strToId[subS], v = strToId[subT];
                    if (dist[u][v] < INF) {
                        dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
