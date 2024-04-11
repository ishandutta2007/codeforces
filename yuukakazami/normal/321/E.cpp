/*
 * e.cpp
 *
 *  Created on: 2013-6-29
 *      Author: 
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

const int MAX_N = 4000 + 10, MAX_K = 800 + 10;

int dp[MAX_K][MAX_N], n, k;
int U[MAX_N][MAX_N];

const int INF = ~0U >> 3;

struct node {
	int l, r, ch;
	node() {
	}
	node(int _l, int _r, int _ch) :
			l(_l), r(_r), ch(_ch) {
	}
};

int Prev[MAX_N], Dp[MAX_N];
int top = 0;
int Cost(int l, int r) {
	return U[l - 1][r - 1];
}

int Get(int i, int j) {
	if (j >= i)
		return INF;
	return Prev[j] + Cost(j + 1, i);
}
int binary(node t, int i) {
	int l = t.l, r = t.r;
#define check(m) (Get(m,t.ch)<Get(m,i))
	if (check(r))
		return r;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	return l;
#undef check
}

void oneStep() {
	Dp[0] = 0;
	deque<node> D;
	D.push_back(node(1, n, 0));
	for (int i = 1; i <= n; i++) {
		Dp[i] = Get(i, D.front().ch);
		if (D.front().l < D.front().r)
			D.front().l++;
		else
			D.pop_front();
		node t;
		int e;
		while (D.size()) {
			t = D.back();
			if (Get(t.l, i) <= Get(t.l, t.ch)) {
				D.pop_back();
			} else {
				e = binary(t, i);
				D.back().r = e;
				break;
			}
		}
		if (D.size() == 0)
			D.push_back(node(i + 1, n, i));
		else if (e < n)
			D.push_back(node(e + 1, n, i));
	}
}

int main() {
	cin >> n >> k;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			char ch;
			while (ch = getchar(), (ch < '0' || ch > '9'))
				;
			U[r][c] = ch - '0';
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 2; j < n; ++j) {
			U[i][j] += U[i + 1][j] + U[i][j - 1] - U[i + 1][j - 1];
		}
	}

	//k=1
	Dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		Dp[i] = Cost(1, i);
	}
	memcpy(Prev, Dp, sizeof(int) * (n + 1));

	for (int i = 2; i <= k; ++i) {
		oneStep();
		memcpy(Prev, Dp, sizeof(int) * (n + 1));
	}
	cout << Dp[n] << endl;
	return 0;
}