#include<stdio.h>
#include<cstdlib>
#include<algorithm>
long long a[100002],b[100002],c[100002];
long long p,q,r,ans;
int n,m,k,t;
inline long long Min(long long p,long long q){return p<q?p:q;}
inline long long sqr(long long p){return p*p;}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);ans=5e18;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);std::sort(a+1,a+n+1);
		for(int i=1;i<=m;i++)scanf("%lld",&b[i]);std::sort(b+1,b+m+1);
		for(int i=1;i<=k;i++)scanf("%lld",&c[i]);std::sort(c+1,c+k+1);
		for(int i=1;i<=n;i++){
			int p=std::lower_bound(b+1,b+m+1,a[i])-b,q=std::upper_bound(c+1,c+k+1,a[i])-1-c;
			if(p<=m&&q>0)ans=Min(ans,sqr(a[i]-b[p])+sqr(a[i]-c[q])+sqr(b[p]-c[q]));
		}for(int i=1;i<=n;i++){
			int p=std::lower_bound(c+1,c+k+1,a[i])-c,q=std::upper_bound(b+1,b+m+1,a[i])-1-b;
			if(p<=k&&q>0)ans=Min(ans,sqr(a[i]-c[p])+sqr(a[i]-b[q])+sqr(c[p]-b[q]));
		}for(int i=1;i<=m;i++){
			int p=std::lower_bound(a+1,a+n+1,b[i])-a,q=std::upper_bound(c+1,c+k+1,b[i])-1-c;
			if(p<=n&&q>0)ans=Min(ans,sqr(b[i]-a[p])+sqr(b[i]-c[q])+sqr(a[p]-c[q]));
		}for(int i=1;i<=m;i++){
			int p=std::lower_bound(c+1,c+k+1,b[i])-c,q=std::upper_bound(a+1,a+n+1,b[i])-1-a;
			if(p<=k&&q>0)ans=Min(ans,sqr(b[i]-c[p])+sqr(b[i]-a[q])+sqr(c[p]-a[q]));
		}for(int i=1;i<=k;i++){
			int p=std::lower_bound(b+1,b+m+1,c[i])-b,q=std::upper_bound(a+1,a+n+1,c[i])-1-a;
			if(p<=m&&q>0)ans=Min(ans,sqr(c[i]-b[p])+sqr(c[i]-a[q])+sqr(b[p]-a[q]));
		}for(int i=1;i<=k;i++){
			int p=std::lower_bound(a+1,a+n+1,c[i])-a,q=std::upper_bound(b+1,b+m+1,c[i])-1-b;
			if(p<=n&&q>0)ans=Min(ans,sqr(c[i]-a[p])+sqr(c[i]-b[q])+sqr(a[p]-b[q]));
		}printf("%lld\n",ans);
	}
}