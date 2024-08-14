#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int solution(int n) {
    int copyNum = n;
    
    bitset<32> bit(n);
    string binaryNum = bit.to_string();
    
    int oneCount = 0;
    for_each(binaryNum.begin(), binaryNum.end(), [&oneCount](char c){
        if ('1' == c)
            ++oneCount;
    });
    

    int answer = n + 1;
    while (true){
        bitset<32> answerBit(answer);
        string answerBinaryNum = answerBit.to_string();
        int answerOneCount = 0;
        for_each(answerBinaryNum.begin(), answerBinaryNum.end(), [&answerOneCount](char c){
            if ('1' == c)
                ++answerOneCount;
        });
        if (oneCount == answerOneCount)
            break;
        ++answer;
    }

    return answer;
}