#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
const db eps = 1e-5;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f; 
}
char p[N][5], s[N][5];
int n, m, k, mt[N], deg[N], Pow[N];
vector<int> e[N];
int ans[N], tot;
map<int, int> mp;
int main() {
	Pow[0] = 1;
	Pow[1] = 27;
	Pow[2] = 27 * 27;
	Pow[3] = 27 * 27 * 27;
	
	n = read(), m = read(), k = read();
	L(i, 1, n) {
		scanf("%s", p[i] + 1);
		int res = 0;
		L(j, 1, k) if(p[i][j] != '_') res += Pow[j - 1] * (p[i][j] - 'a' + 1);
		mp[res] = i;
	}
	L(i, 1, m) {
		scanf("%s%d", s[i] + 1, &mt[i]);
		L(t, 1, k) if(p[mt[i]][t] != '_' && p[mt[i]][t] != s[i][t]) return puts("NO"), 0;
		L(j, 0, (1 << k) - 1) {
			int res = 0;
			L(t, 1, k) if(j >> (t - 1) & 1) res += Pow[t - 1] * (s[i][t] - 'a' + 1);
			int To = mp[res];
			if(To && To != mt[i]) e[mt[i]].push_back(To), deg[To] ++;
		}
	}
	queue<int> q;
	L(i, 1, n) 
		if(deg[i] == 0) 
			q.push(i);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		ans[++tot] = u;
		for(int v : e[u]) {
			deg[v] --;
			if(deg[v] == 0) q.push(v);
		}
	}
	if(tot != n) return puts("NO"), 0;
	puts("YES");
	L(i, 1, n) printf("%d ", ans[i]);
	puts("");
	return 0;
}