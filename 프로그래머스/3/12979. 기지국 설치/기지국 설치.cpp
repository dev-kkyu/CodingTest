#include <iostream>
#include <vector>
#include <utility>
#include <list>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int effect = w * 2 + 1; // 영향을 끼치는 범위
    int startPos = 1;
    
    for(int s : stations){
        int left = s - w;   // 영향을 끼치는 위치
        int right = s + w;
        
        if (startPos < left){
            int dist = left - startPos; // 영향이 닿지 않는 거리
            answer += (dist + effect - 1) / effect;     // dist/effect 올림 연산
        }
        startPos = right + 1;
    }
    
    if (startPos <= n){
        int dist = n - startPos + 1; // 영향이 닿지 않는 거리
        answer += (dist + effect - 1) / effect;
    }
    
    return answer;
}