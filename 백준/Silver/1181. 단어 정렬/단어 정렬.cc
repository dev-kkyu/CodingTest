#include <iostream>
#include <string>
#include <set>

using namespace std;

struct cmp
{
	bool operator()(const string& a, const string& b) const {
		if (a.size() == b.size()) {
			return a < b;
		}
		return a.size() < b.size();
	}
};

int main()
{
	int count;
	cin >> count;
	set<string, cmp> strs;
	for (int i = 0; i < count; ++i) {
		string temp;
		cin >> temp;
		strs.insert(temp);
	}
	for (const auto& str : strs)
		cout << str << '\n';
}