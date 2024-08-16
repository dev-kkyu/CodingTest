#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	int st_cnt{};
	cin >> st_cnt;		// 3~1000

	vector<array<int, 5>> v;		// 벡터는 인원수, array는 1~5학년때의 반
	v.reserve(st_cnt);

	for (int i = 0; i < st_cnt; ++i) {
		array<int, 5> inArr{};
		for (int j = 0; j < 5; ++j) {
			cin >> inArr[j];		// 1~9
		}

		v.push_back(inArr);
	}

	vector<int> vr;		// 인원수, 한번이라도 같은 반이었던 친구 수
	vr.reserve(st_cnt);
	for (int i = 0; i < st_cnt; ++i) {
		int num = 0;
		for (int j = 0; j < st_cnt; ++j) {
			if (i == j)
				continue;
			for (int k = 0; k < 5; ++k) {
				if (v[i][k] == v[j][k]) {
					++num;
					break;
				}
			}
		}
		vr.push_back(num);
	}

	auto itr = max_element(vr.begin(), vr.end());
	for (int i = 0; i < st_cnt; ++i) {
		if (vr[i] == *itr) {
			cout << i + 1;
			break;
		}
	}

}
