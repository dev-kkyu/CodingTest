#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;    
    
    vector<int> dp(money.size(), 0);

    // 0번, 2번 집으로 시작 ->마지막 집 X
    dp[0] = money[0];
    dp[1] = dp[0];
    for(int i=2;i<dp.size();++i){
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }
    
    answer = max(dp[dp.size() - 2], dp[dp.size() - 3]);
    
    dp.clear();
    dp.resize(money.size(), 0);
    
    // 1번 집으로 시작
    dp[1] = money[1];
    for(int i=2;i<dp.size();++i){
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }
    
    answer = max(answer, max(dp[dp.size() - 1], dp[dp.size() - 2]));
    
    return answer;
    
    
}