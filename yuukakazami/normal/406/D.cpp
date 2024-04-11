#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <deque>
using namespace std;

const int MAX_N = int(1e5) + 10;
typedef long long int64;

struct Point {
	int64 x, y;
	Point() {
	}
	Point(int64 _x, int64 _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	int64 dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	int64 det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	void read() {
		cin >> x >> y;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

Point ps[MAX_N];
int n;

int nxt[MAX_N][20];
int dep[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ps[i].read();
	}

	memset(nxt, -1, sizeof nxt);
	deque<int> que;
	for (int i = n - 1; i >= 0; --i) {
		while (que.size() >= 2 && cross(ps[i], ps[que[0]], ps[que[1]]) > 0)
			que.pop_front();
		if (que.size() > 0)
			nxt[i][0] = que[0];
		else
			nxt[i][0] = -1;
		que.push_front(i);
	}
	dep[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		dep[i] = dep[nxt[i][0]] + 1;
	}
	for (int i = n - 2; i >= 0; --i) {
		int u = i, p = nxt[i][0];
		nxt[u][0] = p;
		for (int j = 0; j + 1 < 20; ++j) {
			int g = nxt[u][j];
			if (g == -1)
				nxt[u][j + 1] = -1;
			else
				nxt[u][j + 1] = nxt[g][j];
		}
	}

	int m;
	scanf("%d", &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		if (dep[x] < dep[y])
			swap(x, y);
		int up = dep[x] - dep[y];
		for (int i = 0; i < 20; ++i)
			if (up >> i & 1) {
				x = nxt[x][i];
			}
		if (x != y) {
			for (int i = 20 - 1; i >= 0; --i) {
				if (nxt[x][i] != nxt[y][i])
					x = nxt[x][i], y = nxt[y][i];
			}
			x = nxt[x][0];
		}
		printf("%d ", x + 1);
	}
	puts("");
}