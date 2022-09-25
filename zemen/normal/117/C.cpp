/*
 *
 *  Codeforces Beta Round #88
 *  Problem C
 *
 *  Created on: 23.09.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>

using namespace std;

bool g[5001][5001];
int used[5001];
int stack[5001];
int cnt = 0;
int n;

void findc(int b) {
	if (b == cnt - 3) {
		printf("%d %d %d", stack[cnt - 3] + 1, stack[cnt - 2] + 1, stack[cnt - 1] + 1);
		exit(0);
	}
	if (g[stack[b + 1]][stack[cnt - 1]]) {
		printf("%d %d %d", stack[b] + 1, stack[b + 1] + 1, stack[cnt - 1] + 1);
		exit(0);
	} else {
		findc(b + 1);
	}
}

int findinstack(int e) {
	int cur = 0;
	while (stack[cur] != e)
		++cur;
	return cur;
}

void dfs(int k) {
	used[k] = 1;
	stack[cnt++] = k;
	for (int i = 0; i < n; ++i) {
		if (g[k][i] && used[i] == 1)
			findc(findinstack(i));
		else
			if (g[k][i] && used[i] == 0)
				dfs(i);
	}
	--cnt;
	used[k] = 2;
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			g[i][j] = (getchar() == '1');
		}
		getchar();
	}
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs(i);
	printf("-1");
}