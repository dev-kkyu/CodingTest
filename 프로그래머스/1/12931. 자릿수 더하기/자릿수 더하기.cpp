#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    string str = to_string(n);
    int num = 0;
    for(char c : str)
        num += c -= '0';
    return num;
}