#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int changeBinaryTransform(string& str)
{
    int zeroCount = 0;
    string newStr;
    for(char c : str){
        if (c == '1'){
            newStr += c;
        }
        else{
            ++zeroCount;
        }
    }
    
    int newSize = int(newStr.size());   // 1111 -> 4 -> 100
    
    newStr.clear();
    
    while(newSize){
        newStr = to_string(newSize % 2) + newStr;
        newSize /= 2;
    }
    str = newStr;
    return zeroCount;
}

vector<int> solution(string s) {
    int tryCount = 0;
    int zeroCount = 0;
    while(s != "1"){
        ++tryCount;
        zeroCount += changeBinaryTransform(s);
    }
    
    vector<int> answer{tryCount, zeroCount};
    return answer;
}