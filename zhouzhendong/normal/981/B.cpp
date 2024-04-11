#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int n,m,a[N],b[N],x[N],y[N];
LL v[N];
map <int,int> HA;
int main(){
	HA.clear();
	int tot=0;
	memset(v,0,sizeof v);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&x[i]);
		if (HA[a[i]]==0)
			HA[a[i]]=++tot;
		a[i]=HA[a[i]];
		v[a[i]]=max(v[a[i]],1LL*x[i]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a[i],&x[i]);
		if (HA[a[i]]==0)
			HA[a[i]]=++tot;
		a[i]=HA[a[i]];
		v[a[i]]=max(v[a[i]],1LL*x[i]);
	}
	LL ans=0;
	for (int i=1;i<=tot;i++)
		ans+=v[i];
	printf("%I64d",ans);
	return 0;
}