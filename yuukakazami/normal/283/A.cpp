#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = int(2e5) + 10;

struct TA {
	double a[MAX_N];
	int n;
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; ++i) {
			a[i] = 0;
		}
	}
	void add(int p, double x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	void add(int l, int r, double x) {
		add(l, x);
		add(r + 1, -x);
	}
	double get(int p) {
		double r = 0;
		for (p++; p > 0; p -= p & -p)
			r += a[p - 1];
		return r;
	}
} ta;

int main() {
	ta.init(MAX_N);
	int nQ, n = 0;
	cin >> nQ;
	++n;
	double sum = 0;
	for (int i = 0; i < nQ; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int a, x;
			scanf("%d%d", &a, &x);
			ta.add(0, a - 1, x);
			sum += 1.0 * a * x;
		} else if (type == 2) {
			int k;
			scanf("%d", &k);
			sum += k;
			ta.add(n, n, k);
			++n;
		} else {
			double last = ta.get(n - 1);
			ta.add(n - 1, n - 1, -last);
			--n;
			sum -= last;
		}
		printf("%0.10lf\n", sum / n);
	}
	return 0;
}