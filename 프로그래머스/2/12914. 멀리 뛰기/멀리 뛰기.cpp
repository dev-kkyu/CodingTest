#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<int> fibo{1, 2, 3, 5, 8};
    fibo.resize(n + 1);
    for(int i=2;i<n + 1; ++i){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= 1234567;
    }
    
    return fibo[n - 1];
}