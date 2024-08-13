#include <iostream>

using namespace std;

int main()
{
	int bag;
	cin >> bag;

	int five = bag / 5;
	int remain = bag % 5;
	while (five >= 0) {
		int threeRemain = remain % 3;
		if (threeRemain != 0) {
			--five;
			remain += 5;
			continue;
		}
		else {
			break;
		}
	}
	int outNum;
	if (five >= 0) {
		outNum = five + remain / 3;
	}
	else {
		outNum = -1;
	}
	cout << outNum << endl;
}