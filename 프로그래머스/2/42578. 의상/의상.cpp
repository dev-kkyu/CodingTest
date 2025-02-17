#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    // key : 의상종류, value : 갯수
    unordered_map<string, int> hash;
    
    for(const auto& cloth : clothes){
        ++hash[cloth[1]];
    }
    
    int totalSum = 1;

    for(const auto& hs : hash){
        totalSum *= hs.second + 1;
    }
    
    return totalSum - 1;
}