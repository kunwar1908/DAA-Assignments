
#include <bits/stdc++.h>
using namespace std;

static int toMinutes(const string &t) {
	int hh = (t[0] - '0') * 10 + (t[1] - '0');
	int mm = (t[3] - '0') * 10 + (t[4] - '0');
	return hh * 60 + mm;
}

int main() {
	cin.tie(nullptr);

	cout << "Enter number of trains, then arrival times (HH:MM), then departure times (HH:MM):\n";
	int N;
	if (!(cin >> N)) {
		return 0;
	}

	vector<int> arrivals(N), departures(N);
	cout << "Enter " << N << " arrival times:\n";
	for (int i = 0; i < N; ++i) {
		string t;
		cin >> t;
		arrivals[i] = toMinutes(t);
	}

	cout << "Enter " << N << " departure times:\n";
	for (int i = 0; i < N; ++i) {
		string t;
		cin >> t;
		departures[i] = toMinutes(t);
	}

	sort(arrivals.begin(), arrivals.end());
	sort(departures.begin(), departures.end());

	int i = 0, j = 0;
	int platforms = 0, maxPlatforms = 0;

	while (i < N && j < N) {
		if (arrivals[i] <= departures[j]) {
			++platforms;
			maxPlatforms = max(maxPlatforms, platforms);
			++i;
		} else {
			--platforms;
			++j;
		}
	}

	cout << "Minimum number of platforms required = " << maxPlatforms << "\n";
	return 0;
}
