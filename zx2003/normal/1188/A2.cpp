#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int N=1005;
int n,u,v,w,i;
vector<P>e[N];
inline void delE(int x,int y){
	e[x].erase(lower_bound(e[x].begin(),e[x].end(),P{y,-(1<<30)}));
	e[y].erase(lower_bound(e[y].begin(),e[y].end(),P{x,-(1<<30)}));
}
inline void addE(int u,int v,int w){
	e[u].insert(lower_bound(e[u].begin(),e[u].end(),P{v,-(1<<30)}),{v,w});
	e[v].insert(lower_bound(e[v].begin(),e[v].end(),P{u,-(1<<30)}),{u,w});
}
inline int getW(int x,int y){return lower_bound(e[x].begin(),e[x].end(),P{y,-(1<<30)})->second;}
inline void compress(int i){
	assert(e[i].size()==2);
	int a,b,c,d;tie(a,b)=e[i][0];tie(c,d)=e[i][1];if(b!=d){puts("NO");exit(0);}
	delE(a,i);delE(c,i);addE(a,c,b);
}
vector<vector<int>>opt;
void decE(int x,int y,int w){
	lower_bound(e[x].begin(),e[x].end(),P{y,-(1<<30)})->second-=w;
	lower_bound(e[y].begin(),e[y].end(),P{x,-(1<<30)})->second-=w;
}
bool dfss(int x,int y,int fa,int w){
	if(x==y)return 1;
	for(auto&u:e[x])if(u.first!=fa && dfss(u.first,y,x,w))return decE(x,u.first,w),1;return 0;
}
void addP(int x,int y,int w){opt.push_back({x,y,w});dfss(x,y,0,w);}
int dfss(int x,int fa){if(e[x].size()==1)return x;for(auto u:e[x])if(u.first!=fa)return dfss(u.first,x);}
void dfs(int x,int fa){
	vector<int>ch;vector<P>chh;
	for(auto u:e[x])if(u.first!=fa)ch.push_back(u.first);
	for(int y:ch)dfs(y,x);
	int e,f,g,a,c,d,p,q;
	for(auto u:(::e[x]))if(u.first!=fa)chh.push_back(u);else tie(g,c)=u;
	if(chh.empty())return;
	if(!fa)return addP(x,chh[0].first,chh[0].second);
	for(i=chh.size()-1;i>1;--i)addP(chh[i].first,chh[1].first,chh[i].second),delE(x,chh[i].first);
	tie(e,a)=chh[0];tie(f,d)=chh[1];g=dfss(g,x);
	d=getW(f,x);
	p=a-c+d>>1;q=a+c-d>>1;
	addP(e,f,p);
	addP(e,g,q);
	delE(e,x);
	if(p&1)addP(f,g,1);
	compress(x);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d%d",&u,&v,&w),addE(u,v,w);
	for(i=1;i<=n;++i)sort(e[i].begin(),e[i].end());
	for(i=1;i<=n;++i)if(e[i].size()==2)compress(i);
	for(i=1;i<=n;++i)if(e[i].size()==1)break;dfs(i,0);
	printf("YES\n%d\n",int(opt.size()));
	for(auto u:opt)printf("%d %d %d\n",u[0],u[1],u[2]);
	return 0;
}