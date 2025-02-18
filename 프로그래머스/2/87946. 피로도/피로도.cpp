#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> index(dungeons.size());
    
    iota(index.begin(), index.end(), 0);
    
    priority_queue<int> explorer;
    
    do{
        int count = 0;
        int hp = k;
        for(const int idx : index){
            if (hp < dungeons[idx][0])
                break;
            ++count;
            hp -= dungeons[idx][1];
        }
        
        explorer.push(count);
        
    } while (next_permutation(index.begin(), index.end()));
    
    return explorer.top();
}