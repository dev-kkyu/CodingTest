#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s)
        return {-1};
    
    vector<int> answer;
    
    answer.resize(n, 0);
    
    int baseNum = s / n;
    for(auto& num : answer)
        num = baseNum;
    for(int i = 0; i < s % n; ++i){
        ++answer[answer.size() - 1 - i];
    }
    
    return answer;
}