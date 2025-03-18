#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    std::sort(A.begin(), A.end(), greater<>());
    std::sort(B.begin(), B.end());
    
    int score = 0;
    
    for(int i=0, j = A.size() - 1; i<A.size(); ++i){
        if (A[i] < B[j]){
            ++score;
            --j;
        }
    }
    
    return score;
}