
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = int(1e5) + 10;
typedef long long int64;
const int64 INF = 1LL << 60;

struct Point {
	int64 x;
	int64 y;
} point[N];
int n;
int tmpt[N];

bool cmpxy(const Point& a, const Point& b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

bool cmpy(const int& a, const int& b) {
	return point[a].y < point[b].y;
}

int64 dis2(int i, int j) {
	return (point[i].x - point[j].x) * (point[i].x - point[j].x)
			+ (point[i].y - point[j].y) * (point[i].y - point[j].y);
}

int64 sqr(int64 x) {
	return x * x;
}

int64 Closest_Pair(int left, int right) {
	int64 d = INF;
	if (left == right)
		return d;
	if (left + 1 == right)
		return dis2(left, right);
	int mid = (left + right) >> 1;
	int64 d1 = Closest_Pair(left, mid);
	int64 d2 = Closest_Pair(mid + 1, right);
	d = min(d1, d2);
	int i, j, k = 0;
	//d
	for (i = left; i <= right; i++) {
		if (sqr(point[mid].x - point[i].x) <= d)
			tmpt[k++] = i;
	}
	sort(tmpt, tmpt + k, cmpy);
	//
	for (i = 0; i < k; i++) {
		for (j = i + 1; j < k && sqr(point[tmpt[j]].y - point[tmpt[i]].y) < d;
				j++) {
			int64 d3 = dis2(tmpt[i], tmpt[j]);
			if (d > d3)
				d = d3;
		}
	}
	return d;
}

int main() {
	scanf("%d", &n);
	int64 sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		point[i].x = i;
		sum += x;
		point[i].y = sum;
	}
	cout << Closest_Pair(0, n - 1) << endl;
	return 0;
}