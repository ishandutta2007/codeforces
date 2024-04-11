/*
 * main.cpp
 *
 *  Created on: 28.08.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <algorithm>

#define INF 10000

int n, m;
int pow3[10];
int answ = INF;
int d[30000][42];
char a[10];

using namespace std;

int hash(int pos) {
	int res = pos;
	for (int i = 0; i < m; ++i) {
		res *= 3;
		res += a[i];
	}
	return res;
}

void unhash(int hsh, int &pos) {
	for (int i = m - 1; i >= 0; --i) {
		a[i] = hsh % 3;
		hsh /= 3;
	}
	pos = hsh;
}

void getmin(int k) {
	if (k == m) {
		int hsh = hash(0);
		if (answ > d[hsh][n])
			answ = d[hsh][n];
		return;
	}
	a[k] = 0;
	getmin(k + 1);
	a[k] = 1;
	getmin(k + 1);
}

int main() {
	pow3[0] = 1;
	for (int i = 1; i < 10; ++i)
		pow3[i] = pow3[i - 1] * 3;
	scanf("%d%d", &n, &m);
	if (n < m)
		swap(n, m);
	for (int i = 0; i < n + 1; ++i)
		for (int j = 0; j < m * pow3[m]; ++j) {
			d[j][i] = INF;
		}
	d[0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m * pow3[m]; ++j) {
			if (d[j][i] == INF)
				continue;
			int pos;
			unhash(j, pos);
			a[pos] = 1;
			if (pos > 0 && a[pos - 1] == 2)
				a[pos - 1] = 0;
			int nh = hash((pos + 1) % m);
			if (pos == m - 1) {
				if (d[nh][i + 1] > d[j][i] + 1)
					d[nh][i + 1] = d[j][i] + 1;
			} else {
				if (d[nh][i] > d[j][i] + 1)
					d[nh][i] = d[j][i] + 1;
			}
			unhash(j, pos);
			if (a[pos] == 2)
				continue;
			if (i == n - 1 && pos > 0 && a[pos - 1] == 2)
				continue;
			bool t = 0;
			if (a[pos] == 1)
				t = 1;
			if (pos > 0 && a[pos - 1] == 1)
				t = 1;
			if (t)
				a[pos] = 0;
			else
				a[pos] = 2;
			nh = hash((pos + 1) % m);
			if (pos == m - 1) {
				if (d[nh][i + 1] > d[j][i])
					d[nh][i + 1] = d[j][i];
			} else {
				if (d[nh][i] > d[j][i])
					d[nh][i] = d[j][i];
			}
		}
	getmin(0);
	printf("%d", m * n - answ);
}