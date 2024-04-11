#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,x[N],y[N],i,j,tot,g[N],ccnt,F,trcnt;
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
bool b[505][505],cir,bb[505][505];
inline void tryuni(int x,int y){x=gfa(x);y=gfa(y);if(x!=y)g[x]=y,--ccnt;else cir=1;}
inline int idx(int x,int y){return (x<<9)|y;}
void dfs(int x,int y);
inline int getv(int x,int y){return 0<=x && 0<=y && b[x][y];}
inline int getd(int x,int y){return getv(x+1,y)+getv(x-1,y)+(x&1?getv(x-1,y+1):getv(x+1,y-1));}
inline void ck(int x,int y){if(0<=x && 0<=y && !b[x][y] && getd(x,y)>1)dfs(x,y);}
void dfs(int x,int y){++tot;b[x][y]=1;ck(x+1,y);ck(x-1,y);x&1?ck(x-1,y+1):ck(x+1,y-1);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>x[i]>>y[i],b[x[i]][y[i]]=1;memcpy(bb,b,sizeof b);
	for(i=0;i<=500;++i){
++i,--i;
		for(j=0;j<=500;++j){
			F+=getv(i,j)^getv(i-1,j);
			if(!(i&1))F+=getv(i,j)^getv(i^1,j-1);
		}
	}
	for(i=1;i<=n;++i)dfs(x[i],y[i]);
	for(i=0;i<N;++i)g[i]=i;ccnt=tot;
	for(i=0;i<=500;++i)for(j=0;j<=500;++j)if(b[i][j]){
		if(getv(i-1,j))tryuni(idx(i,j),idx(i-1,j));
		if(!(i&1) && getv(i^1,j-1))tryuni(idx(i,j),idx(i^1,j-1));
	}
	for(i=0;i<=500;++i)for(j=0;j<=500;++j)if(b[i][j] && getd(i,j)==1 && b[i+1][j] && !bb[i+1][j]){
		if(i&1){
			if(getv(i+2,j) && getv(i+2,j-1) && getd(i+2,j)==1 && getd(i+2,j-1)==1)++trcnt;
		}else{
			if(getv(i,j+1) && getv(i+2,j) && getd(i,j+1)==1 && getd(i+2,j)==1)++trcnt;
		}
	}
	if(cir)cout<<"SICK\n";else cout<<"RECOVERED\n"<<(F-ccnt*2-trcnt*2)<<'\n';
}