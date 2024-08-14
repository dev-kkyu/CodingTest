#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {
    stringstream ss{s};
    
    vector<int> nums;
    while(ss){
        int num;
        ss >> num;
        nums.push_back(num);
    }
    
    int maxValue = *max_element(nums.begin(), nums.end());
    int minValue = *min_element(nums.begin(), nums.end());
    
    string answer = to_string(minValue) + " " + to_string(maxValue);
    return answer;
}