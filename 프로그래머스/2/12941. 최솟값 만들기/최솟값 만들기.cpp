#include <iostream>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int size = A.size();
    
    sort(A.begin(), A.end());    
    sort(B.begin(), B.end());

    int retVal = 0;
    for(int i=0;i<size;++i){
        retVal += A[i] * B[size - 1 - i];
    }
    
    return retVal;
}