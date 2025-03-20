#include <string>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    unordered_map<long long, long long> stayRooms;  // key : 방번호, value : 다음방번호
    
    vector<long long> answer;
    answer.reserve(room_number.size());
    
    for(const auto& room : room_number){
        list<long long> updateRooms;
        long long findValue = room;
            
        while (stayRooms.find(findValue) != stayRooms.end()){ // 빈공간 찾기
            updateRooms.push_back(findValue);
            findValue = stayRooms[findValue];
        }
        stayRooms[findValue] = findValue + 1;       // 삽입, 다음공간 넣어주기. 뒤에 더 있다면 다음번에 업데이트 예정
        answer.push_back(findValue);
            
        for(const auto& update : updateRooms){      // 지나쳐온 값들 모두 업데이트 해주기
            stayRooms[update] = stayRooms[findValue];
        }
    }

    return answer;
}