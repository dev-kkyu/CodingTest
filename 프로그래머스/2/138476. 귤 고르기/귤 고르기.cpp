#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> maps;
    for(int n : tangerine)
        ++maps[n];
    
    map<int, int> reverseMap;
    for(auto m : maps)
        ++reverseMap[m.second];
    
    int sum = 0;
    int kind = 0;
    for(auto itr = reverseMap.rbegin();itr!=reverseMap.rend();++itr){
        cout << "["<<itr->first<<":"<<itr->second<<"]\n";
        for(int i=0;i<itr->second;++i){
            sum += itr->first;
            ++kind;
            if (sum >= k)
                break;
        }
        if (sum >= k)
            break;
    }
    return kind;
}