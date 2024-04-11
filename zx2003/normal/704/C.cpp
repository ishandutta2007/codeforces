#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,m,k,i,j;
vector<int>x[N],aa[N];
vector<pair<int,int>>e[N];
int xb,tp[N],aaa[N];
struct P2{
	int x,y;
	inline P2 operator*(const P2&rhs)const{return (P2){int((1ll*x*rhs.x+1ll*y*rhs.y)%mo),int((1ll*x*rhs.y+1ll*y*rhs.x)%mo)};}
	inline P2 operator+(const P2&rhs)const{return (P2){(x+rhs.x)%mo,(y+rhs.y)%mo};}
	inline P2 operator*(const int&k)const{return (P2){int(1ll*k*x%mo),int(1ll*k*y%mo)};}
	inline P2 operator~()const{return (P2){y,x};}
}ans,f[N][2];
bool vi[N];
void dfs(int u,int fa){
	vi[u]=1;
	for(auto v:e[u])if(v.first!=fa){
		tp[++xb]=v.second;aaa[xb]=v.first;
		if(!vi[v.first])dfs(v.first,u);
	}
}
inline void runDP(){
	for(int i=1;i<=xb;++i)if(!tp[i]){
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=~f[i-1][1]+f[i-1][0];
	}else{
		f[i][0]=f[i-1][1]+~f[i-1][0];
		f[i][1]=~(f[i-1][0]+f[i-1][1]);
	}
}
inline void O(){
	int ans=1;for(i=1;i<m;++i)ans=2ll*ans%mo;
	printf("%d\n",ans);exit(0);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&k);x[i].resize(k);
		for(int&v:x[i])scanf("%d",&v),aa[abs(v)].push_back(i*(v>0?1:-1));
	}
	for(i=1;i<=m;++i)if(aa[i].size()==2 && abs(aa[i][0])!=abs(aa[i][1])){
		for(j=0;j<2;++j)e[abs(aa[i][j])].push_back(make_pair(abs(aa[i][j^1]),1ll*aa[i][0]*aa[i][1]<0?1:0));
	}
	ans=(P2){1,0};
	for(i=1;i<=n;++i)if(e[i].empty()){
		if(x[i].size()==1 || x[i][0]==x[i][1])ans=ans*(P2){1,1};
			else if(x[i][0]==-x[i][1])ans=ans*(P2){0,2};else ans=ans*(P2){1,3};
	}
	for(i=1;i<=n;++i)if(!vi[i] && e[i].size()==1){
		xb=0;
		dfs(i,0);
		f[0][0]=(P2){1,0};f[0][1]=x[i].size()>1?(P2){0,1}:(P2){0,0};
		runDP();
		if(x[aaa[xb]].size()>1)f[xb][1]=f[xb][1]*2+~f[xb][0];
		ans=ans*(f[xb][0]+f[xb][1]);
	}
	for(i=1;i<=n;++i)if(!vi[i] && e[i].size()==2){
		xb=0;
		dfs(i,0);if(xb>2)--xb;
		f[0][0]=(P2){1,0};f[0][1]=(P2){0,0};
		runDP();
		P2 t=f[xb][0];
		f[0][0]=(P2){0,0};f[0][1]=(P2){0,1};
		runDP();
		ans=ans*(t+~f[xb][1]);
	}
	for(i=1;i<=m;++i)if(aa[i].empty())ans=ans*2;
	printf("%d\n",ans.y);
	return 0;
}