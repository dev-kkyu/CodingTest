#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int size;
	cin >> size;

	vector<int> nums(size);

	for (int i = 0; i < size; ++i) {
		cin >> nums[i];
	}

	vector<int> tails;

	for (int num : nums) {
		auto itr = lower_bound(tails.begin(), tails.end(), num);
		if (itr == tails.end())
			tails.push_back(num);
		else
			*itr = num;
	}

	cout << tails.size() << '\n';
}