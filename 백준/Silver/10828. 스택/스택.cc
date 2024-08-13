#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int cmdCount;
	cin >> cmdCount;

	stack<int> ss;

	for (int i = 0; i < cmdCount; ++i) {
		string cmd;
		cin >> cmd;

		if ("push" == cmd) {
			int num;
			cin >> num;
			ss.push(num);
		}
		else if ("pop" == cmd) {
			if (ss.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << ss.top() << endl;
				ss.pop();
			}
		}
		else if ("size" == cmd) {
			cout << ss.size() << endl;
		}
		else if ("empty" == cmd) {
			cout << int(ss.empty()) << endl;
		}
		else if ("top" == cmd) {
			if (ss.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << ss.top() << endl;
			}
		}
	}
}