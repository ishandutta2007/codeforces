#include<bits/stdc++.h>
#define N 300005
using namespace std;
int i,j,m,n,p,k,ans,l,r,a[N],b[N],c[N],d[N],f[N];
int main() {
	scanf("%d%d%d",&n,&l,&r); ++l;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	for (i=1;i<=n;i++)	if (!b[i]) c[++c[0]]=a[i]; else d[++d[0]]=a[i];
	sort(d+1,d+d[0]+1);
	memset(f,60,sizeof(f)); 
	f[0]=0;
	for (i=1;i<=c[0];i++) for (j=r;j>=c[i];j--) f[j]=min(f[j],f[j-c[i]]);
	int ti=1,s=0;
	for (i=d[0];i>=1;i--) {
		//first type 
		for (j=l-1;j<r;j++) if (f[j]<100000) break;
		while (ti<=d[0]&&d[ti]+s<=(r-j)) s+=d[ti],++ti;
		while (ti>i+1) --ti,s-=d[ti];
		ans=max(ans,ti-1);
		//add a box
		for (j=l-1;j+s<=r;j++) if (f[j]<d[0]-i) ans=max(ans,ti); 
		for (j=r;j>=d[i];j--) f[j]=min(f[j],f[j-d[i]]+1); 
	}
	for (j=l-1;j<=r;j++) if (f[j]<d[0]) ans=max(ans,1); 		
	printf("%d\n",ans);
}