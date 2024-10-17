#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> subMaxSums;


int solution(vector<vector<int>> triangle) {
    int depth = static_cast<int>(triangle.size());
    
    subMaxSums = vector<vector<int>>(depth, vector<int>(depth, 0));
    
    subMaxSums[0][0] = triangle[0][0];
    
    for(int d = 1;d < depth; ++d){
        for(int i = 0;i<=d;++i){
            if (0 == i){
                subMaxSums[d][i] = subMaxSums[d - 1][i] + triangle[d][i];     // 오른쪽
            }
            else if (d == i){
                subMaxSums[d][i] = subMaxSums[d - 1][i - 1] + triangle[d][i]; // 왼쪽
            }
            else{
                int v1 = subMaxSums[d - 1][i];    // 오른쪽
                int v2 = subMaxSums[d - 1][i - 1];// 왼쪽
                if (v1 > v2)
                    subMaxSums[d][i] = v1 + triangle[d][i];
                else
                    subMaxSums[d][i] = v2 + triangle[d][i];
            }
        }
    }
    
    return *max_element(subMaxSums[depth - 1].begin(), subMaxSums[depth - 1].end());
}