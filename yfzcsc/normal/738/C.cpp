#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 200010
#define inf (1ll<<50)
using namespace std;
int c[maxn],v[maxn],n,k,s,t;
long long d[maxn],q[maxn],g[maxn];
int main(){
	scanf("%d%d%d%d",&n,&k,&s,&t);
	for(int i=1;i<=n;++i)scanf("%d%d",&c[i],&v[i]);
	for(int i=1;i<=k;++i)scanf("%I64d",&g[i]);
	int top=k+1;g[top]=s;
	sort(g+1,g+top+1);
	for(int i=1;i<=top;++i)
		d[i]=g[i]-g[i-1],d[i]*=2;
	sort(d+1,d+top+1);
	for(int i=1;i<=top;++i)
		q[i]=q[i-1]+d[i]/2;
	long long ans=inf,p,l1;
	for(int i=1;i<=n;++i){
		if(d[top]>v[i]*2)continue;
		if(d[top]<=v[i]){
			l1=q[top];
		} else {
			p=upper_bound(d+1,d+top+1,v[i])-d;
			l1=3ll*(q[top]-q[p-1])-1ll*v[i]*(top-p+1)+q[p-1];	
//			printf("[%I64d,%I64d]",l1,top-p+1);
		}
		if(l1<=t)ans=min(ans,(long long)c[i]);
	}
	if(ans==inf)printf("-1");
	else printf("%I64d",ans);
}