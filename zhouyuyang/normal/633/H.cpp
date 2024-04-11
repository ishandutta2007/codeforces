#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int,short>a[30010];
int n,m,q,i,j,last[30010],ans[30010],step[30010],l[30010],r[30010],f[30010];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	static int b[30005];
	for(i=1;i<=n;i++)b[i]=a[i].first%m;
	f[0]=f[1]=1;
	for(i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%m;
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d%d",l+i,r+i);
		last[i]=-1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=q;j++)
			if(a[i].second>=l[j]&&a[i].second<=r[j]&&a[i].first!=last[j]){
				ans[j]+=b[i]*f[step[j]]%m;
				step[j]++;
				last[j]=a[i].first;
			}
	for(i=1;i<=q;i++)printf("%d\n",ans[i]%m);
}