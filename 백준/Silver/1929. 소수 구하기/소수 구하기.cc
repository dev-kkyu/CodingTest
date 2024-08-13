#include <iostream>

using namespace std;

bool isPrimeNumber(int num)
{
	if (1 == num)
		return false;
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int min, max;
	cin >> min >> max;

	for (int i = min; i <= max; ++i) {
		if (isPrimeNumber(i)) {
			cout << i << '\n';
		}
	}
}