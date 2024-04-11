/*		b.cpp
 *		Created on: 29.02.2012
 *      Author: zemen
 */

#include <algorithm>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define INF __INT_MAX__
#define PI M_PIl

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

int a[100000];
int c[100000];
char liar[100000];
vector <int> g[100000];

int main(int argc, char **argv) {
	int n, m, initc = 0;
	memset(c, 0, sizeof(c));
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		char q;
		scanf("%c%d\n", &q, a + i);
		a[i]--;
		if (q == '+') {
			liar[i] = 1;
			c[a[i]]++;
		} else {
			liar[i] = 0;
			c[a[i]]--;
			++initc;
		}
		g[a[i]].push_back(i);
	}
	int w = -1;
	cerr << initc << endl;
	for (int i = 0; i < n; ++i)
		cerr << c[i] << endl;
	for (int i = 0; i < n; ++i)
		if (initc + c[i] == m) {
			if (w == -1)
				w = i;
			else {
				w = -1;
				break;
			}
		}
	if (w != -1) {
		for (int i = 0; i < (int)g[w].size(); ++i)
			liar[g[w][i]] ^= 1;
	} else {
		for (int i = 0; i < n; ++i)
			if (initc + c[i] == m) {
				for (int j = 0; j < (int)g[i].size(); ++j)
					liar[g[i][j]] = 2;
			}
	}
	for (int i = 0; i < n; ++i)
		printf("%s\n", ((liar[i] == 0) ? "Truth" : ((liar[i] == 1) ? "Lie" : "Not defined")));
}