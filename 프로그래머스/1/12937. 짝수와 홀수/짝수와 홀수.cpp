#include <string>

using namespace std;

string solution(int num) {
    if (num & 1)
        return "Odd";
    return "Even";
}