#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using namespace __gnu_cxx;
const int MAX_N = 300 + 10;
int n, m;
int color[MAX_N][MAX_N], symbol[MAX_N][MAX_N];
int order[MAX_N * 2][MAX_N * 2], nId = 0;
//URDL
const int DI[] = { -1, 0, 1, 0 }, DJ[] = { 0, 1, 0, -1 };
int fa[MAX_N * MAX_N];
int col[MAX_N * MAX_N];
int size[MAX_N * MAX_N];
struct Symbols {
	Symbols*l, *r;
	int v;
	Symbols(Symbols*l, Symbols*r) :
			l(l), r(r), v(-1) {
	}
	Symbols(int v) :
			l(0), r(0), v(v) {
	}
	void write(vector<int>&a) {
		if (v == -1) {
			if (l)
				l->write(a);
			if (r)
				r->write(a);
		} else {
			a.push_back(v);
		}
	}
};
Symbols*mySymbol[MAX_N * MAX_N];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void unite(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)
		return;
	fa[b] = a;
	size[a] += size[b];
	mySymbol[a] = new Symbols(mySymbol[a], mySymbol[b]);
}

int main() {
	cin >> n >> m;
	map<int, int> id;
	for (int i = 0; i < n * m; ++i) {
		fa[i] = i;
		mySymbol[i] = new Symbols(i);
		size[i] = 1;
	}
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cin >> color[r][c];
			if (id.count(color[r][c])) {
				unite(id[color[r][c]], r * m + c);
			} else {
				id[color[r][c]] = r * m + c;
				col[r * m + c] = color[r][c];
			}
		}
	}
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cin >> symbol[r][c];
		}
	}
	int r = MAX_N, c = MAX_N;
	memset(order, -1, sizeof order);
	int dir = 0;
	for (;;) {
		//move one step then turn right if we can
		order[r][c] = nId++;
		r += DI[dir], c += DJ[dir];
		if (r < 0 || r >= MAX_N * 2 || c < 0 || c >= MAX_N * 2)
			break;
		int ndir = (dir + 1) % 4;
		int nr = r + DI[ndir], nc = c + DJ[ndir];
		if (order[nr][nc] == -1) {
			dir = ndir;
		}
	}
	int x, y;
	cin >> x >> y;
	--x, --y;
	queue<int> que;
	que.push(x * m + y);
	long long ans = 0;
	while (!que.empty()) {
		int r = que.front() / m;
		int c = que.front() % m;
		que.pop();
		int me = r * m + c, rt = find(me);
		int myCol = col[rt], sym = symbol[r][c];
		if (myCol != 0 && myCol != sym && sym != -1) {
			//paint all myCol to symbol!
			//get all symbol on them
			vector<int> a;
			mySymbol[rt]->write(a);
			mySymbol[rt] = new Symbols(-1);
			ans += size[rt];
			id.erase(col[rt]);
			if (id.count(sym))
				unite(id[sym], rt);
			else {
				id[sym] = rt;
				col[rt] = sym;
			}
			vector<pair<int, int> > lst;
			for (int i = 0; i < a.size(); ++i) {
				int cr = a[i] / m, cc = a[i] % m;
				int ord = order[cr - r + MAX_N][cc - c + MAX_N];
				lst.push_back(make_pair(ord, a[i]));
			}
			sort(lst.begin(), lst.end());
			for (int i = 0; i < lst.size(); ++i) {
				if (lst[i].second != me) {
					que.push(lst[i].second);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}