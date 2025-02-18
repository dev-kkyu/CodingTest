#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int complete = 0;
    
    for(int day = 1; ; ++day){
        if (progresses[complete] + speeds[complete] * day >= 100){
            // 배포 준비 완료
            int count = 1;
            while(true){
                if (complete + count >= progresses.size())
                    break;
                if (progresses[complete + count] + speeds[complete + count] * day < 100)
                    break;
                ++count;
            }
            answer.push_back(count);
            complete += count;
        }
        
        if (complete >= progresses.size())
            break;
    }
    
    return answer;
}