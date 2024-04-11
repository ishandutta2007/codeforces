#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long 
ll a[100010]; int n;
int ct[64];
struct nod {
	int u, v, nxt;
}e[1000];
int head[1000], cnt;
void add(int u, int v) {
	e[++cnt] = { u,v,head[u] };
	head[u] = cnt;
}

int vis[1000];

int dfs(int u,int fa,int dep) {
	//cout << u << " " << dep << endl;
	if (vis[u]) return dep - vis[u] >= 3 ? dep - vis[u] : 1e9;
	//cout << "vis u:" << u << " " << dep << endl;
	vis[u] = dep;
	int ret = 1e9;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fa)continue;
		ret = min(ret, dfs(v, u, dep + 1));
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; if (a[i] == 0)n--,i--;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 64; j++) {
			if (a[i] & (1ll << j)) {
				ct[j]++;
				if (ct[j] >= 3) {
					cout << 3 << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if ((a[i] & a[j]) != 0) {
				add(i, j);
			}
		}
	}

	//for (int i = 1; i <= cnt; i++) cout << e[i].u << " " << e[i].v << endl;cout << endl;

	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		///cout << "i:" << i << endl;
		for (int i = 1; i <= n; i++)vis[i] = 0;
		ans = min(ans, dfs(i, 0, 1));
	}
	if (ans == 1e9)cout << -1 << endl;
	else cout << ans << endl;
}