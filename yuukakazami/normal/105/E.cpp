/*
 * E. Lift and Throw.cpp
 *
 *  Created on: 2011-8-23
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ext/hash_set>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
using namespace __gnu_cxx;
const int SEED = 133331;
hash_set<int> set;

const int MOVE = 0, THROW = 1, HOLD = 2;

struct Person {
	int at, used;
	int move, Throw;
	int idx;
	Person*hold;
	bool isHold;
	void read(int _idx) {
		idx = _idx;
		cin >> at >> move >> Throw;
		isHold = false;
		hold = 0;
		used = 0;
	}
	int hashCode() {
		return (at * 8 + used) * 4 + (hold == 0 ? 0 : hold->idx + 1);
	}
};

Person ps[3];

void readInput() {
	for (int i = 0; i < 3; ++i) {
		ps[i].read(i);
	}
}

int ans;

void dfs() {
	int code = 0;
	for (int i = 0; i < 3; ++i) {
		code = code * SEED + ps[i].hashCode();
	}
	if (!set.insert(code).second)
		return;
	for (int i = 0; i < 3; ++i) {
		ans = max(ans, ps[i].at);
	}
	for (int who = 0; who < 3; ++who) {
		Person&me = ps[who];
		if (me.isHold)
			continue;
		if ((~me.used >> MOVE & 1) && me.hold == 0) {
			for (int go = me.at - me.move; go <= me.at + me.move; ++go) {
				if (go == me.at || go <= 0)
					continue;
				bool check = true;
				for (int k = 0; k < 3; ++k) {
					if (k != who && ps[k].at == go) {
						check = false;
						break;
					}
				}
				if (check) {
					me.used |= 1 << MOVE;
					int tmp = me.at;
					me.at = go;
					dfs();
					me.at = tmp;
					me.used ^= 1 << MOVE;
				}
			}
		}
		if ((~me.used >> THROW & 1) && me.hold != 0) {
			for (int go = me.at - me.Throw; go <= me.at + me.Throw; ++go) {
				if (go == me.at || go <= 0)
					continue;
				bool check = true;
				for (int k = 0; k < 3; ++k) {
					if (k != who && ps[k].at == go) {
						check = false;
						break;
					}
				}
				if (check) {
					Person&hold = *me.hold;
					hold.at = go;
					hold.isHold = false;
					me.hold = 0;
					me.used |= 1 << THROW;
					dfs();
					me.used ^= 1 << THROW;
					me.hold = &hold;
					hold.isHold = true;
					hold.at = me.at;
				}
			}
		}
		if ((~me.used >> HOLD & 1)) {
			for (int where = me.at - 1; where <= me.at + 1; where += 2) {
				Person*p = 0;
				for (int k = 0; k < 3; ++k) {
					if (!ps[k].isHold && ps[k].at == where) {
						p = ps + k;
					}
				}
				if (p != 0) {
					p->isHold = true;
					me.hold = p;
					me.used |= 1 << HOLD;
					p->at = me.at;
					dfs();
					me.used ^= 1 << HOLD;
					me.hold = 0;
					p->isHold = false;
					p->at = where;
				}
			}
		}
	}
}

void work() {
	ans = 0;
	dfs();
	cout << ans << endl;
}

void solve() {
	readInput();
	work();
}

int main() {
	solve();
	return 0;
}