#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    string str;
    str.reserve(s.size());
    
    bool flag = true;
    for(char c : s){
        if (isspace(c)){
            flag = true;
        }
        else if (flag){
            c = toupper(c);
            flag = false;
        }
        else{
            c = tolower(c);
        }
        str.push_back(c);
    }
    return str;
}