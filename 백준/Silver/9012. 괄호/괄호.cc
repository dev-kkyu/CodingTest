#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isValidPS(const string& str)
{
	stack<char> stacks;

	for (char c : str) {
		if (c == '(') {
			stacks.push(c);
		}
		else {
			if (not stacks.empty()) {
				stacks.pop();
			}
			else {
				return false;
			}
		}
	}
	return stacks.empty();
}

int main()
{
	int count;
	cin >> count;

	vector<string> strs;
	strs.reserve(count);
	for (int i = 0; i < count; ++i) {
		string str;
		cin >> str;
		strs.push_back(str);
	}

	for (int i = 0; i < count; ++i) {
		if (isValidPS(strs[i])) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
