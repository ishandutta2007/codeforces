#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef pair<int,int>pii;
char c[N];
int st1[N],w1,st2[N],w2,i,j,n,pre[N],nxt[N],ans[N],xb;
vector<pii>ve[2][2];
inline void link(int x,int y){nxt[x]=y;pre[y]=x;}
inline void link2(pii&a,pii b){link(a.second,b.first);a.second=b.second;}
inline void link3(pii a,pii&b){link(a.second,b.first);b.first=a.first;}
inline void work(vector<pii>&v){for(i=1;i<v.size();++i)link2(v[0],v[i]);v.resize(1);}
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(i=1;i<=n;++i)if(c[i]=='R'){
		if(w1)link(st1[w1--],i);st2[++w2]=i;
	}else{
		if(w2)link(st2[w2--],i);st1[++w1]=i;
	}
	printf("%d\n",w1+w2-1);
	for(i=1;i<=w2;++i){
		for(j=st2[i];pre[j];j=pre[j]);
		ve[c[j]=='R'][1].push_back(pii(j,st2[i]));
	}
	for(i=1;i<=w1;++i){
		for(j=st1[i];pre[j];j=pre[j]);
		ve[c[j]=='R'][0].push_back(pii(j,st1[i]));
	}
	if(!ve[0][1].empty() && !ve[1][0].empty() && ve[0][0].empty() && ve[1][1].empty()){
		int a=0;
		if(ve[a][!a].back().first>ve[!a][a].back().first)a=1;
		int p=ve[a][!a].back().first,q=ve[a][!a].back().second,r=ve[!a][a].back().first,s=ve[!a][a].back().second;
		int np=nxt[p];
		link(p,r);
		ve[a][a].push_back(pii(p,s));if(p!=q)ve[!a][!a].push_back(pii(np,q));
		ve[!a][a].pop_back();ve[a][!a].pop_back();
	}
	for(i=1;i<min(ve[0][0].size(),ve[1][1].size());++i)link2(ve[0][0][i],ve[1][1][i]),ve[0][1].push_back(ve[0][0][i]);
	if(!ve[0][0].empty())ve[0][0].resize(1);if(!ve[1][1].empty())ve[1][1].resize(1);
	work(ve[0][1]);work(ve[1][0]);
	if(!ve[0][0].empty()){
		if(!ve[1][0].empty())for(auto u:ve[1][0])link2(ve[0][0][0],u);
		if(!ve[0][1].empty())for(auto u:ve[0][1])link3(u,ve[0][0][0]);
		ve[0][1].clear();ve[1][0].clear();
	}
	if(!ve[1][1].empty()){
		if(!ve[1][0].empty())for(auto u:ve[1][0])link3(u,ve[1][1][0]);
		if(!ve[0][1].empty())for(auto u:ve[0][1])link2(ve[1][1][0],u);
		ve[0][1].clear();ve[1][0].clear();
	}
	if(!ve[0][0].empty() && !ve[1][1].empty())link(ve[0][0][0].second,ve[1][1][0].first);
	for(i=1;i<=n;++i)if(!pre[i])break;
	for(;i;i=nxt[i])printf("%d ",i);puts("");
	return 0;
}