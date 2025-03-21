#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int>> foodList;
    foodList.reserve(food_times.size());
    
    for(int i=0;i<food_times.size();++i){
        foodList.push_back({i, food_times[i]});
    }
    
    // 시간순으로 정렬
    sort(foodList.begin(), foodList.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    });
    
    long long count = k;
    long long removeCount = 0;      // 음식마다 일괄로 빼줄 갯수
    for(int i=0;i<foodList.size();++i){
        int subRemoveCount = foodList[i].second - removeCount;  // 현재 루프에서 음식마다 감소되는 count
                                                                // 이미 감소된 것 X
        if (subRemoveCount * (foodList.size() - i) > count)     // 현재 루프에서 감소될 수 있는지
            break;
        count -= subRemoveCount * (foodList.size() - i);
        removeCount += subRemoveCount;
    }
    for(auto& food : foodList){
        food.second -= removeCount;
    }

    foodList.erase(remove_if(foodList.begin(), foodList.end(),
                             [](const pair<int, int>& a){
                                 return a.second <= 0;
    }), foodList.end());
    
    if (foodList.size() == 0)
        return -1;
    
    // 다시 음식순으로 정렬
    sort(foodList.begin(), foodList.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.first < b.first;
    });
    
    return foodList[count % foodList.size()].first + 1;
}