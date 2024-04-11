#include <cstdio>
const int N=1e6+10;
int n,m,a[N];
long long sum1[N],sum2[N];
inline int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<n;++i)sum1[i]=sum1[i-1]+max(a[i]-a[i+1],0),sum2[i]=sum2[i-1]+max(a[i+1]-a[i],0);
	for(int s,t,i=1;i<=m;++i){
		scanf("%d %d",&s,&t);
		if(s<t)printf("%lld\n",sum1[t-1]-sum1[s-1]);
		else printf("%lld\n",sum2[s-1]-sum2[t-1]);
	}
	return 0;
}