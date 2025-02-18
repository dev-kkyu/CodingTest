#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    for(auto& city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
    }
    
    if (0 == cacheSize)
        return cities.size() * 5;
    
    list<pair<string, int>> cityList;   // 이름, 히트시간
    
    int totalExecTime = 0;
    
    for(int i = 0; i < cities.size(); ++i){
        bool isFind = false;
        for(auto& city : cityList){         // cache hit
            if (city.first == cities[i]){
                isFind = true;
                city.second = i;
                break;
            }
        }
        if (isFind){
            // cache hit
            totalExecTime += 1;
            continue;
        }
        
        // cache miss;
        totalExecTime += 5;
        if (cityList.size() < cacheSize) { // 단순 삽입
            cityList.push_back({cities[i], i});
        }
        else {   // 가장 오래된 것 교체
            auto itr = min_element(cityList.begin(), cityList.end(),
                                   [](const auto& a, const auto& b){
                                       return a.second < b.second;
                                   });
            itr->first = cities[i];
            itr->second = i;
        }
    }
    
    return totalExecTime;
}