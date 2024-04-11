#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int m;
struct Edge {
	int t, id;
	Edge(int t, int id) :
			t(t), id(id) {
	}
};
const int MAX_N = 10000 + 10;
vector<Edge> e[MAX_N];

int comp[MAX_N];
void dfs(int u, int c) {
	if (comp[u] != -1)
		return;
	comp[u] = c;
	for (vector<Edge>::iterator it = e[u].begin(); it != e[u].end(); ++it) {
		dfs(it->t, c);
	}
}

void bad() {
	puts("-1");
	exit(0);
}

bool used[MAX_N];
int at[MAX_N];
vector<int> path;

void euler(int u) {
	while (at[u] < e[u].size()) {
		int v = e[u][at[u]].t;
		int id = e[u][at[u]++].id;
		if (used[id])
			continue;
		used[id] = true;
		euler(v);
		path.push_back(id);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(Edge(b, i));
		e[b].push_back(Edge(a, i));
	}
	memset(comp, -1, sizeof comp);
	vector<int> comps;
	for (int i = 0; i < MAX_N; ++i)
		if (comp[i] == -1 && e[i].size() > 0) {
			dfs(i, i);
			comps.push_back(i);
		}

	if (comps.size() > 2)
		bad();

	vector<int> odds;
	for (int i = 0; i < MAX_N; ++i) {
		if (e[i].size() % 2 == 1)
			odds.push_back(i);
	}

	if (odds.size() > 4)
		bad();

	vector<int> ans1, ans2;

	if (comps.size() == 2) {
		vector<int> o1, o2;
		for (vector<int>::iterator e = odds.begin(); e != odds.end(); ++e) {
			if (comp[*e] == comps[0])
				o1.push_back(*e);
			else
				o2.push_back(*e);
		}
		if (o1.size() > 2 || o2.size() > 2)
			bad();
		o1.push_back(comps[0]), o2.push_back(comps[1]);
		euler(o1[0]), ans1 = path;
		path.clear();
		euler(o2[0]), ans2 = path;
		path.clear();
	} else {
		if (odds.size() <= 2) {
			odds.push_back(comps[0]);
			euler(odds[0]);
			ans1 = path;
			if (ans1.size() < 2)
				bad();
			ans2.push_back(ans1.back());
			ans1.pop_back();
		} else {
			int x = odds[2], y = odds[3];
			e[x].push_back(Edge(y, MAX_N - 1));
			e[y].push_back(Edge(x, MAX_N - 1));
			euler(odds[0]);
			bool hap = false;
			for (vector<int>::iterator e = path.begin(); e != path.end(); ++e) {
				if (*e == MAX_N - 1)
					hap = true;
				else if (hap)
					ans1.push_back(*e);
				else
					ans2.push_back(*e);
			}
		}
	}

	cout << ans1.size() << endl;
	for (int i = 0; i < ans1.size(); ++i) {
		cout << ans1[i] + 1 << " ";
	}
	cout << endl;
	cout << ans2.size() << endl;
	for (int i = 0; i < ans2.size(); ++i) {
		cout << ans2[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}