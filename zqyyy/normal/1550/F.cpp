#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7,M=1e6+7;
struct Edge{int to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]={y,head[x],w},head[x]=s_e;
}
struct edge{
	int x,y,w;
	bool operator <(const edge &q) const {return w<q.w;}
};
int n,Q,st,d,a[N],pa[N],dis[N],id[M];
set<int>s;
vector<int>b[N];
inline int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
inline bool unin(int x,int y){
	x=find(x),y=find(y);if(x==y)return 0;
	if(b[x].size()<b[y].size())swap(x,y);pa[y]=x;
	for(int z:b[y])b[x].push_back(z);
	return b[y].clear(),1;
}
void dfs(int x,int fa){
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;if(y==fa)continue;
		dis[y]=max(dis[x],e[i].w),dfs(y,x);
	}
}
int main(){
	n=read(),Q=read(),st=read(),d=read();
	for(int i=1;i<=n;i++)a[i]=read(),id[a[i]]=i;
	for(int i=1;i<=n;i++)s.insert(a[i]),pa[i]=i,b[i]={i};
	for(int cnt=0;cnt<n-1;){
		vector<edge>buf;
		for(int i=1;i<=n;i++){
			if(b[i].empty())continue;
			for(int x:b[i])s.erase(a[x]);
			edge mn={0,0,0x3f3f3f3f};
			for(int x:b[i])
				for(int y:{-d,d}){
					auto it=s.lower_bound(a[x]+y);
					if(it!=s.end())mn=min(mn,edge{x,id[*it],abs(abs((*it)-a[x])-d)});
					if(it!=s.begin())it--,mn=min(mn,edge{x,id[*it],abs(abs((*it)-a[x])-d)});
				}
			for(int x:b[i])s.insert(a[x]);
			buf.push_back(mn);
		}
		for(auto i:buf)if(unin(i.x,i.y))cnt++,add_e(i.x,i.y,i.w),add_e(i.y,i.x,i.w);
	}
	dfs(st,0);
	while(Q--){
		int x=read(),k=read();
		puts(dis[x]<=k?"Yes":"No");
	}
	return 0;
}