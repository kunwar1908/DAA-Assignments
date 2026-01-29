#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x;
	double y;
};

struct Result {
	double dist;
	Point a;
	Point b;
};

static double distancePoints(const Point &p1, const Point &p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

static Result bruteForce(const vector<Point> &pts, int l, int r) {
	Result best{numeric_limits<double>::infinity(), {0, 0}, {0, 0}};
	for (int i = l; i <= r; i++) {
		for (int j = i + 1; j <= r; j++) {
			double d = distancePoints(pts[i], pts[j]);
			if (d < best.dist) {
				best = {d, pts[i], pts[j]};
			}
		}
	}
	return best;
}

static Result closestStrip(vector<Point> &strip, double d) {
	sort(strip.begin(), strip.end(), [](const Point &p1, const Point &p2) {
		if (p1.y == p2.y) return p1.x < p2.x;
		return p1.y < p2.y;
	});

	Result best{d, {0, 0}, {0, 0}};
	for (int i = 0; i < (int)strip.size(); i++) {
		for (int j = i + 1; j < (int)strip.size() && (strip[j].y - strip[i].y) < best.dist; j++) {
			double dist = distancePoints(strip[i], strip[j]);
			if (dist < best.dist) {
				best = {dist, strip[i], strip[j]};
			}
		}
	}
	return best;
}

static Result closestUtil(vector<Point> &pts, int l, int r, int depth) {
	int n = r - l + 1;
	string indent(depth * 2, ' ');

	if (n <= 3) {
		Result res = bruteForce(pts, l, r);
		cout << indent << "Brute force on range [" << l << ", " << r << "] -> "
			 << "min distance = " << res.dist << "\n";
		return res;
	}

	int mid = l + (r - l) / 2;
	double midX = pts[mid].x;

	cout << indent << "Divide range [" << l << ", " << r << "] at mid index "
		 << mid << " (x = " << midX << ")\n";

	Result left = closestUtil(pts, l, mid, depth + 1);
	Result right = closestUtil(pts, mid + 1, r, depth + 1);

	Result best = (left.dist < right.dist) ? left : right;
	double d = best.dist;

	vector<Point> strip;
	for (int i = l; i <= r; i++) {
		if (fabs(pts[i].x - midX) < d) {
			strip.push_back(pts[i]);
		}
	}

	cout << indent << "Combine step: strip size = " << strip.size() << ", current d = " << d << "\n";

	Result stripRes = closestStrip(strip, d);
	if (stripRes.dist < best.dist) {
		best = stripRes;
		cout << indent << "Updated by strip: d = " << best.dist << "\n";
	}

	return best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<Point> points = {
		{9, 3}, {2, 6}, {15, 3}, {5, 1},
		{1, 2}, {12, 4}, {7, 2}, {4, 7},
		{16, 5}, {3, 3}, {10, 5}, {6, 4},
		{14, 6}, {8, 6}, {11, 1}, {13, 2}
	};

	cout << "Given points:\n";
	for (const auto &p : points) {
		cout << "(" << p.x << ", " << p.y << ") ";
	}
	cout << "\n\n";

	sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
		if (p1.x == p2.x) return p1.y < p2.y;
		return p1.x < p2.x;
	});

	cout << "Points sorted by x-coordinate:\n";
	for (const auto &p : points) {
		cout << "(" << p.x << ", " << p.y << ") ";
	}
	cout << "\n\nDivide and Conquer Steps:\n";

	Result best = closestUtil(points, 0, (int)points.size() - 1, 0);

	cout << "\n========================================\n";
	cout << "Closest pair: (" << best.a.x << ", " << best.a.y << ") and (" << best.b.x << ", " << best.b.y << ")\n";
	cout << "Minimum Euclidean distance: " << fixed << setprecision(4) << best.dist << "\n";
	cout << "========================================\n";

	return 0;
}
