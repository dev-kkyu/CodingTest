#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int cardCount;
	int maxSum;
	cin >> cardCount >> maxSum;

	vector<int> nums(cardCount);

	for (int i = 0; i < cardCount; ++i)
		cin >> nums[i];

	int sum = 0;
	for (int i = 0; i < cardCount - 2; ++i) {
		for (int j = i + 1; j < cardCount - 1; ++j) {
			for (int k = j + 1; k < cardCount; ++k) {
				int nowSum = nums[i] + nums[j] + nums[k];
				if (nowSum <= maxSum) {
					if (sum < nowSum) {
						sum = nowSum;
					}
				}
			}
		}
	}

	cout << sum << endl;
}