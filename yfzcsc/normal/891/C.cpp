#include<bits/stdc++.h>
#define maxn 501000
using namespace std;
typedef pair<int,int> par;
vector<par>vec[maxn],Q[maxn];
int q,anses[maxn],n,m,f[maxn],sz[maxn],szk,st[maxn],w[maxn],tp,fr[maxn],to[maxn];
int find1(int x){return x==f[x]?x:f[x]=find1(f[x]);}
int find2(int x){return x==f[x]?x:find2(f[x]);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)f[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&fr[i],&to[i],&w[i]),vec[w[i]].push_back(par(fr[i],to[i]));
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		anses[i]=1,scanf("%d",&szk);
		for(int j=1,x;j<=szk;++j)scanf("%d",&x),Q[w[x]].push_back(par(i,x));
	}
	for(int i=1;i<=500000;++i){
		sort(Q[i].begin(),Q[i].end());
		for(int j=0;j<Q[i].size();++j){
			if(j&&Q[i][j].first!=Q[i][j-1].first){
				while(tp){
					int x=st[tp--];
					sz[f[x]]-=sz[x],f[x]=x;
				}
			}
			int _x=find2(fr[Q[i][j].second]),_y=find2(to[Q[i][j].second]);
			if(_x==_y){
				anses[Q[i][j].first]=0;
			} else {
				if(sz[_x]>sz[_y])swap(_x,_y);
				f[_x]=_y,sz[_y]+=sz[_x],st[++tp]=_x;
			}
		}
		for(int j=0;j<vec[i].size();++j)
			f[find1(vec[i][j].first)]=find1(vec[i][j].second);
		tp=0;
	}
	for(int i=1;i<=q;++i)printf("%s\n",anses[i]?"YES":"NO");
}