#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0;
    int y = 0;
    
    for(char c : s){
        if (isupper(c))
            c += ('a' - 'A');
        if (c == 'p')
            ++p;
        else if (c == 'y')
            ++y;
    }
    return p == y;
}