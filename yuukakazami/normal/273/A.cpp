/*
 * a.cpp
 *
 *  Created on: 2013-2-27
 *      Author: 
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <deque>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n;
int a[MAX_N];
typedef long long int64;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (i > 0)
			a[i] = max(a[i], a[i - 1]);
	}

	int nQ;
	cin >> nQ;
	int64 fst = a[0];
	while (nQ--) {
		int w, h;
		scanf("%d%d", &w, &h);
		int64 ret = max(int64(a[w - 1]), fst);
		cout << ret << endl;
		fst = ret + h;
	}
	return 0;
}