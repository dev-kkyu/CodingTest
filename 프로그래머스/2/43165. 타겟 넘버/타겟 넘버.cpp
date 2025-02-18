#include <string>
#include <vector>
#include <stack>

using namespace std;

void dfs(const vector<int>& numbers, int target, int nowIndex, int nowValue, int& count)
{
    if (nowIndex == numbers.size()){
        if (nowValue == target)
            ++count;
        return;
    }
    
    dfs(numbers, target, nowIndex + 1, nowValue + numbers[nowIndex], count);
    dfs(numbers, target, nowIndex + 1, nowValue - numbers[nowIndex], count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0, answer);
    
    return answer;
}