#include<bits/stdc++.h>
using namespace std;
const int S=1e7+5,N=1600,M=6e5,Z=755;
string s[Z];
bitset<Z>b[Z];
int n,i,j,k,aa[Z],nxt[Z],lst[Z];
struct ACM{
int ch[S][2],fail[S],lst[S],xb;
short id[S];
inline void ins(char*c,int l,int zz){
	int u=0,i=0,x;
	for(;i<l;++i){
		x=c[i]-'a';
		if(!ch[u][x])ch[u][x]=++xb;
		u=ch[u][x];
	}
	if(id[u])b[zz][id[u]]=1;
	id[u]=zz;
}
inline void bfs(){
//	static int q[S];
	int t=0,w=1,u,i,*q;q=new int[xb+2];q[1]=0;
	for(;t<w;)for(i=0,u=q[++t],lst[u]=id[fail[u]]?fail[u]:lst[fail[u]];i<2;++i)
		if(!ch[u][i])ch[u][i]=ch[fail[u]][i];else q[++w]=ch[u][i],fail[q[w]]=u?ch[fail[u]][i]:0;
}
inline void go(char*c,int l,int i){
	for(int j=0,u=0;j<l;++j){
		u=ch[u][c[j]-'a'];
		if(id[lst[u]])b[i][id[lst[u]]]=1;
		if(id[u] && j+1<l)b[i][id[u]]=1;
	}
}
}A;
struct graph{
	struct edge{int to,next,f;}e[M<<1];
	int h[N],cur[N],xb;
	inline void addedge(int x,int y,int z){
		e[++xb]=(edge){y,h[x],z};h[x]=xb;
		e[++xb]=(edge){x,h[y],0};h[y]=xb;
	}
	int S,T,d[N],n;
	inline bool bfs(){
		static int q[N];int t=0,w=1;q[1]=S;
		memset(d+1,0,n<<2);d[S]=1;
		for(;t<w;){
			int u=q[++t];
			for(int i=h[u];i;i=e[i].next)if(e[i].f && !d[e[i].to])
				d[e[i].to]=d[u]+1,q[++w]=e[i].to;
		}
		return d[T];
	}
	int dfs(int x,int f){
		if(x==T)return f;
		int ans=0,&i=cur[x],t;
		for(;i;i=e[i].next)if(e[i].f && d[e[i].to]==d[x]+1){
			if(t=dfs(e[i].to,min(f,e[i].f))){
				ans+=t,e[i].f-=t;e[i^1].f+=t;f-=t;
				if(!f)break;
			}
		}
		return ans;
	}
	inline int dinic(int s,int t){
		int ans=0;S=s;T=t;
		for(;bfs();ans+=dfs(s,1<<30))memcpy(cur+1,h+1,n<<2);
		return ans;
	}
	bool inm[N];int col[N],mch[N];
	void dfss(int x,int c){
		col[x]=c;
		if(c){for(int i=h[x];i;i=e[i].next)if(inm[e[i].to] && col[e[i].to]==-1)dfss(e[i].to,0);}
			else if(col[mch[x]]==-1)dfss(mch[x],1);
	}
	inline void getway(){
		int i,j;
		for(i=1;i<=::n;++i)for(j=h[i];j;j=e[j].next)if(e[j].to!=n-1 && !e[j].f)
			inm[i]=inm[e[j].to]=1,mch[i]=e[j].to,mch[e[j].to]=i;
		memset(col+1,-1,n<<2);
		for(i=1;i<=::n*2;++i)if(!inm[i])for(j=h[i];j;j=e[j].next)if(inm[e[j].to] && col[e[j].to]==-1)dfss(e[j].to,0);
		for(i=1;i<=::n*2;++i)if(inm[i] && col[i]==-1)
			dfss(i,0);
		vector<int>ans;
		for(i=1;i<=::n;++i)if((inm[i] && col[i]==0) || (inm[i+::n] && col[i+::n]==0));else ans.push_back(i);
		cout<<ans.size()<<'\n';	
		for(int x:ans)cout<<x<<' ';cout<<'\n';
	}
}G;
bool cmp(int x,int y){return s[x].size()<s[y].size();}
bool can[Z];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>s[i],A.ins(&s[i][0],s[i].size(),i);
	A.bfs();
	for(i=1;i<=n;++i)A.go(&s[i][0],s[i].size(),i),aa[i]=i;
	std::sort(aa+1,aa+n+1,cmp);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(b[aa[i]][j])b[aa[i]]|=b[j];
	G.n=n*2+2;G.xb=1;
	for(i=1;i<=n;++i)G.addedge(G.n-1,i,1),G.addedge(i+n,G.n,1);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(b[i][j])G.addedge(i,j+n,1);
	int zz=G.dinic(G.n-1,G.n);
	G.getway();
	return 0;
}