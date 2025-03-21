#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = 1'000'000'000LL * n;
    
    while(left < right){
        long long mid = (left + right) / 2;
        
        long long total = 0;
        for(int time : times){
            total += mid / time;
        }
        
        if (total < n)
            left = mid + 1;
        else
            right = mid;
    }
    
    return right;
}