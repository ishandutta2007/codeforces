#include <cstdio>
#include <vector>
const int inf=1e9,N=4e5+10;
int n,m,tim,x[N],y[N];
bool vis[N];
std::vector<int> rec,vec[N];
inline void swap(int &x,int &y){x^=y^=x^=y;}
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
inline void swp(int u,int v){
	swap(vec[x[u]][y[u]],vec[x[v]][y[v]]);
	swap(x[u],x[v]),swap(y[u],y[v]);
}
inline bool chk(int i,int j){
	int res=inf;
	if(vec[i][j]==1)return true;
	if(i!=1)cmin(res,vec[i-1][j]);
	if(i!=n)cmin(res,vec[i+1][j]);
	if(j!=1)cmin(res,vec[i][j-1]);
	if(j!=m)cmin(res,vec[i][j+1]);
	return res<vec[i][j];
}
void solve(int u){
	vis[u]=true;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int v=vec[i][j];
			if(vis[v])continue;
			bool tag=true;
			swp(u,v),tag&=chk(x[u],y[u]),tag&=chk(x[v],y[v]);
			for(int k:rec)tag&=chk(x[k],y[k]);
			if(x[u]!=1)tag&=chk(x[u]-1,y[u]);
			if(x[u]!=n)tag&=chk(x[u]+1,y[u]);
			if(y[u]!=1)tag&=chk(x[u],y[u]-1);
			if(y[u]!=m)tag&=chk(x[u],y[u]+1);
			if(x[v]!=1)tag&=chk(x[v]-1,y[v]);
			if(x[v]!=n)tag&=chk(x[v]+1,y[v]);
			if(y[v]!=1)tag&=chk(x[v],y[v]-1);
			if(y[v]!=m)tag&=chk(x[v],y[v]+1);
			swp(u,v),tim+=tag;
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		vec[i].resize(m+1);
		for(int j=1;j<=m;++j)scanf("%d",&vec[i][j]),x[vec[i][j]]=i,y[vec[i][j]]=j;
	}
	int t=n*m;
	for(int i=1;i<=t;++i)if(!chk(x[i],y[i]))rec.push_back(i);
	if(!rec.size()){puts("0");return 0;}
	if(rec.size()>15){puts("2");return 0;}
	int u=rec.front();
	solve(u);
	if(x[u]!=1)solve(vec[x[u]-1][y[u]]);
	if(x[u]!=n)solve(vec[x[u]+1][y[u]]);
	if(y[u]!=1)solve(vec[x[u]][y[u]-1]);
	if(y[u]!=m)solve(vec[x[u]][y[u]+1]);
	if(!tim)puts("2");
	else printf("1 %d\n",tim);
	return 0;
}