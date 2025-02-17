#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int bookCount = citations.size();
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = 0; i < bookCount; ++i) {
        int h = i + 1;
        
        if (i == bookCount - 1 or citations[i + 1] <= h) {
            if (citations[i] >= h) {
                return h;
            }
        }
    }
    
    return 0;
}