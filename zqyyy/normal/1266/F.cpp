#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e6+7;
int n, ans1[N], ans2[N], ans3[N], dp[N], pos[N];
vector<int>G[N], son[N], f[N];
void dfs1(int x, int fa) {
	pos[x]=-1;
	for (int i=0, y; i<(int)G[x].size(); i++) {
		if ((y=G[x][i])==fa) {pos[x]=i; continue;}
		son[x].push_back(y), dfs1(y, x), f[x][i]=dp[y]+1, ckmax(dp[x], f[x][i]);
	}
}
void dfs2(int x, int fa) {
	if (son[x].empty()) return;
	static int pre[N]={-1}, suf[N]; int sz=G[x].size();
	for (int i=0; i<sz; i++) pre[i+1]=max(pre[i], dp[G[x][i]]);
	suf[sz+1]=-1;
	for (int i=sz-1; ~i; i--) suf[i+1]=max(suf[i+2], dp[G[x][i]]);
	for (int i=0, y; i<sz; i++) {
		y=G[x][i];
		if (y^fa) f[y][pos[y]]=max(pre[i], suf[i+2])+2;
	}
	for (int y:son[x]) dp[x]=f[y][pos[y]]-1, dfs2(y, x);
}
int tof[N], tox[N];
int main() {
#ifdef LOCAL
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
	n=read();
	for (int i=1; i<n; i++) {
		int x=read(), y=read();
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i=1; i<=n; i++) f[i].resize(G[i].size());
	dfs1(1, 0), dfs2(1, 0);
	for (int x=1;  x<=n; x++) {
		int sz=G[x].size();
		for (int i=0, y; i<sz; i++)
			if (i==pos[x]) tof[x]=f[x][i];
			else tox[G[x][i]]=f[x][i];
		sort(f[x].begin(), f[x].end(), greater<int>());
		for (int i=0; i<sz; i++) {
			ckmax(ans1[f[x][i]], i+1);
			if (i+1<sz && f[x][i]>=f[x][i+1]+1) ckmax(ans3[f[x][i+1]], i+2);
		}
	}
	for (int x=1; x<=n; x++) {
		static int tmp[N]; int sz=f[x].size();
		for (int i=0; i<sz; i++) tmp[i]=0;
		for (int y:son[x]) {
			bool fl1=false, fl2=false;
			for (int i=0; i<(int)f[y].size(); i++) {
				int F=f[y][i];
				fl1|=F==tof[y], fl2|=F<=tox[y];
				int pos=upper_bound(f[x].begin(), f[x].end(), F, greater<int>())-f[x].begin()-1;
				ckmax(ans2[F], i+1+pos+1-fl1-fl2);
				pos=lower_bound(f[x].begin(), f[x].end(), F, greater<int>())-f[x].begin();
				if (pos<sz) ckmax(tmp[pos], i+1-fl1-fl2);
			}
		}
		for (int i=1; i<sz; i++) ckmax(tmp[i], tmp[i-1]);
		for (int i=0; i<sz; i++) ckmax(ans2[f[x][i]], i+1+tmp[i]);
	}
	ans1[n+1]=1;
	for (int i=n; i; i--) ckmax(ans1[i], ans1[i+1]), ckmax(ans2[i], ans2[i+1]), ckmax(ans3[i], ans3[i+1]);
	int ans=ans1[1];
	for (int i=1; i<=n; i++) ckmax(ans, (int)G[i].size()+1);
	printf("%d ",ans);
	for (int i=2; i<=n; i++) {
		int ans=ans1[(i+1)>>1];
		if (~i&1) ckmax(ans, ans2[i>>1]);
		else ckmax(ans, ans3[i>>1]);
		printf("%d ", ans);
	}
	return 0;
}