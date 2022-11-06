#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;

long long int getans(long long int n) {
	if (n <= 1)return 0;
	if (n == 2)return 1;
	if (n == 3)return 1;
	if (n == 4)return 1;
	if (n == 5)return 2;
	long long int num = 1;
	long long int count = 0;
	while (num <= n) {
		num *= 2;
		count++;
	}
	long long int ans = ((count-1)*(count - 2)) / 2;

	long long int anum = num/4;
	long long int acount = 0;
	while (num-1-anum<=n) {
		anum /= 2;
		acount++;
		if (anum == 0)break;
	}
	ans += acount;
	return ans;
}
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>>field;

int memo[502][502];
int ruisekimemo[502][502];

int ykaburi[502][502];
int ruisekiykaburi[502][502];
int xkaburi[502][502];
int ruisekixkaburi[502][502];

int main() {
	memset(memo, 0, sizeof(memo));
	memset(ruisekimemo, 0, sizeof(ruisekimemo));
	memset(ykaburi, 0, sizeof(ykaburi));
	memset(ruisekiykaburi, 0, sizeof(ruisekiykaburi));
	memset(xkaburi, 0, sizeof(xkaburi));
	memset(ruisekixkaburi, 0, sizeof(ruisekixkaburi));

	int h, w; cin >> h >> w;
	field.resize(h + 2);
	field[0].resize(w + 2);
	field[h + 1].resize(w + 2);
	for (int i = 0; i < 2*h+2; i+=h+1) {

		for (int j = 0; j <w+2; ++j) {
			field[i][j] = 1;
		}
	}
	for (int i = 0; i < h; ++i) {
		string st; cin >> st;
		field[i+1].push_back(true);
		for (int j = 0; j < st.size(); ++j) {
			if (st[j] == '.') {
				field[i + 1].push_back(false);
			}
			else {
				field[i + 1].push_back(true);
			}
		}
		field[i + 1].push_back(true);
	}
	//for (int y = 1; y <= h; ++y) {
	//	for (int x = 1; x <= w; ++x) {
	//		for (int i = 1; i < 3; ++i) {
	//			if (!field[y][x] && !field[y + dy[i]][x + dx[i]]) {
	//				memo[y][x]++;
	//			}
	//		}
	//	}
	//}
	for (int y = 1; y <= h; ++y) {
		for (int x = 1; x <= w; ++x) {
			if (!field[y][x] && !field[y -1][x]) {
				ykaburi[y][x]++;
			}
			
		}
	}
	for (int y = 1; y <= h; ++y) {
		for (int x = 1; x <= w; ++x) {
			if (!field[y][x] && !field[y][x - 1]) {
				xkaburi[y][x]++;
			}
			
		}
	}
	for (int y = 1; y <= h; ++y) {
		for (int x = 1; x <= w; ++x) {
			//ruisekimemo[y][x] = ruisekimemo[y][x - 1] + ruisekimemo[y - 1][x] - ruisekimemo[y - 1][x - 1] + memo[y][x];
			ruisekiykaburi[y][x] = ruisekiykaburi[y - 1][x]+ruisekiykaburi[y][x - 1]-ruisekiykaburi[y-1][x-1] +ykaburi[y][x];
		}
	}
	for (int x = 1; x <= w; ++x) {
		for (int y = 1; y <= h; ++y) {
			ruisekixkaburi[y][x] = ruisekixkaburi[y - 1][x] + ruisekixkaburi[y][x - 1] - ruisekixkaburi[y - 1][x - 1] + xkaburi[y][x];
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, l, d, r; cin >> u >> l >> d >> r;
		int ykabu = ruisekiykaburi[d][r] - ruisekiykaburi[u][r] - ruisekiykaburi[d][l - 1] + ruisekiykaburi[u][l - 1];
		int xkabu = ruisekixkaburi[d][r] - ruisekixkaburi[d][l] - ruisekixkaburi[u-1][r] + ruisekixkaburi[u - 1][l];
		int ans = ykabu + xkabu;
		cout << ans << endl;
	}
	return 0;
}