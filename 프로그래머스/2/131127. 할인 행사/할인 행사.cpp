#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> want_map;
    
    for(int i=0;i<want.size();++i){
        want_map[want[i]] = number[i];
    }
    
    int retVal = 0;
    for(int i=0;i<discount.size() - (10 - 1);++i){  // 10개씩 본다
        auto copy_map = want_map;
        for(int j=i;j< i + 10;++j){
            if (copy_map.count(discount[j])){
                if (--copy_map[discount[j]] == 0){
                    copy_map.erase(discount[j]);
                }
            }
        }
        if (copy_map.size() == 0)
            ++retVal;
    }
    return retVal;
}