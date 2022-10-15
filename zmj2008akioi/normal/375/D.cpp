#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
const int rt=1,b=500,B=510,C=1e5,N=1e5+10;
int n,m,nw,ans,dnt,c[N],ft[N],bkt[N],head[N],to[N<<1],next[N<<1],pans[N][B];
bool vis[N];
std::vector<int> vec;
std::unordered_map<int,int> map[N];
std::unordered_map<int,std::vector<int>> tim;
namespace basic{
	int lt,nw,res,dig[30];
	char cdc;
	inline int min(int x,int y){return x<y?x:y;}
	inline void swap(int &x,int &y){x^=y^=x^=y;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar('\n');
	}
}using basic::min;using basic::swap;using basic::read;using basic::write;
inline void addedge(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
void merge(int a,int b){
	//merge b to a
	int fa=ft[a],fb=ft[b];
	if(map[fa].size()<map[fb].size())swap(fa,fb),swap(ft[a],ft[b]),memcpy(pans[a],pans[b],sizeof(pans[a]));
	for(auto i:map[fb])while(i.second--)if(++map[fa][i.first]<=::b)++pans[a][map[fa][i.first]];
}
void dfs1(int u){
	vis[u]=true,tim[nw][u]=c[u]==nw;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;
		dfs1(to[i]),tim[nw][u]+=tim[nw][to[i]];
	}
	vis[u]=false;
}
void dfs2(int u){
	vis[u]=true,map[u][c[u]]=pans[u][1]=1;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;
		dfs2(to[i]),merge(u,to[i]);
	}
	vis[u]=false;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)ft[i]=i,++bkt[c[i]=read()];
	for(int i=1;i<=C;++i)if(bkt[i]>b)vec.push_back(i),tim[i].resize(C+1);
	for(int u,v,i=2;i<=n;++i)u=read(),v=read(),addedge(u,v),addedge(v,u);
	for(int i:vec)nw=i,dfs1(rt);
	dfs2(rt);
	for(int u,k,i=1;i<=m;++i){
		u=read(),k=read();
		//if(i!=1)u=(u+ans)%n+1;
		if(k>b){
			ans=0;
			for(int j:vec)ans+=tim[j][u]>=k;
		}
		else ans=pans[u][k];
		write(ans);
	}
	return 0;
}