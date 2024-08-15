#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<int> dp{0, 1, 2, 3, 5, 8};
    dp.resize(n + 1);
    for(int i = 3; i < n + 1; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    
    return dp[n];
}