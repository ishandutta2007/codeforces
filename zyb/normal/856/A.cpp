#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define N 1000005
#define lowbit(o) o&(-o)
using namespace std;
int i,j,k,l,s,n,m,fa[N],test,Ans,ans[105];
int a[105],b[10005],q[N],tot,r;
inline int get(int x) {
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
int main() {
	scanf("%d",&test);
	for (i=1;i<=1000001;i++) fa[i]=i;
	while (test--) {
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		for (i=1;i<=n;i++) for (j=i+1;j<=n;j++) b[++tot]=abs(a[i]-a[j]);
		i=1;
		while (i<=1000000&&Ans<n) {
			ans[++Ans]=i;
			for (j=1;j<=tot;j++) if (get(i+b[j])==i+b[j]&&i+b[j]<=1000000) fa[i+b[j]]=get(i+b[j]+1),q[++r]=i+b[j];
			i=get(i+1);
		}
		if (Ans<n) puts("NO");
		else {
			puts("YES");
			for (i=1;i<=n;i++) printf("%d ",ans[i]);
			puts("");
		}
		Ans=0;
		for (i=1;i<=r;i++) fa[q[i]]=q[i];
		tot=r=0;
	}
}