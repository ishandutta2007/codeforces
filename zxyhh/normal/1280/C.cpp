/*
	Author: zxy_hhhh
	date: 2019/12/15
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#define ll long long
inline ll rd() {
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 200005
int T;
int n;
std::vector<std::pair<int,int>>G[maxn];
ll resG,resB;
int sz[maxn];
std::pair<int,int> dfs(int u,int fa) {
	std::pair<int,int> res=std::make_pair(1,1);
	sz[u]=1;
	for(auto i:G[u]) if (i.first!=fa) {
		std::pair<int,int> now=dfs(i.first,u);
		resG+=1ll*now.first*i.second,resB+=1ll*now.second*i.second;
		res.first+=now.first,res.second+=now.second;
		sz[u]+=sz[i.first];
	}
	res.second=res.second&1;
	while(res.first>n-sz[u]) {
		res.first-=2;
	} 
	return res;
}
int main() {
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	T=rd();
	while(T--) {
		n=rd()*2;resG=0,resB=0;
		for(int i=2;i<=n;i++) {
			int x=rd(),y=rd(),z=rd();
			G[x].push_back(std::make_pair(y,z));
			G[y].push_back(std::make_pair(x,z));
		}
		dfs(1,1);
		for(int i=1;i<=n;i++) G[i].clear();
		wrt(resB,' '),wrt(resG,'\n');
	}
}