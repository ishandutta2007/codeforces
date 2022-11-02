/*
 * C. Moon Craters.cpp
 *
 *  Created on: 2011-9-2
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 2000 * 2 + 1;
short id[MAX_N][MAX_N];
short dp[MAX_N][MAX_N], how[MAX_N][MAX_N];
int n, nx;
int L[MAX_N], R[MAX_N];
map<int, int> mp;
vector<int> begin[MAX_N];
vector<int> end[MAX_N];

int calc(int l, int r) {
	short&ret = dp[l][r];
	short&ch = how[l][r];
	if (ret != -1)
		return ret;
	if (l >= r)
		return ret = 0;
	ret = 0;
	ch = -1;
	if (ret < calc(l + 1, r)) {
		ret = calc(l + 1, r);
		ch = l + 1;
	}
	if (ret < calc(l, r - 1)) {
		ret = calc(l, r - 1);
		ch = r - 1;
	}
	foreach(e,begin[l]) {
		int sp = R[*e];
		if (sp < r && ret < calc(l, sp) + calc(sp, r)) {
			ret = calc(l, sp) + calc(sp, r);
			ch = sp;
		}
	}
	foreach(e,end[r]) {
		int sp = L[*e];
		if (sp > l && ret < calc(l, sp) + calc(sp, r)) {
			ret = calc(l, sp) + calc(sp, r);
			ch = sp;
		}
	}
	if (id[l][r] != -1)
		++ret;
	return ret;
}

void print(int l, int r) {
	if (l < r && dp[l][r] > 0) {
		if (id[l][r] != -1)
			cout << id[l][r] + 1 << " ";
		if (how[l][r] == -1)
			return;
		print(l, how[l][r]);
		print(how[l][r], r);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int c, r;
		cin >> c >> r;
		L[i] = c - r, R[i] = c + r;
		mp[L[i]];
		mp[R[i]];
	}
	nx = 0;
	foreach(e,mp)
		e->second = nx++;
	memset(id, -1, sizeof id);
	for (int i = 0; i < n; ++i) {
		L[i] = mp[L[i]];
		R[i] = mp[R[i]];
		begin[L[i]].push_back(i);
		end[R[i]].push_back(i);
		id[L[i]][R[i]] = i;
	}
	memset(dp, -1, sizeof dp);
	cout << calc(0, nx - 1) << endl;
	print(0, nx - 1);
	return 0;
}