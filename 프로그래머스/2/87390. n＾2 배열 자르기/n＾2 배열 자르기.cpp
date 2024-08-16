#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long startX = left / n;
    long long endX = right / n;
    
    for(long long i = startX; i <= endX; ++i){
        for (long long j = 0; j < n; ++j){
            if (i * n + j >= left and i * n + j <= right){
                int value;
                if (j + 1 < i + 1)
                    value = i + 1;
                else
                    value = j + 1;
                answer.emplace_back(value);
            }
        }
    }
    
    return answer;
}
