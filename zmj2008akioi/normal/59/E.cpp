#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>
const int inf=1e9,N=3010,M=20010,K=100010;
int n,m,k,fn,cnt,dnt,h[K+N],rev[K+N],head[N],to[M<<1],next[M<<1],last[K+N],cc[N][N];
bool vis[K+N];
std::unordered_map<int,bool> map[K+N];
namespace basic{
	int lt,nw,res,dig[30];
	char cdc;
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x,char end=' '){
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar(end);
	}
}using basic::read;using basic::write;
inline void addedge(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
struct pr{
	int u,w,l;
	pr(){}
	pr(int u,int w,int l):u(u),w(w),l(l){};
	bool operator<(const pr &nxt)const{return w>nxt.w;}
};std::priority_queue<pr> heap;
struct stack{
	int p,arr[N];
	stack():p(0){}
	inline int size(){return p;}
	inline void push(int x){arr[++p]=x;}
	inline int top(){return arr[p--];}
}stack;
int main(){
	n=read(),m=read(),k=read(),cnt=n;
	for(int i=1;i<=n;++i)rev[i]=i;
	for(int u,v,i=1;i<=m;++i)u=read(),v=read(),addedge(u,v),addedge(v,u);
	for(int a,b,c,i=1;i<=k;++i){
		a=read(),b=read(),c=read();
		if(!cc[a][b])cc[a][b]=++cnt,rev[cnt]=b;
		map[cc[a][b]][c]=true;
	}
	for(int i=1;i<=cnt;++i)h[i]=inf;
	heap.push(pr(1,0,0));
	while(heap.size()){
		int u,w,l;
		pr nw;
		while(heap.size()&&vis[nw=heap.top(),nw.u])heap.pop();
		if(!heap.size())break;
		u=nw.u,w=nw.w,l=nw.l,h[u]=w,last[u]=l,l=rev[u],vis[u]=true,heap.pop();
		for(int i=head[rev[u]],v=to[i];i;v=to[i=next[i]]){
			if(map[u].find(v)!=map[u].end()||h[v]<=h[u]+1)continue;
			if(cc[rev[u]][v])v=cc[rev[u]][v];
			h[v]=h[u]+1,heap.push(pr(v,h[v],u));
		}
	}
	fn=n;
	for(int i=n+1;i<=cnt;++i)if(rev[i]==n&&h[i]<h[fn])fn=i;
	if(h[fn]==inf){puts("-1");return 0;}
	for(int i=fn;i;i=last[i])stack.push(rev[i]);
	write(stack.size()-1,'\n');
	while(stack.size())write(stack.top());
	return 0;
}