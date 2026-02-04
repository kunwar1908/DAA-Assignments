
#include <bits/stdc++.h>
using namespace std;

struct Activity {
	int start;
	int finish;
};

int main() {
	cout << "Enter number of activities, then start times, then finish times:\n";
	int N;
	if (!(cin >> N)) {
		return 0;
	}

	cout << "Enter " << N << " start times:\n";
	vector<int> start(N), finish(N);
	for (int i = 0; i < N; ++i) {
		cin >> start[i];
	}
	cout << "Enter " << N << " finish times:\n";
	for (int i = 0; i < N; ++i) {
		cin >> finish[i];
	}

	vector<Activity> activities;
	activities.reserve(N);
	for (int i = 0; i < N; ++i) {
		activities.push_back({start[i], finish[i]});
	}

	sort(activities.begin(), activities.end(), [](const Activity &a, const Activity &b) {
		if (a.finish != b.finish) return a.finish < b.finish;
		return a.start < b.start;
	});

	vector<Activity> selected;
	int lastFinish = INT_MIN;
	for (const auto &act : activities) {
		if (act.start >= lastFinish) {
			selected.push_back(act);
			lastFinish = act.finish;
		}
	}

	cout << "Maximum number of activities = " << selected.size() << "\n";
	cout << "Selected activities: ";
	for (size_t i = 0; i < selected.size(); ++i) {
		cout << "(" << selected[i].start << ", " << selected[i].finish << ")";
		if (i + 1 < selected.size()) {
			cout << ", ";
		}
	}
	cout << "\n";

	return 0;
}
