#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cstdlib>
#include <cassert>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 6000 + 10;
const int MAX_M = MAX_N * MAX_N / 2;
bool is[MAX_M];
int color[MAX_N], n;

void output() {
	for (int i = 0; i < n; ++i) {
		cout << color[i] << " ";
	}
	cout << endl;
	exit(0);
}

int main() {
	fill(is + 2, is + MAX_M, true);
	for (int i = 2; i * i < MAX_M; ++i) {
		if (!is[i])
			continue;
		for (int j = i * i; j < MAX_M; j += i)
			is[j] = false;
	}

	cin >> n;
	int s = n * (n + 1) / 2;
	if (is[s]) {
		fill(color, color + n, 1);
		output();
	}
	if (s % 2 == 0) {
		for (int k = 2; k < s; ++k) {
			if (is[k] && is[s - k]) {
				fill(color, color + n, 1);
				int rem = k;
				for (int i = n; i >= 1; --i) {
					if (rem >= i) {
						color[i - 1] = 2;
						rem -= i;
					}
				}
				assert(rem==0);
				output();
			}
		}
	}
	if (is[s - 2]) {
		fill(color, color + n, 1);
		color[1] = 2;
		output();
	}

	color[0] = color[1] = 3;
	for (int k = 2; k < s - 3; ++k) {
		if (is[k] && is[s - 3 - k]) {
			fill(color + 2, color + n, 1);
			int rem = k;
			for (int i = n; i >= 1; --i) {
				if (rem >= i && i > 2) {
					color[i - 1] = 2;
					rem -= i;
				}
			}
			while (rem > 0) {
				for (int i = 2; i < n; ++i) {
					if (color[i] == 2 && color[i + 1] == 1) {
						swap(color[i], color[i + 1]);
						--rem;
						break;
					}
				}
			}
			assert(rem==0);
			output();
		}
	}
	return 0;
}