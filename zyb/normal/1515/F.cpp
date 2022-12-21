#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define pb push_back
long long a[N];
int i,j,k,ans[N],tot,l,s,n,m,X,fa[N];
int A[N],q[N];
struct pa {
	int x,y;
};
vector<pa>G[N];
inline int get(int x) {
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
inline void build(int x) {
	for (int i=1;i<=n;i++) fa[i]=0;
	int l=0,r=1; q[1]=x;
	while (l<r) {
		int k=q[++l];
		for (auto p:G[k]) {
			if (fa[k]==p.x) continue;
			fa[q[++r]=p.x]=k;
			A[p.x]=p.y;
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&X);
	for (int i=1;i<=n;i++) fa[i]=i,scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) {
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		if (get(xx)!=get(yy)) {
			fa[get(xx)]=get(yy);
			G[xx].pb({yy,i});
			G[yy].pb({xx,i});
		}
	}
	long long s=0;
	for (int i=1;i<=n;i++) s+=a[i];
	if (s < 1ll*(n-1)*X) {
		puts("NO");
	}
	else {
		puts("YES");
		build(1);
		int tot1=n-1;
		for (int i=n;i>1;i--) {
			if (a[q[i]]>=X) {
				ans[++tot]=A[q[i]];
				a[fa[q[i]]]+=a[q[i]]-X;
			}
			else ans[tot1--]=A[q[i]];
		}
		for (int i=1;i<n;i++) printf("%d\n",ans[i]);
	}
}