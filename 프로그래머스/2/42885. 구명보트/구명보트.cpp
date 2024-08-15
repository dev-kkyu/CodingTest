#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    list<int> weights{people.begin(), people.end()};
    
    vector<int> boat;
    
    while(weights.size() > 0){
        int sum = weights.back();
        weights.pop_back();
        if (weights.size() > 0 and sum + weights.front() <= limit) {
            sum += weights.front();
            weights.pop_front();
        }
        boat.push_back(sum);
    }
    
    return boat.size();
}