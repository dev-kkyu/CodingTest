#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    
    int count = 0;
    
    while(routes.size()){
        int end = routes[0][1];
        
        for(int i=1;i<routes.size();++i){
            if(routes[i][0] <= end and routes[i][1] >= end){
                routes.erase(routes.begin() + i);
                --i;
            }
        }
        
        routes.erase(routes.begin());
        ++count;
    }
    
    return count;
}