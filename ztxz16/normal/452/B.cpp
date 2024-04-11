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
#include <cmath>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

const int N = 105;

struct Point {
	int x, y;
	
	Point (const int &x = 0, const int &y = 0) :
		x(x), y(y) {}
		
	friend double dis(const Point &a, const Point &b) {
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	
	friend bool operator < (const Point &a, const Point &b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	}
	
	friend bool operator == (const Point &a, const Point &b) {
		return a.x == b.x && a.y == b.y;
	}
} a[N], ans[N], sel[N];

double lenMax = 0.0;

int tot, n, m;
int visit[N];

void dfs(int i) {
	if (i > 4) {
		double s = 0.0;
		for (int x = 1; x < 4; x++) {
			s += dis(sel[x], sel[x + 1]);
		}
		
		if (s > lenMax) {
			lenMax = s;
			for (int x = 1; x <= 4; x++) {
				ans[x] = sel[x];
			}
		}
		
		return;
	}
	
	for (int x = 1; x <= tot; x++) {
		if (visit[x]) {
			continue;
		}
		
		sel[i] = a[x];
		visit[x] = 1;
		dfs(i + 1);
		visit[x] = 0;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			a[++tot] = Point(i, j);
			if (tot == 4) {
				break;
			}
		}
		
		if (tot == 4) {
			break;
		}
	}
	
	for (int i = n; i >= 0; i--) {
		for (int j = m; j >= 0; j--) {
			a[++tot] = Point(i, j);
			if (tot == 8) {
				break;
			}
		}
		
		if (tot == 8) {
			break;
		}
	}
	
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			a[++tot] = Point(j, i);
			if (tot == 12) {
				break;
			}
		}
		
		if (tot == 12) {
			break;
		}
	}
	
	for (int i = m; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			a[++tot] = Point(j, i);
			if (tot == 16) {
				break;
			}
		}
		
		if (tot == 16) {
			break;
		}
	}
	
	sort(a + 1, a + tot + 1);
	tot = unique(a + 1, a + tot + 1) - a - 1;
	dfs(1);
	for (int i = 1; i <= 4; i++) {
		printf("%d %d\n", ans[i].x, ans[i].y);	
	}
	
	return 0;
}