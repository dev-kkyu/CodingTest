#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    std::priority_queue<int> p_queue{works.begin(), works.end()};
    
    for(int i=0;i<n;++i){
        if (p_queue.empty())
            break;
        int newVal = p_queue.top();
        p_queue.pop();
        if (1 != newVal)
            p_queue.push(newVal - 1);
    }
    
    long long retVal = 0;
    while(not p_queue.empty()){
        int value = p_queue.top();
        p_queue.pop();
        retVal += value * value;
    }
    return retVal;
}