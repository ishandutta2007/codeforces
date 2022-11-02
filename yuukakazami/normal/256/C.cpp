#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long int64;
int n;

const int MAX_N = int(1e6);
int sg[MAX_N];
const int MAX_SG = 5;
int cnt[MAX_SG][MAX_N];

int eval(int64 x) {
	//x^(1/4),x^2
	int64 y = sqrt((double) x) - 2;
	if (y < 0)
		y = 0;
	while (y * y <= x)
		++y;
	--y;
	//y*y<=x
	if (y == x)
		--y;
	//y<x
	int64 z = sqrt(y) - 2;
	if (z < 0)
		z = 0;
	while (z * z * z * z < x)
		++z;
	//z^4>=x
	//z..y
	if (z > y)
		return 0;
	for (int k = 0; k < MAX_SG; ++k) {
		int c = cnt[k][y] - cnt[k][z - 1];
		if (c == 0)
			return k;
	}
	return MAX_SG;
}

int main() {
	sg[0] = sg[1] = 0;
	cnt[0][0] = 1;
	cnt[0][1] = 2;

	for (int i = 2; i < MAX_N; ++i) {
		sg[i] = eval(i);
		for (int j = 0; j < MAX_SG; ++j) {
			cnt[j][i] = cnt[j][i - 1];
		}
		cnt[sg[i]][i]++;
	}
	cin >> n;
	int xr = 0;
	for (int i = 0; i < n; ++i) {
		int64 a;
		cin >> a;
		if (a < MAX_N)
			xr ^= sg[a];
		else
			xr ^= eval(a);
	}
	if (xr)
		puts("Furlo");
	else
		puts("Rublo");
	return 0;
}