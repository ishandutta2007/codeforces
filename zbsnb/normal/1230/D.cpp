/*
#include<iostream>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
ll a[100010],dep[100010];

struct nod {
int u, v, nxt;
}e[200010];
int head[100010], cnt;
void add(int u,int v) {
e[++cnt] = { u,v,head[u] };
head[u] = cnt;
}

ll gcd(ll a, ll b) {
return b ? gcd(b, a%b) : a;
}

ll ans = 0;
void dfs(int u, int fa) {
ans += a[u];
dep[u] = dep[fa] + 1;
a[u]=gcd(a[u], a[fa]);
for (int i = head[u]; i; i = e[i].nxt) {
int v = e[i].nxt;
if (v == fa)continue;
dfs(v, u);
}
}
int main() {
int n; cin >> n;
for (int i = 1; i <= n; i++) {
cin >> a[i];
}
for (int i = 1; i < n; i++) {
int a, b; cin >> a >> b;
add(a, b); add(b, a);
}
dep[1] = 1;
dfs(1, 0);
ll ans = 0;
for (int i = 1; i <= n; i++) {
cout << i << " " << a[i] << " " << dep[i] << endl;
ans += a[i]*dep[i]%mod;
}
cout << ans%mod << endl;
}
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
struct nod {
	ll a, b;
}e[7010];
vector<int> vec[7010];
int sum[7010];
int main() {
	int n; cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) cin >> e[i].a;
	for (int i = 1; i <= n; i++) cin >> e[i].b, ans += e[i].b;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (e[i].a ^ (e[i].a&e[j].a))vec[j].push_back(i),sum[i]++;
			if (e[j].a ^ (e[i].a&e[j].a))vec[i].push_back(j),sum[j]++;
		}
	}
	/*
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)cout << sum[i] << " "; cout << endl;
	
	*/

	int now = n;
	for (int k = 1; k <= n; k++) {
		if (now == 1) {
			ans = 0;
			break;
		}
		int flg = 1;
		for (int i = 1; i <= n; i++) {
			if (sum[i] == now - 1) {
				ans -= e[i].b;
				sum[i] = 0;
				now--;
				flg = 0;
				for (int j = 0; j < vec[i].size(); j++) {
					sum[vec[i][j]]--;
				}
				break;
			}
		}
		if (flg)break;
	}

	cout << ans << endl;
}