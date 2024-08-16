#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void my_search(set<int>& sets, int index, int n, const vector<vector<int>>& computers)
{
    sets.erase(index);
    for(int i = 0; i < n; ++i){
        if (i != index and 1 == computers[index][i]){
            if (sets.find(i) != sets.end()){
                my_search(sets, i, n, computers);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    set<int> nums;
    for(int i=0;i<n;++i)
        nums.insert(i);

    int answer = 0;
    while(nums.size() > 0){
        my_search(nums, *nums.begin(), n, computers);
        ++answer;
    }
    return answer;
}