#include<bits/stdc++.h>
#define R register
#define LL long long
using namespace std;
const int N = 1e6 + 10;

int n, k, q;
int a[N], ord[N];
set<int> Set;
LL del[N << 2], buf[N << 2];

void read(int &x) {
	R char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	for (x = 0; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + c - '0';
}

void Merge(int x, int y, int z) {
	buf[x] = buf[y] + buf[z];
	buf[x] -= min(del[y], buf[z]);
//	if (del[y] >= buf[z])
//		buf[x] -= buf[z];
	del[x] = del[z] + max(0ll, del[y] - buf[z]);
}

void Build(int x, int l, int r) {
	del[x] = 0;
	buf[x] = r - l + 1;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	Build(x << 1, l, mid);
	Build(x << 1 | 1, mid + 1, r);
}

void Updata(int x, int l, int r, int pos) {
	if (l == r) {
		buf[x] = 0;
		del[x] = a[pos] - 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= pos)
		Updata(x << 1, l, mid, pos);
	if (mid < pos)
		Updata(x << 1 | 1, mid + 1, r, pos);
	Merge(x, x << 1, x << 1 | 1);
//	cout << x << ' ' << l << ' ' << r << ' ' << del[x] << ' ' << buf[x] << endl;
}

void Delete(int x, int l, int r, int pos) {
	if (l == r) {
		buf[x] = 1;
		del[x] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= pos)
		Delete(x << 1, l, mid, pos);
	if (mid < pos)
		Delete(x << 1 | 1, mid + 1, r, pos);
	Merge(x, x << 1, x << 1 | 1);
}

void dfs(int x, int l, int r) {
	cout << l << ' ' << r << ' ' << buf[x] << ' ' << del[x] << endl;
	if (l == r) return;
	int mid = (l + r) >> 1;
	dfs(x << 1, l, mid);
	dfs(x << 1 | 1, mid + 1, r);
}

void Query(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
//		cout << l << ' ' << r << ' ' << del[x] << ' ' << buf[x] << endl;
		if (del[0] + buf[0] == -2) {
			del[0] = del[x];
			buf[0] = buf[x];
		}
		else {
			Merge(0, 0, x);
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= ql)
		Query(x << 1, l, mid, ql, qr);
	if (mid < qr)
		Query(x << 1 | 1, mid + 1, r, ql, qr);
}

int m = 0;

int main() {
	read(q);
	Build(1, 1, N);
	while (q--) {
		int t, d;
		char c[3];
		scanf("%s", c);
		if (c[0] == '+') {
			read(t); read(d);
			a[t] = d;
			Set.insert(t);
			Updata(1, 1, N, t);
		}
		if (c[0] == '-') {
			read(t);
//			cout << t << ' ' << ord[t] << endl;
			Set.erase(ord[t]);
			a[ord[t]] = 0;
			Delete(1, 1, N, ord[t]);
		}
		if (c[0] == '?') {
			read(t);
			set<int>::iterator it;
			it = Set.upper_bound(t);
			if (it == Set.begin()) {
				puts("0");
			}
			else {
//				dfs(1, 1, N);
				--it;
				del[0] = buf[0] = -1;
				Query(1, 1, N, 1, *it);
				LL ps = del[0];
//			cout << ps << endl;
//				cout << del[0] << ' ' << buf[0] << endl;
				printf("%lld\n", max(0ll, (*it) + ps + 1 - t));
			}
		}
		ord[++m] = t;
	}
/*	puts("");
	for (int i = 1; i <= m; ++i)
		cout << ord[i] << ' ';
		puts("");*/
	return 0;
}