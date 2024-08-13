#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int numCount;
	cin >> numCount;
	vector<int> nums(numCount);
	for (int i = 0; i < numCount; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end(), less<int>());
	for (int num : nums)
		cout << num << '\n';
}