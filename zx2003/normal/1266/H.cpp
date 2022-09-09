#include<bits/stdc++.h>
using namespace std;
typedef __uint128_t lll;
typedef unsigned long long ll;
inline void out(lll x){if(!x){puts("");return;}out(x/10);putchar(int(x%10)+'0');}
vector<int>V(ll x){vector<int>ve;for(;x;x/=10)ve.push_back(x%10);reverse(ve.begin(),ve.end());return ve;}
const ll mo=17717361816799281121ull;
inline ll poww(ll x,ll y){ll ans=1;for(;y;y>>=1,x=(lll)x*x%mo)if(y&1)ans=(lll)ans*x%mo;return ans;}
const int N=60;
int n,e1[N],e2[N],i,j,k,Q,v;
char c[N];
ll a[N][N],b[N][N],w2[N],x,y;lll w3[N],oa[N][N],w1[N];
int main(){
	scanf("%d",&n);--n;
	for(i=1;i<=n;++i)scanf("%d%d",e1+i,e2+i),++a[i][e1[i]],++a[i][e2[i]];
	for(i=1;i<=n;++i)b[i][i]=1,a[i][i]-=2;
	for(i=1;i<=n;++i)++oa[i][e1[i]],++oa[i][e2[i]];
	for(i=1;i<=n;++i)oa[i][i]-=2;
	for(i=1;i<=n;++i)a[i][i]+=mo;
	for(i=1;i<=n;++i){
		for(j=i;j<=n && !a[j][i];++j);
		if(j>n){puts("No Solution");return 0;}
		if(j>i)for(k=1;k<=n;++k)swap(a[i][k],a[j][k]),swap(b[i][k],b[j][k]);
		y=poww(a[i][i],mo-2);
		for(j=1;j<=n;++j)if(j!=i)for(x=(lll)(mo-a[j][i])*y%mo,k=1;k<=n;++k)
			a[j][k]=(a[j][k]+(lll)x*a[i][k])%mo,b[j][k]=(b[j][k]+(lll)x*b[i][k])%mo;
	}
	for(i=1;i<=n;++i)for(j=1,y=poww(a[i][i],mo-2);j<=n;++j)b[i][j]=(lll)b[i][j]*y%mo;
	for(scanf("%d",&Q);Q--;){
		scanf("%d%s",&v,c+1);
		memset(w1,0,sizeof w1);memset(w2,0,sizeof w2);memset(w3,0,sizeof w3);
		--w1[1];++w1[v];for(i=1;i<=n;++i)if(c[i]=='R')++w1[i],--w1[e2[i]];
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				w2[j]=(w2[j]+(lll)(mo+w1[i])*b[i][j])%mo;
		bool fl=0;
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)w3[j]+=(lll)w2[i]*oa[i][j];
		for(i=1;i<=n;++i)if(w3[i]!=w1[i])fl=1;
		static bool vi[N];
		auto nxt=[&](int i){return c[i]=='R'?e2[i]:e1[i];};
		for(i=1;i<=n;++i)if(w2[i] || c[i]=='R'){
			memset(vi+1,0,n);
			for(j=i;vi[j]=1,!vi[nxt(j)];j=nxt(j));
			fl|=!vi[v];
		}
		ll ret=0;for(i=1;i<=n;++i)ret+=w2[i]*2+(c[i]=='R');
		if(fl==1)puts("-1");else printf("%llu\n",ret);
	}
}