#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> my_queue;
    
    for(const auto& op : operations){
        stringstream ss{op};
        char cmd;
        int value;
        ss >> cmd >> value;
        if (cmd == 'I'){
            my_queue.insert(value);
        }
        else{
            if (not my_queue.empty()){
                if (value > 0){
                    my_queue.erase(prev(my_queue.end()));
                }
                else{
                    my_queue.erase(my_queue.begin());
                }
            }
        }
    }
    
    vector<int> answer;
    
    if (my_queue.empty()){
        answer = {0, 0};
    }
    else{
        answer = {*prev(my_queue.end()), *my_queue.begin()};
    }
    
    return answer;
}