#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    string str = to_string(n);
    answer.reserve(str.size());
    for(auto itr = str.rbegin();itr != str.rend(); ++itr)
        answer.push_back(*itr - '0');
    
    return answer;
}