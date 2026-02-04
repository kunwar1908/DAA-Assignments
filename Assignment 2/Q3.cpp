
#include <bits/stdc++.h>
using namespace std;

struct Item {
	double value;
	double weight;
};

int main() {
	cout << "Enter number of items, then values, then weights, then capacity:\n";
	int N;
	if (!(cin >> N)) {
		return 0;
	}

	vector<double> values(N), weights(N);
	cout << "Enter " << N << " values:\n";
	for (int i = 0; i < N; ++i) {
		cin >> values[i];
	}
	cout << "Enter " << N << " weights:\n";
	for (int i = 0; i < N; ++i) {
		cin >> weights[i];
	}

	double W;
	cout << "Enter capacity:\n";
	cin >> W;

	vector<Item> items;
	items.reserve(N);
	for (int i = 0; i < N; ++i) {
		items.push_back({values[i], weights[i]});
	}

	sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
		return (a.value / a.weight) > (b.value / b.weight);
	});

	double totalValue = 0.0;
	double remaining = W;
	for (const auto &it : items) {
		if (remaining <= 0) break;
		if (it.weight <= remaining) {
			totalValue += it.value;
			remaining -= it.weight;
		} else {
			double fraction = remaining / it.weight;
			totalValue += it.value * fraction;
			remaining = 0;
		}
	}

	cout << "Maximum value = " << fixed << setprecision(2) << totalValue << "\n";
	return 0;
}
