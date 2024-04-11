#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 300100
using namespace std;
typedef long long ll;
int lsh[maxn],a[maxn],b[maxn],h[maxn],n,bh[maxn];
ll dp[maxn],ans,t[maxn];
int comp(const int x,const int y){return b[x]==b[y]?a[x]>a[y]:b[x]>b[y];}
void add(int x,ll a){for(;x<=n*2;x+=x&-x)t[x]=max(t[x],a);}
ll query(int x){ll ans=0;for(;x;x-=x&-x)ans=max(ans,t[x]);return ans;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&a[i],&b[i],&h[i]),bh[i]=i,lsh[i*2-1]=a[i],lsh[i*2]=b[i];
	sort(bh+1,bh+n+1,comp),sort(lsh+1,lsh+n*2+1);
	for(int i=1;i<=n;++i)a[i]=lower_bound(lsh+1,lsh+n*2+1,a[i])-lsh,b[i]=lower_bound(lsh+1,lsh+n*2+1,b[i])-lsh;
	for(int i=1;i<=n;++i){
		dp[bh[i]]=query(b[bh[i]]-1)+h[bh[i]];
		add(a[bh[i]],dp[bh[i]]);
		ans=max(ans,dp[bh[i]]);
//		printf("[%d,%d]",b[i]-1,a[i]);
	}
	printf("%I64d",ans);
}