#include <vector>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<unordered_set<int>> nodes(n + 1);
    
    for(const auto& v : edge){
        nodes[v[0]].insert(v[1]);
        nodes[v[1]].insert(v[0]);
    }
    
    vector<bool> visited(n + 1, false);
    
    map<int, int> distance;
    
    queue<pair<int, int>> bfs;  // node, depth
    bfs.push({1, 0});
    visited[1] = true;
    
    while(not bfs.empty()){
        int node = bfs.front().first;
        int depth = bfs.front().second;
        bfs.pop();
        
        ++distance[depth];
        
        for(int n : nodes[node]){
            if (not visited[n]){
                visited[n] = true;
                bfs.push({n, depth + 1});
            }
        }
    }
    
    return distance.rbegin()->second;
}