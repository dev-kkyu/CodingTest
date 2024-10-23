#include <string>
#include <vector>
#include <numeric>

using namespace std;

void dfs(string str, const string& target, const vector<string>& words,
         const vector<bool>& visited, int depth, int& minCount)
{
    if (str == target){
        if (depth < minCount){
            minCount = depth;
            return;
        }
    }
    
    auto newVisited = visited;
    
    for(int i=0;i<words.size();++i){
        if (not newVisited[i]){
            int count = 0;
            for(int j = 0;j<str.size();++j){
                if (str[j] != words[i][j])
                    ++count;
            }
            if (1 == count){
                newVisited[i] = true;
                dfs(words[i], target, words, newVisited, depth + 1, minCount);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int minCount = numeric_limits<int>::max();
    vector<bool> visited(words.size(), false);
    
    dfs(begin, target, words, visited, 0, minCount);
    
    if (minCount == numeric_limits<int>::max())
        return 0;
    return minCount;
}
