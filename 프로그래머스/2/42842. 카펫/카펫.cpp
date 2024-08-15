#include <string>
#include <vector>

using namespace std;

bool isValidBrownColor(int width, int height, int brown)
{
    return (width * 2 + height * 2 + 4) == brown;
}

vector<int> solution(int brown, int yellow) {
    // 노란색의 수가 될 수 있는 가로/세로 구하기
    // 해당 경우의 수에서 갈색의 수가 맞는 단 하나의 경우 구하기
    
    // 노란색의 약수 구하기 문제...
    
    vector<int> divisor;
    divisor.reserve(yellow / 2);
    for(int i = 1; i * i <= yellow; ++i){
        if (yellow % i == 0)
            divisor.push_back(i);
    }
    // divisor은 세로..
    
    vector<int> answer;
    
    for(int height : divisor){
        if (isValidBrownColor(yellow / height, height, brown)){
            answer = {yellow / height + 2, height + 2};
            break;
        }
    }
    
    return answer;
}