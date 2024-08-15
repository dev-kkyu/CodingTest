#include <string>
#include <vector>

using namespace std;

vector<int> candidate{0, 1, 1, 2, 3, 5, 8};

int solution(int n) {    
    candidate.resize(n + 1);
    
    for(int i = 2; i < n + 1; ++i) {
        candidate[i] = candidate[i - 1] % 1234567 + candidate[i - 2] % 1234567;
        candidate[i] %= 1234567;
    }
    
    return candidate[n];
}
