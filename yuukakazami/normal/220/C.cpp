/*
 * c.cpp
 *
 *  Created on: 2012-9-1
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <utility>
#include <set>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int n;
const int MAX_N = int(1e5) + 10;
int a[MAX_N], b[MAX_N];
int at1[MAX_N], at2[MAX_N];

//min x+b,-x+b
struct Updater {
	vector<pair<int, int> > es[MAX_N];
	void add(int l, int r, int x) {
		if (l > r)
			return;
		es[l].push_back(make_pair(x, 1));
		es[r + 1].push_back(make_pair(x, -1));
	}
	int a[MAX_N];
	void doit() {
		multiset<int> st;
		for (int i = 0; i < n; ++i) {
			for (vector<pair<int, int> >::iterator e = es[i].begin(); e != es[i].end(); ++e) {
				if (e->second == 1)
					st.insert(e->first);
				else
					st.erase(st.find(e->first));
			}
			a[i] = *st.begin();
		}
	}
} u1, u2;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		at1[a[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		--b[i];
		at2[b[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		int x = at1[i], y = at2[i];
		if (y >= x) {
			//[0,y-x] => y-i-x => -i+(y-x)
			//[y-x+1,y] => x-(y-i) = i+x-y
			//[y+1,n) => y-i+n-x => -i+(y-x+n)
			u1.add(0, y - x, y - x);
			u2.add(y - x + 1, y, x - y);
			u1.add(y + 1, n - 1, y - x + n);
		} else {
			//[0,y] => x-(y-i) => i+x-y
			//[y+1,y-x+n] => (y-i+n)-x =>-i+(y-x+n)
			//[y-x+n+1,n) => x-(y-i+n) =>i+x-y-n
			u2.add(0, y, x - y);
			u1.add(y + 1, y - x + n, y - x + n);
			u2.add(y - x + n + 1, n - 1, x - y - n);
		}
	}

	u1.doit();
	u2.doit();
	for (int i = 0; i < n; ++i) {
		int ans = min(u1.a[i] - i, u2.a[i] + i);
		cout << ans << endl;
	}
	return 0;
}