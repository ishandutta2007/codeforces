#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=14e4,mo=998244353;
inline void red(int&x){x+=x>>31&mo;}
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int n,m,i,u,v,iv,outd[N],mex[N],f[N],mx,L;
vector<int>re[N],e[N];
inline void FWT(){
	int i,j,k,m,x,y;
	for(i=2;i<=L;i<<=1)for(j=k=0,m=i>>1;j<L;j+=i)for(k=0;k<m;++k)
		x=f[j+k],y=f[j+k+m],red(f[j+k]=x+y-mo),red(f[j+k+m]=x-y);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;++i)cin>>u>>v,++outd[u],re[v].push_back(u),e[u].push_back(v);
	queue<int>q;
	for(i=1;i<=n;++i)if(!outd[i])q.push(i);
	for(;!q.empty();){
		u=q.front();q.pop();
		for(int v:re[u])if(!--outd[v])q.push(v);
		static int buc[N];
		for(int v:e[u])++buc[mex[v]];
		for(i=0;buc[i];++i);mex[u]=i;
		for(int v:e[u])--buc[mex[v]];
		mx=max(mx,mex[u]);++f[mex[u]];
	}
	for(L=1;L<=mx;L<<=1);FWT();
	iv=poww(n+1,mo-2);for(i=0;i<L;++i)f[i]=poww((1+1ll*(mo-iv)*f[i])%mo,mo-2);
	FWT();v=1ll*iv*f[0]%mo*poww(L,mo-2)%mo;v=(1+mo-v)%mo;printf("%d\n",v);
}