#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
int i,j,k,l,s[N],n,m,tot,last[N],Next[N],to[N],dfn[N],low[N];
int vis[N],q[N],Q[N],q1[N],r,r1,G[N],T;
vector<int>gt;
int ans[N],A[N],B[N],a[N],b[N],x,y;
inline void add(int x,int y) {
	Next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
inline void tarjan(int x) {
	dfn[x]=low[x]=++tot;
	q[++r]=x;
	vis[x]=1;
	for (int i=last[x];i;i=Next[i]) {
		if (!dfn[to[i]]) tarjan(to[i]),low[x]=min(low[x],low[to[i]]);
		else if (vis[to[i]]) low[x]=min(low[x],low[to[i]]);
	}
	if (low[x]==dfn[x]) {
		++T;
		while (q[r]!=x) {
			G[q[r]]=T;
			vis[q[r]]=0;
			r--;
			s[T]++;
		}
		G[q[r]]=T;
		vis[q[r]]=0;
		r--;
		s[T]++;
	}
}
inline void bfs(int x) {
	int l=0,r=1; Q[1]=x;
	while (l<r) {
		int k=Q[++l];
		for (int i=last[k];i;i=Next[i]) {
			if (!vis[to[i]]) vis[Q[++r]=to[i]]=1;
		}
	}
}
inline bool check(int x,int y) {
	int s=0;
	int p=x;
	while (x) {
		s+=x&1;
		x>>=1;
	}
	x=y;
	while (x) {
		s-=x&1;
		x>>=1;
	}
	if (s>0) return true;
	if (s<0) return false;
	if (s==0&&p!=(1<<r1)-1) return true;
	return false;
}
int main() {
	scanf("%d%d",&n,&m);
	if (n==1) return puts("YES"),0;
	for (i=1;i<=m;i++) scanf("%d%d",&x,&y),add(x,y);
	tot=0;
	for (i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	for (i=1;i<=n;i++)
	for (j=last[i];j;j=Next[j]) {
		B[G[to[j]]]++,A[G[i]]++;
		if (G[to[j]]!=G[i]) a[G[i]]=b[G[to[j]]]=1;
	}
	for (i=1;i<=T;i++) if (!A[i]&&!B[i]) return puts("NO"),0;
	for (i=1;i<=n;i++) {
		if (!A[G[i]]) gt.pb(i);
		else if (!B[G[i]]) q1[++r1]=i;	
	}
	for (i=1;i<=T;i++) {
		if (A[i]&&B[i]&&r1&&(!a[i]||!b[i])) return puts("NO"),0;
	}
	if (!r1&&T>1) return puts("NO"),0;
	for (i=1;i<=r1;i++) {
		for (j=1;j<=n;j++) vis[j]=0;
		bfs(q1[i]);
		for (j=0;j<gt.size();j++) if (vis[gt[j]]) ans[i]+=(1<<(j));
	}
	for (i=1;i<(1<<r1);i++) {
		int x=i;
		int s=0,t=1;
		while (x) {
			if (x&1) s|=ans[t];
			t++;
			x>>=1;
		}
		if (check(i,s)) return puts("NO"),0;
	}
	puts("YES");
}