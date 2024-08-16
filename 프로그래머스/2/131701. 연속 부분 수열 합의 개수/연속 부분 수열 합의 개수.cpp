#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int size = elements.size();
    
    unordered_set<int> sets;
    
    for(int i = 1; i<= size;++i){       // 부분집합 1 ~ 5개 일때
        for(int j = 0; j < size; ++j){  // 각 부분집합별로 경우의 수 (항상 size)
            int sum = 0;
            for(int k = 0;k < i; ++k){  // 부분집합 개수에 따라서 합 구하기
                sum += elements[(k + j) % size];
            }
            sets.emplace(sum);
        }
    }
    
    return sets.size();
}