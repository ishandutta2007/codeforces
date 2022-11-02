/*
 * d.cpp
 *
 *  Created on: 2012-6-12
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cstdlib>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

string s;

string ans;

typedef long long int64;

const int MAX_N = int(4e5) + 10;

int d, n;

typedef int64 HASH;
typedef char CHAR;

const HASH SEED = 133331;

struct H {
	int64 h, p;
	H(char c) {
		h = c;
		p = SEED;
	}
	H() {
		h = 0;
		p = 1;
	}
	H(int64 _h, int64 _p) :
			h(_h), p(_p) {
	}
};

H operator +(H a, H b) {
	return H(a.h * b.p + b.h, a.p * b.p);
}

bool operator==(H a, H b) {
	return a.h == b.h;
}

struct Tree {
	Tree*pl, *pr;
	int l, r;
	H v, rv;

	inline int get(int a, int b) {
		return 0;
	}
	void update() {
		v = pl->v + pr->v;
		rv = pr->rv + pl->rv;
	}
	void relax() {
	}
	void apply(int x) {
	}
	Tree(int _l, int _r) :
			l(_l), r(_r) {
		int m = (l + r) >> 1;
		if (l + 1 == r) {
			pl = pr = 0;
			v = H(0);
			return;
		}
		pl = new Tree(l, m);
		pr = new Tree(m, r);
		update();
	}

	H askV(int L, int R) {
		if (L >= r || l >= R)
			return H();
		if (L <= l && R >= r) {
			return v;
		}
		return pl->askV(L, R) + pr->askV(L, R);
	}

	H askRV(int L, int R) {
		if (L >= r || l >= R)
			return H();
		if (L <= l && R >= r) {
			return rv;
		}
		return pr->askRV(L, R) + pl->askRV(L, R);
	}

	void changeAt(int at, char c) {
		if (l + 1 == r) {
			v = rv = H(c);
			return;
		}
		int m = l + r >> 1;
		if (at < m)
			pl->changeAt(at, c);
		else
			pr->changeAt(at, c);
		update();
	}
}*rt;

bool isPlain2(int l, int r) {
	return rt->askV(l, r) == rt->askRV(l, r);
}

char ret[MAX_N];
void rec(int i, bool same) {
	if (i == n) {
		throw 1;
	}
	for (char a = same ? s[i] : 'a'; a <= 'z'; ++a) {
		rt->changeAt(i, a);
		if (i - d + 1 >= 0 && isPlain2(i - d + 1, i + 1))
			continue;
		if (i - d >= 0 && isPlain2(i - d, i + 1))
			continue;
		ret[i] = a;
		rec(i + 1, same && a == s[i]);
	}
}

int main() {
	cin >> d;
	cin >> s;
	ans = "";
	n = s.size();
	if (count(s.begin(), s.end(), 'z') == n) {
		puts("Impossible");
		return 0;
	}
	rt = new Tree(0, n);

	//add s by 1
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] != 'z') {
			++s[i];
			for (int j = i + 1; j < n; ++j) {
				s[j] = 'a';
			}
			break;
		}
	}
	try {
		rec(0, true);
	} catch (int e) {
		puts(ret);
		return 0;
	}
	puts("Impossible");

	return 0;
}