#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int N = 200005;

int n;
pair <int, int> s, tt, q[N];
set <pair <int, int> > oks;
map <pair <int, int>, int> dis;

int main() {
	scanf("%d %d", &s.first, &s.second);
	scanf("%d %d", &tt.first, &tt.second);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int r, a, b;
		scanf("%d %d %d", &r, &a, &b);
		for (int j = a; j <= b; j++) {
			oks.insert(make_pair(r, j));
		}
	}
	
	q[1] = s;
	dis[s] = 0;
	for (int h = 1, t = 1; h <= t; h++) {
		pair <int, int> now = q[h];
		int disNow = dis[now];
		pair <int, int> x = make_pair(now.first - 1, now.second);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
		
		x = make_pair(now.first + 1, now.second);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
		
		x = make_pair(now.first, now.second - 1);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
		
		x = make_pair(now.first, now.second + 1);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
		
		x = make_pair(now.first - 1, now.second - 1);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
		
		x = make_pair(now.first - 1, now.second + 1);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
		
		x = make_pair(now.first + 1, now.second - 1);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
		
		x = make_pair(now.first + 1, now.second + 1);
		if (oks.find(x) != oks.end() && dis.find(x) == dis.end()) {
			dis[x] = disNow + 1;
			q[++t] = x;
		}
	}
	
	if (dis.find(tt) == dis.end()) {
		printf("-1\n");
	} else {
		printf("%d\n", dis[tt]);
	}
	
	return 0;
}