#include <iostream>

using namespace std;
int main()
{
	int day;
	int night;
	int height;
	cin >> day >> night >> height;

	int wayPerDay = day - night;

	int count = height / wayPerDay + !!(0 != height % wayPerDay);

	while (wayPerDay * (count - 1) + night >= height) {
		--count;
	}

	cout << count << '\n';
}