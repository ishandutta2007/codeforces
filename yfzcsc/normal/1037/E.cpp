#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef pair<int,int> pii;
set<pii>st;
set<int>G[maxn];
int dg[maxn],n,K,m,in[maxn];
int fr[maxn],to[maxn],anses[maxn];
void del(int x){
	if(!in[x])return ;
	st.erase(pii(dg[x],x));
	for(auto y:G[x])if(in[y]){
		st.erase(pii(dg[y],y));
		--dg[y];
		st.insert(pii(dg[y],y));
	}
	in[x]=0;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&fr[i],&to[i]);
		G[fr[i]].insert(to[i]);
		G[to[i]].insert(fr[i]);
		dg[fr[i]]++,dg[to[i]]++;
	}
	for(int i=1;i<=n;++i)st.insert(pii(dg[i],i)),in[i]=1;
	for(int i=m;i>=1;--i){
		while(st.size()&&st.begin()->first<K){
			del(st.begin()->second);
		}
		anses[i]=st.size();
		if(in[fr[i]]&&in[to[i]]){
			int y=fr[i];
			st.erase(pii(dg[y],y));
			--dg[y];
			st.insert(pii(dg[y],y));
			y=to[i];
			st.erase(pii(dg[y],y));
			--dg[y];
			st.insert(pii(dg[y],y));
		}
		G[fr[i]].erase(to[i]);
		G[to[i]].erase(fr[i]);
	}
	for(int i=1;i<=m;++i)printf("%d\n",anses[i]);
}