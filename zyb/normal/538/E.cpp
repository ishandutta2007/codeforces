#include<stdio.h>
#include<algorithm>
#define N 200005
using namespace std;
int last[N],to[2*N],next[2*N],i,j,k,l,s,n,m,tot,x,y,f[N],g[N],q[N],fa[N],deep[N],dis[N];
int S[N];
inline void add(int x,int y) {
	next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
inline void build(int x) {
	int l=0,r=1; deep[q[1]=x]=1;
	while (l<r) {
		k=q[++l];
		for (int i=last[k];i;i=next[i]) {
			if (fa[k]==to[i]) continue;
			fa[q[++r]=to[i]]=k;
			dis[k]++;
			deep[to[i]]=deep[k]+1;
		}
	}
}
int main() {
	scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	build(1);
	int sum=0;
	for (i=n;i;i--)
	if (!dis[q[i]]) f[q[i]]=g[q[i]]=1,sum++,S[q[i]]=1;
	else {
		if (deep[q[i]]&1) f[q[i]]=n+1;
		else g[q[i]]=n+1;
		for (j=last[q[i]];j;j=next[j]) {
			if (to[j]==fa[q[i]]) continue;
			S[q[i]]+=S[to[j]];
			if (deep[q[i]]&1) {
				f[q[i]]=min(f[q[i]],f[to[j]]);
				g[q[i]]+=g[to[j]]-1;
			}
			else {
				f[q[i]]+=f[to[j]]; 
				g[q[i]]=min(g[q[i]],S[to[j]]-g[to[j]]);
			}
		}
		if (deep[q[i]]&1) g[q[i]]++;
		else g[q[i]]=S[q[i]]-g[q[i]];
	}
	printf("%d %d\n",sum-f[1]+1,sum-g[1]+1);
}