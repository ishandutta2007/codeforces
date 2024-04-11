/*
 * d.cpp
 *
 *  Created on: 2011-8-7
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 3e5 + 10;
const int MAX_S = 600;
typedef long long int64;
int64 w[MAX_N];
int n;
int64 ans[MAX_N];
int a[MAX_N], b[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", w + i);
	}
	int nQ;
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		::a[i] = a, ::b[i] = b;
		if (b >= MAX_S) {
			int64 ret = 0;
			for (int j = a; j < n; j += b)
				ret += w[j];
			ans[i] = ret;
		}
	}
	for (int b = 1; b < MAX_S; ++b) {
		static int64 f[MAX_N];
		for (int i = n - 1; i >= 0; --i) {
			f[i] = w[i];
			if (i + b < n)
				f[i] += f[i + b];
		}
		for (int i = 0; i < nQ; ++i) {
			if (::b[i] == b)
				ans[i] = f[a[i]];
		}
	}

	for (int i = 0; i < nQ; ++i) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}