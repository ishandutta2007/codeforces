#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair

const int N = 100000 + 10;
const int M = 100000 + 10;
struct Cost;
vector<Cost*> csts;

struct Cost {
	int c;
	Cost*a, *b; //a-b
	int id;
	int nUsed;

	bool operator<(Cost o) const { return c < o.c; }
	Cost(int c, int id) {
		this->c = c;this->id = id;a = b = 0;nUsed = 0;
		csts.push_back(this);
	}

	Cost(Cost*a, Cost*b) {
		this->a = a;this->b = b;id = -1;c = a->c - b->c;nUsed = 0;
		csts.push_back(this);
	}

	void push() {
		if (id == -1) {
			a->nUsed += nUsed;
			b->nUsed -= nUsed;
		}
	}

	void useIt() {++nUsed;}
};

struct edge {
	int u, v;
	Cost* cost;
	edge() {
	}
	edge(int u, int v, int c, int id) :
			u(u), v(v) {
		cost = new Cost(c, id);
	}
} e[M];

int pre[N], hash1[N], vis[N];
Cost* In[N];

bool better(Cost*a, Cost*b) { //a better than b?
	if (a == 0 || b == 0)
		return b == 0;
	return a->c < b->c;
}
int Directed_MST(int root, int n, int m) {
	int ret = 0;
	while (true) {
		rep(i,0,n) In[i] = 0;
		rep(i,0,m) {
			int u = e[i].u; int v = e[i].v;
			if (better(e[i].cost, In[v]) && u != v) {
				pre[v] = u;
				In[v] = e[i].cost;
			}
		}
		rep(i,0,n) {
			if (i == root) continue;
			if (In[i] == 0) return -1;
		}
		int cntnode = 0;
		memset(hash1, -1, sizeof(int) * n);
		memset(vis, -1, sizeof(int) * n);

		rep(i,0,n) if (i != root) {
			ret += In[i]->c;
			In[i]->useIt();
			int v = i;
			while (vis[v] != i && hash1[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if (v != root && hash1[v] == -1) {
				for (int u = pre[v]; u != v; u = pre[u])
					hash1[u] = cntnode;
				hash1[v] = cntnode++;
			}
		}
		if (cntnode == 0)
			break;
		rep(i,0,n)
			if (hash1[i] == -1)
				hash1[i] = cntnode++;
		rep(i,0,m) {
			int v = e[i].v;
			e[i].u = hash1[e[i].u];
			e[i].v = hash1[e[i].v];
			if (e[i].u != e[i].v) {
				e[i].cost = new Cost(e[i].cost, In[v]);
			}
		}
		n = cntnode;
		root = hash1[root];
	}
	return ret;
}
int n, m;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	int mm = 0;
	rep(i,0,m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		e[mm++] = edge(a, b, c, i + 1);
	}
	int ans = Directed_MST(0, n, mm);
	if (ans == -1)
		puts("-1");
	else {
		cout << ans << endl;
		per(i,0,csts.size()) csts[i]->push();
		vector<int> lst;
		rep(i,0,csts.size()) {
			Cost*c = csts[i];
			if (c->id != -1 && c->c > 0 && c->nUsed > 0) {
				lst.push_back(c->id);
			}
		}
		sort(lst.begin(), lst.end());
		rep(i,0,lst.size()) {
			cout << lst[i] << " ";
		}
		cout << endl;
	}
	return 0;
}