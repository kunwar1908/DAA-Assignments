
#include <bits/stdc++.h>
using namespace std;

struct Job {
	string id;
	int deadline;
	int profit;
};

int main() {

	cout << "Enter number of jobs, then job IDs, then deadlines, then profits:\n";
	int N;
	if (!(cin >> N)) {
		return 0;
	}

	vector<string> ids(N);
	vector<int> deadlines(N), profits(N);

	cout << "Enter " << N << " job IDs:\n";
	for (int i = 0; i < N; ++i) {
		cin >> ids[i];
	}

	cout << "Enter " << N << " deadlines:\n";
	for (int i = 0; i < N; ++i) {
		cin >> deadlines[i];
	}

	cout << "Enter " << N << " profits:\n";
	for (int i = 0; i < N; ++i) {
		cin >> profits[i];
	}

	vector<Job> jobs;
	jobs.reserve(N);
	int maxDeadline = 0;
	for (int i = 0; i < N; ++i) {
		jobs.push_back({ids[i], deadlines[i], profits[i]});
		maxDeadline = max(maxDeadline, deadlines[i]);
	}

	sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
		return a.profit > b.profit;
	});

	vector<int> slot(maxDeadline + 1, -1);
	vector<string> selected;
	int totalProfit = 0;

	for (size_t i = 0; i < jobs.size(); ++i) {
		for (int t = jobs[i].deadline; t >= 1; --t) {
			if (slot[t] == -1) {
				slot[t] = static_cast<int>(i);
				selected.push_back(jobs[i].id);
				totalProfit += jobs[i].profit;
				break;
			}
		}
	}

	cout << "Selected Jobs: [";
	for (size_t i = 0; i < selected.size(); ++i) {
		cout << selected[i];
		if (i + 1 < selected.size()) {
			cout << ", ";
		}
	}
	cout << "]\n";
	cout << "Maximum Profit = " << totalProfit << "\n";
	return 0;
}
