#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,m,a,b,u[N],v[N],g[N],i,sz[N],ff[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>n>>m>>a>>b;
		for(i=1;i<=n;++i)g[i]=i;memset(sz+1,0,n<<2);memset(ff+1,0,n<<2);
		for(i=1;i<=m;++i){
			cin>>u[i]>>v[i];
			if(u[i]!=a && u[i]!=b && v[i]!=a && v[i]!=b)
				g[gfa(u[i])]=gfa(v[i]);
		}
		for(i=1;i<=m;++i){
			if(u[i]==a && v[i]!=b)ff[gfa(v[i])]|=1;
			if(u[i]==b && v[i]!=a)ff[gfa(v[i])]|=2;
			swap(u[i],v[i]);
			if(u[i]==a && v[i]!=b)ff[gfa(v[i])]|=1;
			if(u[i]==b && v[i]!=a)ff[gfa(v[i])]|=2;
		}
		for(i=1;i<=n;++i)++sz[gfa(i)];
		int aa[4]={0,0,0,0};
		for(i=1;i<=n;++i)if(i!=a && i!=b && gfa(i)==i && ff[i]!=3)aa[ff[i]]+=sz[i];
		cout<<1ll*aa[1]*aa[2]<<endl;
	}
	return 0;
}