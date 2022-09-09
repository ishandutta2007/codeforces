#include<bits/stdc++.h>
using namespace std;
const int N=25e4+5;
typedef long long ll;
typedef pair<int,int>pii;
typedef unsigned int ui;
inline ui R(){
	static ui seed=19287;
	return seed^=seed<<5,seed^=seed>>13,seed^=seed<<19;
}
struct node{
	int sz,ch[2],fa;ll su,v;
	ui p;
	inline int dir(const int&x){return ch[1]==x;}
	inline node(ll _v=0):sz(1),v(_v),su(_v),p(R()){fa=ch[0]=ch[1]=0;}
}t[N*3];int tcnt,rt[N];
inline void maintain(int i){
	t[i].sz=t[t[i].ch[0]].sz+t[t[i].ch[1]].sz+1;
	t[i].su=t[t[i].ch[0]].su+t[t[i].ch[1]].su+t[i].v;
}
inline void setc(int x,int y,int o){t[t[y].fa=x].ch[o]=y;}
inline void rotate(int x){
	int y=t[x].fa,z=t[y].fa,o;
	setc(z,x,t[z].dir(y));
	o=t[y].dir(x);setc(y,t[x].ch[!o],o);setc(x,y,!o);
	maintain(y);maintain(x);
}
int ins(int x,ll v){
	if(!x){t[++tcnt]=node(v);return tcnt;}
	int o=t[x].v<v,y;++t[x].sz;t[x].su+=v;
	setc(x,y=ins(t[x].ch[o],v),o);
	if(t[y].p>t[x].p)rotate(y),x=y;return x;
}
int merge(int x,int y){
	if(!x || !y)return x|y;t[x].fa=t[y].fa=0;
	if(t[x].p>t[y].p)return setc(x,merge(t[x].ch[1],y),1),maintain(x),x;
		else return setc(y,merge(x,t[y].ch[0]),0),maintain(y),y;
}
int del(int x,ll v){
	if(t[x].v==v)return merge(t[x].ch[0],t[x].ch[1]);
	int o=t[x].v<v;setc(x,del(t[x].ch[o],v),o);--t[x].sz;t[x].su-=v;return x;
}
inline int getrk(int x){
	int ans=0;
	for(;x;){
		int z=t[t[x].ch[0]].sz+1;
		if(t[x].v<=0)ans+=z,x=t[x].ch[1];else x=t[x].ch[0];
	}
	return ans;
}
inline ll ask(int x,int k){
	if(t[x].sz<k)return 1ll<<40;
	ll ans=0;
	for(;x;){
		int z=t[t[x].ch[0]].sz+1;
		if(k>=z)ans+=t[t[x].ch[0]].su+t[x].v,k-=z,x=t[x].ch[1];else x=t[x].ch[0];
	}
	return ans;
}
int n,a,b,c,i,deg[N];
set<int>s;
set<pii>e[N];
vector<int>v[N];
bool bb[N];
ll ans,f[N][2];
void dfs(int u,int fa){
	bb[u]=1;
	for(pii i:e[u])if(fa!=i.first)dfs(i.first,u);
	ll su=0;
	for(pii i:e[u])if(fa!=i.first)rt[u]=ins(rt[u],f[i.first][1]-f[i.first][0]+i.second),
		su+=f[i.first][0];
	int z=getrk(rt[u]);
	f[u][0]=su+ask(rt[u],max(z,deg[u]-i));f[u][1]=su+ask(rt[u],max(z,deg[u]-i-1));
	for(pii i:e[u])if(fa!=i.first)rt[u]=del(rt[u],f[i.first][1]-f[i.first][0]+i.second);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);t[0].sz=0;
	cin>>n;for(i=1;i<n;++i)cin>>a>>b>>c,e[a].insert(pii(b,c)),e[b].insert(pii(a,c));
	for(i=1;i<=n;++i)v[deg[i]=e[i].size()].push_back(i),s.insert(i);
	for(i=0;i<n;++i){
		for(int j:v[i])for(pii k:e[j])if(deg[a=k.first]>i)
			rt[a]=ins(rt[a],k.second),e[a].erase(e[a].lower_bound(pii(j,0)));
		for(int j:v[i])s.erase(j);
		ans=0;
		for(int j:s)if(!bb[j])dfs(j,0),ans+=f[j][0];
		for(int j:s)bb[j]=0;
		cout<<ans<<' ';
	}
	cout<<endl;
	return 0;
}