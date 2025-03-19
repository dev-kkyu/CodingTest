#include <iostream>
#include <vector>
#include <utility>
#include <list>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    list<pair<int, int>> remainAparts;    // 전파가 안닿는 아파트의 시작~끝 리스트

    int startPos = 1;
    
    for(int s : stations){
        int left = s - w;   // 영향을 끼치는 범위
        int right = s + w;
        
        if (left < 1)
            left = 1;
        if (right > n)
            right = n;
        
        if (startPos < left){
            remainAparts.push_back({startPos, left - 1});
        }
        startPos = right + 1;
    }
    
    if (startPos <= n){
        remainAparts.push_back({startPos, n});
    }
    
    int answer = 0;
    
    for (const auto& remain : remainAparts){
        int dist = remain.second - remain.first + 1;
        int effect = w * 2 + 1;
        answer += (dist + effect - 1) / effect;
    }
    
    return answer;
}