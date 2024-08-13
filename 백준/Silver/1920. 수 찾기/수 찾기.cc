#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long nums[100000];

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i) {
		long long num;
		cin >> num;
		nums[i] = num;
	}

	sort(nums, nums + count);

	int newCount;
	cin >> newCount;
	for (int i = 0; i < newCount; ++i) {
		long long num;
		cin >> num;
		cout << int(binary_search(nums, nums + count, num)) << '\n';
	}
}