#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define P 1000000007
int tot,n,m,k,ans[N],fa[N],a[N];
inline int get(int x) {
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
inline void work(int k,int i,int a[]) {
	if (k==1) {
		int x=get(a[1]);
		if (!x) return;
		ans[++tot]=i;
		fa[x]=0;
		return;
	}
	else {
		int x=get(a[1]);
		if (!x) {
			int y=get(a[2]);
			if (!y) return;
			ans[++tot]=i;
			fa[y]=0;
			return;
		}
		else {
			int y=get(a[2]);
			if (!y&&!x) return;
			if (x==y) {
				return ;
			}
			if (!x) {
				ans[++tot]=i;
				fa[y]=0;
				return;
			}
			if (!y) {
				ans[++tot]=i;
				fa[x]=0;
				return;
			}
			if (x<y) {
				ans[++tot]=i;
				fa[x]=y;
				return;
			}
			else {
				ans[++tot]=i;
				fa[y]=x;
				return;
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) fa[i]=i;
	for (int i=1;i<=n;i++) {
		scanf("%d",&k);
		for (int j=1;j<=k;j++) scanf("%d",&a[j]);
		sort(a+1,a+1+k);
		work(k,i,a);
	}
	int Ans=1;
	for (int i=1;i<=tot;i++) Ans=1ll*2*Ans%P;
	printf("%d %d\n",Ans,tot);
	for (int i=1;i<=tot;i++) printf("%d ",ans[i]);
}