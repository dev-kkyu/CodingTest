#include <iostream>
#include <vector>

using namespace std;

bool isPrimeNumber(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int numCount;
	cin >> numCount;

	vector<int> nums(numCount);

	for (int i = 0; i < numCount; ++i) {
		cin >> nums[i];
	}

	int primeCount = 0;
	for (int i = 0; i < numCount; ++i) {
		if (isPrimeNumber(nums[i]))
			++primeCount;
	}
	cout << primeCount << endl;
}