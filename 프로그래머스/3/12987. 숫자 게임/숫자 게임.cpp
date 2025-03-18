#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    std::sort(A.begin(), A.end(), greater<>());
    std::sort(B.begin(), B.end());
    
    int score = 0;
    
    for(int i=0;i<A.size();++i){
        if (A[i] < B.back()){
            ++score;
            B.erase(B.end() - 1);
        }
    }
    
    return score;
}