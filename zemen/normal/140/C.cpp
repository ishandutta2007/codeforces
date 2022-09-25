#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <complex.h>
#include <string.h>
#include <memory.h>

#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long li;
typedef long double ld;

#define INF 0x7fffffff
#define PI acos(-1)
#define mp make_pair

struct tr {
	int q, w, e;
	tr (int q1, int w1, int e1) {
		q = q1;
		w = w1;
		e = e1;
	}
};

int a1[100001];
priority_queue < pair <int, int> > a;
vector <tr> res;


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a1 + i);
	sort(a1, a1 + n);
	int cnt = 1;
	for (int i = 1; i < n; ++i) {
		if (a1[i] == a1[i - 1])
			cnt++;
		else {
			a.push(mp(cnt, a1[i - 1]));
			cnt = 1;
		}
	}
    a.push(mp(cnt, a1[n - 1]));
	while (a.size() > 2) {
		pair <int, int> q, w, e;
		q = a.top();
		a.pop();
		w = a.top();
		a.pop();
		e = a.top();
		a.pop();
		res.push_back(tr(q.second, w.second, e.second));
		q.first--;
		w.first--;
		e.first--;
		if (q.first)
			a.push(q);
		if (w.first)
			a.push(w);
		if (e.first)
			a.push(e);
	}
	printf("%d\n", (int)res.size());
	for (int i = 0; i < (int)res.size(); ++i) {
	    int t[3];
	    t[0] = res[i].q;
	    t[1] = res[i].w;
	    t[2] = res[i].e;
	    sort(t, t + 3);
		printf("%d %d %d\n", t[2], t[1], t[0]);
	}
}