#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    for(int i=1;;++i){
        a = ceil(a / 2.0);
        b = ceil(b / 2.0);
        if (a == b)
            return i;
    }
}