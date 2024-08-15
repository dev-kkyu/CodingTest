
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> strStack;
    
    for(char c : s){
        if(not strStack.empty()){
            if (strStack.top() == c){
                strStack.pop();
            }
            else{
                strStack.push(c);
            }
        }
        else{
            strStack.push(c);
        }
    }
    
    return strStack.empty();
}