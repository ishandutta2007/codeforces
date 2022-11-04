#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

const int N = 300005;

int n, m;
int f[N], now[N];
pair <int, pair <int, int> > v[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v[i].second.first, &v[i].second.second, &v[i].first);
	}
	
	sort(v + 1, v + m + 1);
	for (int i = 1; i <= m; i++) {
		int j;
		for (j = i + 1; j <= m && v[j].first == v[i].first; j++);
		j--;
		
		for (int k = i; k <= j; k++) {
			int a = v[k].second.first;
			f[k] = now[a] + 1;
		}
		
		for (int k = i; k <= j; k++) {
			int a = v[k].second.second;
			now[a] = max(now[a], f[k]);
		}
		
		i = j;
	}
	
	int ans = f[1];
	for (int i = 1; i <= m; i++) {
		ans = max(ans, f[i]);
	}
	
	printf("%d\n", ans);
	return 0;
}