#include <string>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> charMap{{'[', ']'}, {'{', '}'}, {'(', ')'}};

bool isValidString(const list<char>& strs)
{
    stack<char> stackStr;
    
    for(char c : strs){
        if (stackStr.empty()){
            stackStr.push(c);
        }
        else{          
            if (c == charMap[stackStr.top()])
                stackStr.pop();
            else
                stackStr.push(c);
        }
    }
    
    return stackStr.empty();
}

int solution(string s) {
    list<char> strs{s.begin(), s.end()};
    
    int answer = 0;
    for(int i = 0;i< s.size();++i){
        if (isValidString(strs))
            ++answer;
        strs.push_back(strs.front());
        strs.pop_front();
    }
    
    return answer;
}