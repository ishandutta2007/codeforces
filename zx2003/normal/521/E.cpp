#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef vector<int>V;
int n,m,x,y,i,be[N],en[N],xb,cov[N],dad[N],xx,yy,p1,q1,p2,q2;
V e[N],e1,e2;
void dfs(int u,int fa){
	be[u]=++xb;dad[u]=fa;
	for(int v:e[u])if(v!=fa){if(!be[v])dfs(v,u),cov[u]+=cov[v];else if(be[v]<be[u])
		++cov[u],--cov[v],e1.push_back(v),e2.push_back(u);}
	if(cov[u]>1)xx=u,yy=fa;
	en[u]=xb;
}
inline bool isanc(int x,int y){return be[x]<=be[y] && be[y]<=en[x];}
inline void out(V v){cout<<v.size()<<' ';for(int x:v)cout<<x<<' ';cout<<'\n';}
inline V getP(int x,int y){V v;for(;v.push_back(x),x!=y;x=dad[x]);return v;}
inline V R(V v){reverse(v.begin(),v.end());return v;}
inline V operator+(V a,V b){a.insert(a.end(),b.begin(),b.end());return a;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(i=1;i<=m;++i)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	for(i=1;i<=n;++i)if(!be[i])dfs(i,0);
	if(!xx){cout<<"NO\n";return 0;}
	cout<<"YES\n";
	for(i=0;i<e1.size();++i)if(isanc(e1[i],yy) && isanc(xx,e2[i])){if(!p1)p1=e1[i],q1=e2[i];else p2=e1[i],q2=e2[i];}
	if(isanc(p2,p1))swap(p1,p2),swap(q1,q2);
	y=0;for(i=1;i<=n;++i)if(isanc(i,q1) && isanc(i,q2) && be[i]>be[y])y=i;
	out(R(getP(y,p2)));out(getP(p2,p1)+getP(q1,y));out(V{p2}+getP(q2,y));
	return 0;
}