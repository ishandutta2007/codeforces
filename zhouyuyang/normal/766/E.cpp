#include <bits/stdc++.h>
#define N 1000020
#define LG 22
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head[N/10], to[N/5], nxt[N/5], cnt;
void insert(int x, int y) {
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
bool a[N][LG];
int f[N][2], bit;
ll sum, ans;
void dfs(int x, int fa) {
	// printf("%d %d :: %d\n", x, fa, bit);
	int qwq = a[x][bit];
	f[x][qwq] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs(to[i], x);
			sum = sum + f[x][0] * f[to[i]][1] + f[to[i]][0] * f[x][1];
			f[x][1] += f[to[i]][1 ^ qwq];
			f[x][0] += f[to[i]][0 ^ qwq];
		}
}
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		ans += x;
		for (int j = 0; j < LG; j++)
			a[i][j] = x >> j & 1;
	}
	for (int i = 1; i < n; i++)
		insert(read(), read());
	for (bit = 0; bit < LG; bit++) {
		memset(f, 0, sizeof f);
		sum = 0;
		dfs(1, 0);
		ans = ans + (sum << bit);
	}
	printf("%lld\n", ans);
	return 0;
}