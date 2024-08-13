#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int wayCount = 1;

	int flag = 1;
	int accumFlag = 0;
	for (int i = 2; i <= num; ++i) {
		if (0 == accumFlag)
			++wayCount;
		++accumFlag;
		if (flag * 6 == accumFlag) {
			++flag;
			accumFlag = 0;
		}
	}

	cout << wayCount << endl;
}