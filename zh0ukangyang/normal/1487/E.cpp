#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int N = 2e5 + 7;
const int inf = 1e9;
int val, n1, n2, n3, n4, k;
int m, sav[N];
struct node {
	int val, id, dp;
} a[N], b[N], c[N], d[N];
bool operator < (node aa, node bb) {
	return aa.dp < bb.dp;
}
map<int, bool> vb[N]; 
void work1() {
	sort(a + 1, a + n1 + 1);
	cin >> m;
	for(int i = 1, u, v; i <= m; i++) cin >> u >> v, vb[v][u] = true;
	for(int i = 1; i <= n2; i++) {
		b[i].dp = 1e9; 
		for(int now = 1; now <= n1; now++) 
			if(!vb[i][a[now].id]) {
				b[i].dp = a[now].dp + b[i].val;
				break;
			} 
	}
	for(int i = 1; i <= n2; i++) vb[i].clear();
}
void work2() {
	sort(b + 1, b + n2 + 1), cin >> m;
	for(int i = 1, u, v; i <= m; i++) cin >> u >> v, vb[v][u] = true;
	for(int i = 1; i <= n3; i++) {
		c[i].dp = 1e9; 
		for(int now = 1; now <= n2; now++) 
			if(!vb[i][b[now].id]) {
				c[i].dp = b[now].dp + c[i].val;
				break;
			} 
	}
	for(int i = 1; i <= n3; i++) vb[i].clear();
}
void work3() {
	sort(c + 1, c + n3 + 1), cin >> m;
	for(int i = 1, u, v; i <= m; i++) cin >> u >> v, vb[v][u] = true;
	for(int i = 1; i <= n4; i++) {
		d[i].dp = 1e9; 
		for(int now = 1; now <= n3; now++) 
			if(!vb[i][c[now].id]) {
				d[i].dp = c[now].dp + d[i].val;
				break;
			} 
	}
}
void Main() {
	cin >> n1 >> n2 >> n3 >> n4;
	for(int i = 1; i <= n1; i++) a[i].id = i, cin >> a[i].val, a[i].dp = a[i].val;
	for(int i = 1; i <= n2; i++) b[i].id = i, cin >> b[i].val;
	for(int i = 1; i <= n3; i++) c[i].id = i, cin >> c[i].val;
	for(int i = 1; i <= n4; i++) d[i].id = i, cin >> d[i].val;
	work1(), work2(), work3();
	int ans = 1e9;
	for(int i = 1; i <= n4; i++) ans = min(ans, d[i].dp);
	if(ans == 1e9) cout << "-1\n";
	else cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}