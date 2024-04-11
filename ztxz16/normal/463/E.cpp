#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int MAX = 2000000;
const int N = 100005;

int n, q, value[N], isNot[MAX + 5];
vector <int> v[N], prime[MAX + 5];
set <pair <int, int> > s[MAX + 5];
pair <int, int> ans[N];

void getAns(int now, int father, int deep) {
	int vNow = value[now];
	ans[now] = make_pair(-1, -1);
	for (int i = 0; i < (int)prime[vNow].size(); i++) {
		int x = prime[vNow][i];
		ans[now] = max(ans[now], *s[x].rbegin());
		s[x].insert(make_pair(deep, now));
	}
	
	for (int i = 0; i < (int)v[now].size(); i++) {
		int x = v[now][i];
		if (x == father) {
			continue;
		}
		
		getAns(x, now, deep + 1);
	}
	
	for (int i = 0; i < (int)prime[vNow].size(); i++) {
		int x = prime[vNow][i];
		s[x].erase(make_pair(deep, now));
	}
}

int main() {
	scanf("%d %d", &n, &q);
	isNot[1] = 1;
	for (int i = 1; i * i <= MAX; i++) {
		if (isNot[i]) {
			continue;
		}
		
		for (int j = i * i; j <= MAX; j += i) {
			isNot[j] = 1;
		}
	}
	
	for (int i = 1; i <= MAX; i++) {
		if (isNot[i]) {
			continue;
		}
		
		for (int j = i; j <= MAX; j += i) {
			prime[j].push_back(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &value[i]);
	}
	
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 1; i <= MAX; i++) {
		if (!isNot[i]) {
			s[i].insert(make_pair(-1, -1));
		}
	}
	
	getAns(1, 0, 1);
	while (q--) {
		int type, a, b;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d", &a);
			printf("%d\n", ans[a].second);
		} else {
			scanf("%d %d", &a, &b);
			value[a] = b;
			getAns(1, 0, 1);
		}
	}
	
	return 0;
}