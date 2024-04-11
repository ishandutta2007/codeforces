/*
 * c.cpp
 *
 *  Created on: 2011-9-11
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <bitset>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = int(3e8) + 10;
bitset<MAX_N> p;

int main() {
	int l, r;
	cin >> l >> r;
	p.set();
	int j;
	for (int i = 3; (j = i * i) <= r; i += 2)
		if (p[i])
			for (; j <= r; j += i + i)
				p[j] = false;
	int ans = 0;
	for (int i = 5; i <= r; i += 4)
		if (i >= l && p[i])
			++ans;
	if (l <= 2 && 2 <= r)
		++ans;
	cout << ans << endl;
	return 0;
}