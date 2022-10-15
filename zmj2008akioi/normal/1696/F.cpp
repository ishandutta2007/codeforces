#include <cstdio>
#include <cstring>
#include <vector>
const int rt=1,N=110;
int T,n,dnt,g[N],f[N*N],head[N],to[N<<1],next[N<<1],dis[N][N];
bool vis[N*N];
char s[N];
std::vector<int> son[N];
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline int id(int u,int v){
	if(u>v)swap(u,v);
	return (u-1)*n+v;
}
inline void grs(){for(int i=1;i<=n;++i)g[i]=i;}
inline void addedge(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
int gfind(int x){
	if(g[x]!=x)g[x]=gfind(g[x]);
	return g[x];
}
struct pr{
	int u,v;
	pr(){};
	pr(int u,int v):u(u),v(v){};
};std::vector<pr> vec[N*N];
struct option{
	int k,i,j;
	option(){};
	option(int k,int i,int j):k(k),i(i),j(j){};
};std::vector<option> opt,same;
inline void reset(int n){for(int i=1;i<=n;++i)for(int j=i;j<=n;++j)f[id(i,j)]=id(i,j),vec[id(i,j)].clear();}
void dfs(int u,int p=0){
	son[u].push_back(u);
	for(int i=head[u];i;i=next[i]){
		if(to[i]==p)continue;
		dfs(to[i],u);
		for(int k:son[to[i]])for(int j:son[u])dis[k][j]=dis[j][k]=dis[u][j]+dis[to[i]][k]+1;
		for(int k:son[to[i]])son[u].push_back(k);
	}
}
bool chk(){
	for(int i=1;i<=n;++i)son[i].clear();
	dfs(rt);/*int d[N*N];bool cvis[N*N],wvis[N];memset(cvis,0,sizeof(cvis)),memset(wvis,0,sizeof(wvis));*/
	for(option x:opt)if(dis[x.i][x.k]==dis[x.j][x.k])return false;
	for(option x:same)if(dis[x.i][x.k]!=dis[x.j][x.k])return false;
	/*for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			int fa=find(id(i,j));
			if(!cvis[fa]){
				if(wvis[dis[i][j]])return false;
				cvis[fa]=wvis[dis[i][j]]=true,d[fa]=dis[i][j];
			}
			else if(d[fa]!=dis[i][j])return false;
		}
	}*/
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),reset(n),opt.clear(),same.clear();
		bool tag=true,flg=false;
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				scanf("%s",s+1);
				for(int k=1;k<=n;++k){
					if(k==i||k==j){tag&=s[k]=='0';continue;}
					if(s[k]=='0')opt.push_back(option(k,i,j));
					if(s[k]=='1')f[find(id(i,k))]=find(id(j,k)),same.push_back(option(k,i,j));
				}
			}
		}
		for(option x:opt)if(find(id(x.i,x.k))==find(id(x.j,x.k)))tag=false;
		if(!tag){puts("No");continue;}
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)vec[find(id(i,j))].push_back(pr(i,j));
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				int fa=find(id(i,j));
				if((int)vec[fa].size()!=n-1)continue;grs();
				bool ntag=true;
				for(pr i:vec[fa]){
					int u=i.u,v=i.v;
					if(gfind(u)==gfind(v)){ntag=false;break;}
					g[gfind(u)]=gfind(v);
				}
				if(!ntag)continue;
				dnt=0,memset(head,0,sizeof(head)),memset(next,0,sizeof(next));
				for(pr i:vec[fa])addedge(i.u,i.v),addedge(i.v,i.u);
				if(chk()){
					flg=true,puts("Yes");
					for(pr i:vec[fa])printf("%d %d\n",i.u,i.v);
					break;
				}
			}
			if(flg)break;
		}
		if(!flg)puts("No");
	}
	return 0;
}
/*
1
5
00000 01001 00000 01100
00000 10000 00000
00000 11010
00000
*/