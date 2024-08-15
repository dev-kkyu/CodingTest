#include <iostream>
#include <bitset>

using namespace std;

int solution(int n)
{
    bitset<32> ans(n);
    return ans.count();
}