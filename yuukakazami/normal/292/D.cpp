#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

const int MAX_N = 500 + 10;
const int MAX_M = int(1e4) + 10;
const int MAX_K = int(2e4) + 10;
int n, m, nQ;

struct UF {
	vector<int> fa;
	void init(int n) {
		fa.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		if (fa[x] == x)
			return x;
		return fa[x] = find(fa[x]);
	}

	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b)
			return false;
		fa[a] = b;
		return true;
	}
};

UF L[MAX_M], R[MAX_M];

int a[MAX_M], b[MAX_M];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
		--a[i], --b[i];
	}

	L[0].init(n);
	for (int i = 1; i < m; ++i) {
		L[i] = L[i - 1];
		L[i].unite(a[i - 1], b[i - 1]);
	}

	R[m - 1].init(n);
	for (int i = m - 2; i >= 0; --i) {
		R[i] = R[i + 1];
		R[i].unite(a[i + 1], b[i + 1]);
	}

	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		//[l,r]
		UF u = L[l];
		for (int k = 0; k < n; ++k) {
			u.unite(k, R[r].fa[k]);
		}

		int nComp = 0;
		for (int k = 0; k < n; ++k) {
			if (u.fa[k] == k)
				++nComp;
		}

		printf("%d\n", nComp);
	}
}