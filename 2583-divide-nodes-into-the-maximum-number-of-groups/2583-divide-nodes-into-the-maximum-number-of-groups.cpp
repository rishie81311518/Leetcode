class Solution {
public:
    vector<vector<int>> graph;
    vector<int> component;
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        graph.resize(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        component.resize(n + 1, -1);
        vector<vector<int>> components;
        
        for (int i = 1; i <= n; i++) {
            if (component[i] == -1) {
                components.push_back({});
                dfs(i, components.size() - 1, components.back());
            }
        }
        
        int result = 0;
        for (const auto& comp : components) {
            int maxGroups = 0;
            for (int node : comp) {
                int groups = bfs(node);
                if (groups == -1) return -1;
                maxGroups = max(maxGroups, groups);
            }
            result += maxGroups;
        }
        
        return result;
    }
    
private:
    void dfs(int node, int compId, vector<int>& comp) {
        component[node] = compId;
        comp.push_back(node);
        for (int neighbor : graph[node]) {
            if (component[neighbor] == -1) {
                dfs(neighbor, compId, comp);
            }
        }
    }
    
    int bfs(int start) {
        queue<int> q;
        q.push(start);
        vector<int> distance(graph.size(), -1);
        distance[start] = 0;
        int maxDist = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[node] + 1;
                    maxDist = max(maxDist, distance[neighbor]);
                    q.push(neighbor);
                } else if (abs(distance[neighbor] - distance[node]) != 1) {
                    return -1;
                }
            }
        }
        
        return maxDist + 1;
    }
};
