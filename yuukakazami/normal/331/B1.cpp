#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = int(3e5) + 10;
int n;
int at[MAX_N]; //where is i? a

int a[MAX_N], ta[MAX_N];
void add(int p, int x) {
	for (p++; p <= n; p += p & -p) {
		ta[p - 1] += x;
	}
}

int sum(int p) {
	int r = 0;
	for (p++; p; p -= p & -p) {
		r += ta[p - 1];
	}
	return r;
}

void back(int i) {
	if (i < 0 || i + 1 >= n)
		return;
	if (at[i] > at[i + 1])
		add(i, -1);
}

void put(int i) {
	if (i < 0 || i + 1 >= n)
		return;
	if (at[i] > at[i + 1])
		add(i, 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		at[x] = i;
		a[i] = x;
	}

	for (int i = 0; i + 1 < n; ++i) {
		if (at[i] > at[i + 1]) {
			add(i, 1);
		}
	}

	int nQ;
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int q, x, y;
		scanf("%d%d%d", &q, &x, &y);
		--y, --x;
		if (q == 1) {
			int ans = 1 + sum(y - 1) - sum(x - 1);
			printf("%d\n", ans);

//			for (int k = x; k <= y; ++k) {
//				cout << at[k] << " ";
//			}
//			cout << endl;
		} else {
			int i = a[x], j = a[y];
			swap(a[x], a[y]);

			vector<int> who;
			who.push_back(i - 1), who.push_back(i), who.push_back(j - 1), who.push_back(
					j);

			sort(who.begin(), who.end());
			who.erase(unique(who.begin(), who.end()), who.end());

			for (int i = 0; i < (int) who.size(); ++i) {
				back(who[i]);
			}

			swap(at[i], at[j]);

			for (int i = 0; i < (int) who.size(); ++i) {
				put(who[i]);
			}

		}
	}
	return 0;
}