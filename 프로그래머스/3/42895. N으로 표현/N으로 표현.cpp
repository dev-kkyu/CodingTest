#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    vector<set<int>> dp(9);
    
    for(int i=1;i<=8;++i){
        int num = 0;
        for(int j=0;j<i;++j){
            num = num * 10 + N;
        }
        dp[i].insert(num);
    }
    
    for (int i=1;i<=8;++i){
        for(int j=1;j < i;++j)
        for(int n : dp[j]){
            for(int m : dp[i - j]){
                dp[i].insert(n + m);
                dp[i].insert(n - m);
                dp[i].insert(n * m);
                if (m != 0) dp[i].insert(n / m);
            }
        }
        if (dp[i].count(number) != 0)
            return i;
    }
    return -1;
}
