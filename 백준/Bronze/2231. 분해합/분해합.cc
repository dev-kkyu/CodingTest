#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int input;
	cin >> input;

	int digit = 0;
	int tempNum = input;
	while (tempNum > 0) {
		++digit;
		tempNum /= 10;
	}

	int max_dist = digit * 9;

	vector<int> candidate_list;
	for (int i = input - max_dist; i < input; ++i) {
		string strNum = to_string(i);
		int newNum = i;
		for (int n = 0; n < strNum.size(); ++n) {
			newNum += strNum[n] - '0';
		}
		if (newNum == input)
			candidate_list.push_back(i);
	}
	if (candidate_list.empty()) {
		cout << 0 << '\n';
	}
	else {
		cout << *min_element(candidate_list.begin(), candidate_list.end()) << '\n';
	}
}