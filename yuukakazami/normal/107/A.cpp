/*
 * a.cpp
 *
 *  Created on: 2011-8-23
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 1000 + 10;
int in[MAX_N] = { }, out[MAX_N] = { };
int C[MAX_N][MAX_N];
int n;
typedef pair<int, int> ipair;

int main() {
	int e;
	cin >> n >> e;
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		C[a][b] = c;
		in[b] = a;
		out[a] = b;
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0) {
			if (out[i] != 0) {
				++cnt;
			}
		}
	}

	cout << cnt << endl;
	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0) {
			if (out[i] != 0) {
				int mind = INT_MAX;
				int u = i;
				while (true) {
					int v = out[u];
					if (!v)
						break;
					mind = min(mind, C[u][v]);
					u = v;
				}
				cout << i << " " << u << " " << mind << endl;
			}
		}
	}
	return 0;
}