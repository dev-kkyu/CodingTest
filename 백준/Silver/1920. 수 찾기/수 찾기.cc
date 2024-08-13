#include <iostream>
#include <set>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	set<long long> nums;

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i) {
		long long num;
		cin >> num;
		nums.insert(num);
	}

	cin >> count;
	for (int i = 0; i < count; ++i) {
		long long num;
		cin >> num;
		cout << nums.count(num) << '\n';
	}
}