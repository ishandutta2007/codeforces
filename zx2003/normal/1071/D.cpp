#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int U=1e6,S=2999;
typedef vector<int>V;
int T,i,j,x,y,mn[U+5],p[U/10],pcnt;
bool b[U+5];
map<V,int>mp;
int st[9],scnt,dis[S][S],fc[S];
vector<int>e[S],tmp[S];int mxx;
void dfs(int d,ll x,int lst){
	vector<int>ve(st+1,st+d);reverse(ve.begin(),ve.end());
	mp[ve]=++scnt;fc[scnt]=1;for(int x:ve)fc[scnt]*=x+1;
tmp[scnt]=ve;mxx=max(mxx,fc[scnt]);
	for(int i=1;x*p[d]<=U*10000ll && i<=lst;++i)st[d]=i,x*=p[d],dfs(d+1,x,i);
}
void bfs(int x){
	queue<int>q;static int d[S];int i,u;
	q.push(x);memset(d+1,0,scnt<<2);d[x]=1;
	for(;!q.empty();){
		u=q.front();q.pop();
		for(int v:e[u])if(!d[v])q.push(v),d[v]=d[u]+1;
	}
	for(int&v:dis[x])v=99;
	for(i=1;i<=scnt;++i)dis[x][fc[i]]=min(dis[x][fc[i]],d[i]-1);
}
int main(){
	for(i=2;i<=U;++i){
		if(!b[i])p[++pcnt]=i,mn[i]=i;
		for(j=1;j<=pcnt;++j){
			x=i*p[j];if(x>U)break;
			b[x]=1;mn[x]=p[j];if(i%p[j]==0)break;
		}
	}
	dfs(1,1,20);
	for(auto u:mp){
		for(i=0;i<u.first.size();++i){
			auto v=u.first;
			if(!--v[i])v.erase(v.begin()+i);sort(v.begin(),v.end());if(mp.count(v))e[u.second].push_back(mp[v]);
			v=u.first;++v[i];sort(v.begin(),v.end());if(mp.count(v))e[u.second].push_back(mp[v]);
		}
		auto v=u.first;v.insert(v.begin(),1);if(mp.count(v))e[u.second].push_back(mp[v]);
	}
	for(i=1;i<=scnt;++i)bfs(i);
	for(scanf("%d",&T);T--;){
		auto getid=[&](int x){
			vector<int>ve;
			for(;x>1;){
				int y=mn[x],ct=0;
				for(;x%y==0;x/=y,++ct);
				ve.push_back(ct);
			}
			sort(ve.begin(),ve.end());return mp[ve];
		};
		scanf("%d%d",&x,&y);x=getid(x);y=getid(y);
		int ass=99;for(i=0;i<S;++i)ass=min(ass,dis[x][i]+dis[y][i]);printf("%d\n",ass);
	}
	return 0;
}