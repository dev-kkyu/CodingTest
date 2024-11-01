#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    set<pair<int, int>> obs;
    
    for(const auto& v : puddles){
        obs.insert({v[0] - 1, v[1] - 1});
    }
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    
    for(int i = 0;i < m; ++i){
        for(int j=0;j < n; ++j){
            if (j > 0 and obs.count({i, j - 1}) == 0)  // 위
                dp[i][j] = dp[i][j - 1] % 1'000'000'007;
            if (i > 0 and obs.count({i - 1, j}) == 0)  // 왼
                dp[i][j] += dp[i - 1][j] % 1'000'000'007;
        }
    }
    
    return dp[m - 1][n - 1] % 1'000'000'007;
}