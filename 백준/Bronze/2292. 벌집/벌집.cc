#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int wayCount = 1;

	int sum = 1;
	while (sum < num) {
		sum += wayCount * 6;
		++wayCount;
	}

	cout << wayCount << endl;
}