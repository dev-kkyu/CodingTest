#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void my_search(int from, vector<bool>& visited, int n, vector<vector<int>> computers)
{
    for(int i=0;i<n;++i){
        if (i != from){
            if (not visited[i]){
                if (computers[from][i]){
                    visited[i] = true;
                    my_search(i, visited, n, computers);
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    
    int answer = 0;
    for(int i=0;i<n;++i){
        if (visited[i])
            continue;
        
        visited[i] = true;
        my_search(i, visited, n, computers);
        i = -1;
        
        ++answer;
    }
    
    return answer;
}