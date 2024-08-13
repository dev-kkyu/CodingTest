#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> scores;

	int subjectCount;
	cin >> subjectCount;

	scores.resize(subjectCount);

	for (int i = 0; i < subjectCount; ++i) {
		int num;
		cin >> num;
		scores[i] = num;
	}

	int maxScore = *max_element(scores.begin(), scores.end());

	vector<double> newScores(subjectCount);

	for (int i = 0; i < subjectCount; ++i) {
		newScores[i] = double(scores[i]) / maxScore * 100;
	}

	double average = accumulate(newScores.begin(), newScores.end(), 0.0) / newScores.size();

	cout << average << endl;
}