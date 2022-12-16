#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define N 3005
#define pb push_back
#define lowbit(o) o&(-o)
using namespace std;
int i,j,k,l,s,n,m,tot,last[N],next[400005],to[400005],x,y,z,Q,h[N],q[N],v[N],V[N],T[N],G[N],vis[N];
vector<int>GT[N];
struct node {
	int id,x,y,z,ans;
}a[400005];
inline bool cmp(const node &x,const node &y) {
	return x.x<y.x;
}
inline void add(int x,int y) {
	next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
inline void bfs(int x) {
	if (vis[x]) return ;
	int l=0,r=1; h[1]=x;
	vis[x]=1;
	while (l<r) {
		++l;
		if (!V[h[l]]) V[h[l]]=-1;
		for (int i=0;i<GT[h[l]].size();i++) if (!vis[GT[h[l]][i]]) h[++r]=GT[h[l]][i],vis[GT[h[l]][i]]=1;;
	}
}
inline void work(int x) {
	for (int i=1;i<=n;i++) v[i]=V[i]=T[i]=G[i]=vis[i]=0;
	int r=1; q[1]=x; v[x]=T[x]=1;
	while (1) {
		while (G[x]==GT[x].size()&&r) v[x]=-1,x=q[--r];
		if (!r) break;
		x=GT[x][G[x]++];
		if (!v[x]) {
			v[x]=1,q[++r]=x,T[x]=r;
			if (!V[x]) {
				V[x]=1;
				for (int j=last[x];j;j=next[j]) {
					if (a[to[j]].z<=r) a[to[j]].ans=q[a[to[j]].z];
					else a[to[j]].ans=-1;
				}
			}
		}
		else if (v[x]==1) {
			for (int k=T[x];k<=r;k++) bfs(q[k]),v[q[k]]=-1;
			r=T[x]-1; x=q[r];
		}
		else if (v[x]==-1) x=q[r];
	}
}
inline bool cmp1(const node &x,const node &y) {
	return x.id<y.id;
}
int main() {
	scanf("%d%d%d",&n,&m,&Q);
	//for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++) scanf("%d%d",&x,&y),GT[x].pb(y);
	for (i=1;i<=n;i++) sort(GT[i].begin(),GT[i].end());
	for (i=1;i<=Q;i++) scanf("%d%d%d",&a[a[i].id=i].x,&a[i].y,&a[i].z);
	sort(a+1,a+1+Q,cmp);
	for (i=1;i<=Q;i=j) {
		j=i;
		while (a[j].x==a[i].x&&j<=Q) add(a[j].y,j),j++;
		work(a[i].x);
		tot=0;
		for (k=i;k<j;k++) last[a[k].y]=0;
	}
	sort(a+1,a+1+Q,cmp1);
	for (i=1;i<=Q;i++) {
		if (!a[i].ans) a[i].ans=-1;
		printf("%d\n",a[i].ans);
	}
}