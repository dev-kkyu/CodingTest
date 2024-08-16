#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<string> strs;
    
    strs.reserve(words.size());
    
    int invalidIndex = -1;
    for(const auto& w : words){
        bool flag = false;
        // 중복 검사
        for(int i=0;i<strs.size();++i){
            if (strs[i] == w){    // 같은 단어??
                flag = true;
                break;
            }
        }
        // 끝단어 검사
        if (not strs.empty()){
            if (strs.back().back() != w.front())
                flag = true;
        }
        if (flag){
            invalidIndex = strs.size();
            break;
        }
        
        strs.push_back(w);
    }

    vector<int> answer;
    
    if (invalidIndex < 0){
        answer = {0, 0};
    }
    else{
        answer = {invalidIndex % n + 1, invalidIndex / n + 1};
    }

    return answer;
}