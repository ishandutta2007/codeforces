#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int N = 100005;

struct People {
	int t, s, f, tag;
	
	void read() {
		scanf("%d %d %d", &t, &s, &f);
	}
	
	friend bool operator < (const People &a, const People &b) {
		return a.t < b.t;
	}
} p[N], temp[N];

set <pair <int, int> > goUp, goDown, waitUp, waitDown;
int n, m, l, pos;
long long t, ans[N];

void go(long long tt) {
	if (tt == 10) {
		tt = 10;
	}
	
	int sUp = waitUp.size() + goUp.size(), sDown = waitDown.size() + goDown.size();
	if (sUp + sDown) {
		if (sUp >= sDown) {
			l += (tt - t);
			while (goUp.size() && goUp.begin()->first == l) {
				pair <int, int> now = *goUp.begin();
				goUp.erase(now);
				ans[now.second] = tt;
			}
			
			while (waitUp.size() && waitUp.begin()->first == l) {
				pair <int, int> now = *waitUp.begin();
				waitUp.erase(now);
				now.first = temp[now.second].f;
				if (now.first < l) {
					goDown.insert(now);
				} else {
					goUp.insert(now);
				}
			}
		} else {
			l -= (tt - t);
			while (goDown.size() && goDown.rbegin()->first == l) {
				pair <int, int> now = *goDown.rbegin();
				goDown.erase(now);
				ans[now.second] = tt;
			}
			
			while (waitDown.size() && waitDown.rbegin()->first == l) {
				pair <int, int> now = *waitDown.rbegin();
				waitDown.erase(now);
				now.first = temp[now.second].f;
				if (now.first < l) {
					goDown.insert(now);
				} else {
					goUp.insert(now);
				}
			}
		}
	}
	
	t = tt;
	while (pos + 1 <= n && p[pos + 1].t == tt) {
		pos++;
		if (p[pos].s == l) {
			if (p[pos].f > l) {
				goUp.insert(make_pair(p[pos].f, p[pos].tag));
			} else {
				goDown.insert(make_pair(p[pos].f, p[pos].tag));
			}
		} else {
			if (p[pos].s > l) {
				waitUp.insert(make_pair(p[pos].s, p[pos].tag));
			} else {
				waitDown.insert(make_pair(p[pos].s, p[pos].tag));
			}
		}
	}
	
	//sUp = waitUp.size() + goUp.size(), sDown = waitDown.size() + goDown.size();
	//printf("t = %I64d, l = %d, pos = %d, sup = %d, sdown = %d\n",t, l, pos, sUp, sDown);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i].read();
		temp[i] = p[i];
		p[i].tag = i;
	}
	
	sort(p + 1, p + n + 1);
	t = 0, l = 1, pos = 0;
	while (1) {
		int sUp = waitUp.size() + goUp.size(), sDown = waitDown.size() + goDown.size();
		if (!(sUp + sDown)) {
			if (pos == n) {
				break;
			} else {
				go(p[pos + 1].t);
			}
		} else {
			if (sUp >= sDown) {
				int now = OO;
				if (waitUp.size()) {
					now = min(now, waitUp.begin()->first - l);
				}
				
				if (goUp.size()) { 
					now = min(now, goUp.begin()->first - l);
				}
				
				if (pos < n && p[pos + 1].t < t + now) {
					go(p[pos + 1].t);
				} else {
					go(t + now);
				}
			} else {
				int now = OO;
				if (waitDown.size()) {
					now = min(now, l - waitDown.rbegin()->first);
				}
				
				if (goDown.size()) { 
					now = min(now, l - goDown.rbegin()->first);
				}
				
				if (pos < n && p[pos + 1].t < t + now) {
					go(p[pos + 1].t);
				} else {
					go(t + now);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}