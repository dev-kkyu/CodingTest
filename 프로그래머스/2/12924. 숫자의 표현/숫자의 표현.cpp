#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    if (1 == n)
        return 1;
    
    int endNum = static_cast<int>(ceil(n / 2.0));
    
    int count = 0;
    
    for(int i = 1; i <= endNum; ++i){
        
        int sum = 0;
        for(int j = i; j <= endNum; ++j){
            sum += j;
            if (sum >= n){
                if (n == sum)
                    ++count;
                break;
            }
        }
    }
    
    return count + 1;
}