/*
 * b.cpp
 *
 *  Created on: 2011-8-7
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
bool E[101][101];
int nV;

vector<int> stack, cyc;
bool visited[101] = { };
bool findCycle(int u, int fa) {
	if (visited[u]) {
		for (;;) {
			int v = stack.back();
			stack.pop_back();
			cyc.push_back(v);
			if (v == u)
				break;
		}
		return true;
	}

	visited[u] = true;
	stack.push_back(u);
	for (int v = 0; v < nV; ++v) {
		if (E[u][v] && v != fa && findCycle(v, u))
			return true;
	}
	stack.pop_back();
	return false;
}

int nComp;
void dfs(int u) {
	if (visited[u])
		return;
	visited[u] = true;
	for (int v = 0; v < nV; ++v) {
		if (E[u][v])
			dfs(v);
	}
}

int calcComp() {
	memset(visited, false, sizeof visited);
	nComp = 0;
	for (int i = 0; i < nV; ++i) {
		if (!visited[i]) {
			nComp++;
			dfs(i);
		}
	}
	return nComp;
}

int main() {
	cin >> nV;
	int nE;
	cin >> nE;
	for (int i = 0; i < nE; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		E[a][b] = E[b][a] = true;
	}
	if (calcComp() > 1) {
		puts("NO");
		return 0;
	}
	memset(visited, false, sizeof visited);
	if (!findCycle(0, -1)) {
		puts("NO");
		return 0;
	}
	int n = cyc.size();
	for (int i = 0; i < n; ++i) {
		int u = cyc[i];
		E[u][cyc[(i + 1) % n]] = false;
		E[cyc[(i + 1) % n]][u] = false;
	}
	if (calcComp() != n) {
		puts("NO");
		return 0;
	}
	memset(visited, false, sizeof visited);
	for (int i = 0; i < n; ++i) {
		int u = cyc[i];
		stack.clear();
		if (findCycle(u, -1)) {
			puts("NO");
			return 0;
		}
	}
	puts("FHTAGN!");
	return 0;
}