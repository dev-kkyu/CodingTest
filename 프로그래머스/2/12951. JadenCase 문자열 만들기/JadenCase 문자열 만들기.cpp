#include <string>
#include <vector>
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
            if (isalpha(c)){
                if (islower(c))
                    c -= 'a' - 'A';
            }
            flag = false;
        }
        else{
            if (isupper(c)){
                c += 'a' - 'A';
            }
        }
        str.push_back(c);
    }
    return str;
}