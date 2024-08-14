#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<bool> ss;
    
    for(char c : s){
        if (c == '(')
            ss.push(true);
        else{
            if (ss.empty())
                return false;
            ss.pop();
        }
    }
    return ss.empty();
}