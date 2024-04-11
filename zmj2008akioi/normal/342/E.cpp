#include <cstdio>
#include <queue>
const int rt=1,size=200,inf=1e9,N=1e5,PW=20,EXT=10;
int n,q,x,u,v,nw,opt,top,stack[size+EXT],ans[N+EXT],dep[N+EXT],head[N+EXT],to[2*N+EXT],next[2*N+EXT],dbl[PW+EXT][N+EXT];
char cdc;
bool vis[N+EXT];
std::queue<int> queue;
inline int min(int x,int y){return x<y?x:y;}
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline void addedge(int u,int v){static int dnt=0;++dnt,next[dnt]=head[u],head[u]=dnt,to[dnt]=v;}
void update(int u){for(register int i=head[u];i;i=next[i])if(ans[to[i]]==-1)ans[to[i]]=ans[u]+1,queue.push(to[i]);}
inline int read(){
	int res=0;
	for(;cdc<'0'||cdc>'9';cdc=getchar());
	for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
	return res;
}
inline void write(int x){
	static int lt,nw,dig[30];
	if(!x)putchar('0');
	for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
	for(;lt;--lt)putchar(dig[lt]^48);
	putchar('\n');
}
void dfs(int u){
	for(register int i=head[u];i;i=next[i]){
		if(dep[to[i]])continue;
		dep[to[i]]=dep[u]+1,dbl[0][to[i]]=u,dfs(to[i]);
	}
}
void rebuild(){
	top=0;
	for(register int i=1;i<=n;++i){
		ans[i]=vis[i]?0:-1;
		if(vis[i])queue.push(i);
	}
	while(queue.size())update(queue.front()),queue.pop();
}
int dist(int u,int v){
	int res=dep[u]+dep[v];
	if(dep[u]>dep[v])swap(u,v);
	for(register int i=PW-1;~i;--i)if(dep[u]+(1<<i)<=dep[v])v=dbl[i][v];
	if(u==v)return res-2*dep[u];
	for(register int i=PW-1;~i;--i)if(dbl[i][u]!=dbl[i][v])u=dbl[i][u],v=dbl[i][v];
	return res-2*dep[dbl[0][u]];
}
int main(){
	n=read(),q=read(),dep[rt]=1;
	for(register int i=2;i<=n;++i)u=read(),v=read(),addedge(u,v),addedge(v,u);
	vis[rt]=true,dfs(rt),stack[++top]=1;
	for(register int i=1;i<PW;++i)for(register int j=1;j<=n;++j)dbl[i][j]=dbl[i-1][dbl[i-1][j]];
	for(register int i=1;i<=q;++i){
		if(i%size==1)rebuild();
		opt=read(),x=read();
		if(opt==1)vis[x]=true,stack[++top]=x;
		if(opt==2){
			nw=ans[x];
			for(register int i=1;i<=top;++i)nw=min(nw,dist(x,stack[i]));
			write(nw);
		}
	}
	return 0;
}