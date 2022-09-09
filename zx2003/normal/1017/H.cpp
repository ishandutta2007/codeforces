#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
const int mo=998244353,N=1e5+5;
int n,m,q,e[N],l,r,k,ans[N],i,j,a[N],b[N],ssm[N];
vector<V>qu[N];
int bel[N],bl,inv[N*2],pi,xjm[N];
inline void inc(int i){i=e[i];pi=1ll*pi*(a[i]+k-b[i]++)%mo;}
inline void dec(int i){i=e[i];pi=1ll*pi*inv[a[i]+k-(--b[i])]%mo;}
int main(){
	for(i=2,inv[1]=1;i<N*2;++i)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	for(i=1;i<=n;++i)cin>>e[i],++a[e[i]];
	for(i=1;i<=q;++i)cin>>l>>r>>k,qu[k].push_back({l,r,i});
	for(k=0;k<N;++k)if(!qu[k].empty()){
		bl=max(n/sqrt(qu[k].size()),1.0);for(i=1;i<=n;++i)bel[i]=(i-1)/bl+1;
		sort(qu[k].begin(),qu[k].end(),[&](const V&a,const V&b){return bel[a[0]]==bel[b[0]]
			?(bel[a[0]]&1?a[1]>b[1]:a[1]<b[1]):a[0]<b[0];});
		j=1ll*k*m%mo;ssm[0]=1;for(i=1;i<=n;++i)ssm[i]=1ll*ssm[i-1]*(j+i)%mo;
		l=1;r=0;pi=1;memset(b+1,0,m<<2);
		for(V u:qu[k]){
			for(;l>u[0];inc(--l));for(;r<u[1];inc(++r));for(;l<u[0];dec(l++));for(;r>u[1];dec(r--));
			ans[u[2]]=1ll*pi*ssm[n-(u[1]-u[0]+1)]%mo;
		}
	}
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}