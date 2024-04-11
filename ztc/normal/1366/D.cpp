#include<stdio.h>
int a[10000002],p[10000002],tp=0,v[10000002],ans[1000002][2];
int main(){
	for(int i=2;i<=1e7;i++){
		if(!a[i])p[++tp]=i,v[i]=i;
		for(int j=1;j<=tp&&i*p[j]<=1e7;j++){
			a[i*p[j]]=1;v[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}int n,m;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		long long p=v[m];while((long long)m%p==0)p*=v[m];p/=v[m];
		if(p==m)ans[i][0]=ans[i][1]=-1;
		else ans[i][0]=p,ans[i][1]=m/p;
	}for(int i=1;i<=n;i++)printf("%d ",ans[i][0]);puts("");
	for(int i=1;i<=n;i++)printf("%d ",ans[i][1]);
}