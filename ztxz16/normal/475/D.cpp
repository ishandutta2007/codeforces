#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int N = 100005;

int n, q, a[N];
map <int, long long> ans;
vector <pair <int, int> > g[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = n; i >= 1; i--) {
		g[i].clear();
		g[i].push_back(make_pair(a[i], i));
		for (int j = 0; j < (int)g[i + 1].size(); ++j) {
			int ng = __gcd(g[i].back().first, g[i + 1][j].first);
			if (ng == g[i].back().first) {
				g[i][g[i].size() - 1].second = g[i + 1][j].second;
			} else {
				g[i].push_back(make_pair(ng, g[i + 1][j].second));
			}
		}
		
		int last = i - 1;
		for (int j = 0; j < (int)g[i].size(); j++) {
			ans[g[i][j].first] += (g[i][j].second - last);
			last = g[i][j].second;
		}
	}
	
	scanf("%d", &q);
	while (q--) {
		int x;
		scanf("%d", &x);
		printf("%I64d\n", ans[x]);
	}
	
	return 0;
}