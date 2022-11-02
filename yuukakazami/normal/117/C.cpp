#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 5000 + 10;
bool E[MAX_N][MAX_N];
int nV;
bool inStack[MAX_N];
int ord[MAX_N], cur;
vector<int> stack, cycle;

void dfs(int u, int fa) {
	ord[u] = cur++;
	stack.push_back(u);
	inStack[u] = true;
	for (int v = 0; v < nV; ++v) {
		if (v != fa && E[u][v]) {
			if (ord[v] == -1)
				dfs(v, u);
			else if (inStack[v]) {
				//to anc
				for (;;) {
					int t = stack.back();
					stack.pop_back();
					cycle.push_back(t);
					if (t == v)
						break;
				}
				reverse(cycle.begin(), cycle.end());
				throw 1;
			}
		}
	}
	stack.pop_back();
	inStack[u] = false;
}

int main() {
	cin >> nV;
	for (int i = 0; i < nV; ++i) {
		scanf(" ");
		char buf[MAX_N];
		scanf("%s", buf);
		for (int j = 0; j < nV; ++j) {
			E[i][j] = buf[j] == '1';
		}
	}
	memset(ord, -1, sizeof ord);
	try {
		for (int i = 0; i < nV; ++i) {
			if (ord[i] == -1)
				dfs(i, -1);
		}
	} catch (int e) {
		for (;;) {
			int a = cycle[0], b = cycle[1], c = cycle[2];
			//a->b->c
			if (E[c][a]) {
				cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
				return 0;
			} else {
				//a->c
				cycle.erase(cycle.begin() + 1);
			}
		}
	}
	cout << -1 << endl;
	return 0;
}