#include<stdio.h>
#include<algorithm>
#define rd() sd^=sd>>7,sd^=sd<<13,sd^=sd>>7
long long a[200002],b[200002];int n,m=0,ans;
unsigned long long sd=0xdeafdeafdeafdeafull;
inline long long Min(long long p,long long q){return p<q?p:q;}
int check(long long v){
	long long cnt=0,p;
	for(int i=1;i<=n;i++)p=a[i]%v,cnt+=p==a[i]?v-p:Min(p,v-p);
	return cnt>=n?n:cnt;
}
int main(){
	scanf("%d",&n);ans=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=10;i++)rd();
	for(int i=1;i<=10&&m<=50;i++){
		rd();int p=sd%n+1;
		long long v=a[p];
		for(int i=2;1ll*i*i<=v;i++)if(v%i==0){
			b[++m]=i;
			while(v%i==0)v/=i;
		}if(v!=1)b[++m]=v;v=a[p]+1;
		for(int i=2;1ll*i*i<=v;i++)if(v%i==0){
			b[++m]=i;
			while(v%i==0)v/=i;
		}if(v!=1)b[++m]=v;v=a[p]-1;
		if(v){
			for(int i=2;1ll*i*i<=v;i++)if(v%i==0){
				b[++m]=i;
				while(v%i==0)v/=i;
			}if(v!=1)b[++m]=v;
		}std::sort(b+1,b+m+1);m=std::unique(b+1,b+m+1)-b-1;
	}for(int i=1;i<=m;i++)ans=Min(ans,check(b[i]));
	printf("%d ",ans);
}