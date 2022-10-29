#include<bits/stdc++.h>
using namespace std;
int x[2010],a[2010],n,m,z;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]<=m)x[a[i]]++;
	}
	int lim=n/m;
	for(int i=1;i<=n;++i){
		if(a[i]>m||x[a[i]]>lim)
			for(int j=1;j<=m;++j)if(x[j]<lim){
//				printf("[%d->%d(%d,%d)]\n",a[i],j,x[a[i]],x[j]);
				if(a[i]<=m)x[a[i]]--;
				a[i]=j,x[j]++;z++;
				goto end;
			}
//		if(a[i]>m)for(int j=1;j<=m;++j)if(x[j]==lim){
//			a[i]=j;x[j]++;z++;goto end;
//		}
		end:;
	}
	int ans=1<<30;
	for(int i=1;i<=m;++i)ans=min(ans,x[i]);
	printf("%d %d\n",ans,z);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
}