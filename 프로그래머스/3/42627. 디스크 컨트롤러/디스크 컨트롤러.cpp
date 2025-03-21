#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

// 작업번호, 요청시각, 소요시간
struct WorkCompare{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        if (a[2] == b[2]){
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] > b[1];
        }
        return a[2] > b[2];
    }
};

int solution(vector<vector<int>> jobs) {
    deque<vector<int>> notArrivedWorks;
    for(int i=0;i<jobs.size();++i){
        notArrivedWorks.push_back({i, jobs[i][0], jobs[i][1]});
    }
    sort(notArrivedWorks.begin(), notArrivedWorks.end(),
         [](const vector<int>& a, const vector<int>& b){
             return a[1] < b[1];    // 요청시간 순으로 오름차순
         });
    
    priority_queue<vector<int>, vector<vector<int>>, WorkCompare> arrivedWorks;
    vector<int> runWorks;
    int totalTurnTime = 0;
    for(int time = 0;
        runWorks.size() != 0 or notArrivedWorks.size() != 0 or arrivedWorks.size() != 0;
        ++time){
        while(notArrivedWorks.size() != 0) {
            auto work = notArrivedWorks.front();    // 작업을 한번 살펴본다
            if (work[1] <= time){
                arrivedWorks.push(work);
                notArrivedWorks.pop_front();
            }
            else break;
        }
        if (0 != runWorks.size()){  // 진행중인 작업이 있다면
            --runWorks[2];  // 소요시간 감소
            if (0 == runWorks[2]){  // 작업이 완료되면 제거해준다
                totalTurnTime += time - runWorks[1];
                runWorks.clear();
            }
        }
        if (0 == runWorks.size()){  // 진행중인 작업이 없다면
            if (arrivedWorks.size() != 0){      // 다음 작업을 뽑아온다.
                runWorks = arrivedWorks.top();
                arrivedWorks.pop();
            }
        }
    }
    
    return totalTurnTime / jobs.size();
}