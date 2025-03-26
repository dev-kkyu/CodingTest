#include <iostream>
#include <string>

int main()
{
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	while (cin >> n) {
		int count = 1;
		size_t num = 1;
		while (0ULL != num % n) {
			num *= 10;
			num += 1;
			num %= n;
			++count;
		}
		cout << count << '\n';
	}
}
