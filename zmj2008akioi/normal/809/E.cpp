#include <cstdio>
#include <algorithm>
const int PW=20,P=1e9+7,N=4e5+10;
int n,cnt,top,pdfn,fdnt[2],a[N],c[N],f[N],g[N],p[N],tp[N],rev[N],num[N],dep[N],dfn[N],prm[N],phi[N],stk[N],prd[N],ipr[N],inv[N],fhead[2][N],fto[2][N],fnext[2][N],dp[N][2],st[PW][N];
int *dnt,*head,*to,*next;long long ans,pans;bool dpr[N];
namespace basic{
	int lt,nw,res,dig[30];char c;
	int pd(int x,int y){return (long long)x*y%P;}
	template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
	int qpow(int b,int p){
		int pw=1,rs=1,nw=b,rm=p;
		for(;rm;pw<<=1,nw=pd(nw,nw))if(rm&pw)rm^=pw,rs=pd(rs,nw);
		return rs;
	}
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar('\n');
	}
}using basic::pd;using basic::swp;using basic::qpow;using basic::read;using basic::write;
int meg(int u,int v){return dep[u]<dep[v]?u:v;}
void sg(int x){dnt=&fdnt[x],head=fhead[x],to=fto[x],next=fnext[x];}
struct cmp{bool operator()(int a,int b){return dfn[a]<dfn[b];}};
void ad(int u,int v){next[++(*dnt)]=head[u],head[u]=*dnt,to[*dnt]=v;}
void dfs1(int u){
	dfn[u]=++pdfn,st[0][pdfn]=u;
	for(int i=head[u];i;i=next[i])if(!dfn[to[i]])p[to[i]]=u,dep[to[i]]=dep[u]+1,dfs1(to[i]);
}
void dfs2(int u){
	dp[u][0]=dp[u][1]=0;
	if(tp[u])dp[u][0]=phi[a[u]];
	for(int i=head[u];i;i=next[i]){
		int v=to[i];dfs2(v),dp[v][1]=(dp[v][1]+pd(dp[v][0],dep[v]-dep[u]))%P;
		pans+=pd(dp[u][0],dp[v][1])+pd(dp[u][1],dp[v][0]);
		dp[u][0]=(dp[u][0]+dp[v][0])%P,dp[u][1]=(dp[u][1]+dp[v][1])%P;
	}
}
int lca(int u,int v){
	int a=dfn[u],b=dfn[v];
	if(a>b)swp(a,b);++a;int c=num[b-a+1];
	return p[meg(st[c][a],st[c][b-(1<<c)+1])];
}
int main(){
	sg(0),n=read(),dep[0]=-1,prd[0]=phi[1]=1;
	for(int i=2;i<=n;++i){
		if(!dpr[i])phi[i]=i-1,prm[++cnt]=i;
		for(int v,j=1;j<=cnt&&(v=i*prm[j])<=n;++j){
			dpr[v]=true;if(i%prm[j]==0){phi[v]=phi[i]*prm[j];break;}
			phi[v]=phi[i]*(prm[j]-1);
		}
	}
	for(int i=2;i<=n;++i)num[i]=num[i>>1]+1;
	for(int i=1;i<=n;++i)a[i]=read(),rev[a[i]]=i,prd[i]=pd(prd[i-1],i);
	ipr[n]=qpow(prd[n],P-2);for(int i=n-1;~i;--i)ipr[i]=pd(ipr[i+1],i+1);
	for(int i=1;i<=n;++i)inv[i]=pd(ipr[i],prd[i-1]);
	for(int u,v,i=1;i<n;++i)u=read(),v=read(),ad(u,v),ad(v,u);dfs1(1),sg(1);
	for(int i=1;i<PW;++i)for(int j=1;j+(1<<i)-1<=n;++j)st[i][j]=meg(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(int i=n;i;--i){
		pans=cnt=0;for(int j=i;j<=n;j+=i)c[++cnt]=rev[j];
		std::sort(c+1,c+cnt+1,cmp()),stk[top=1]=c[1];
		for(int j=1;j<=cnt;++j)tp[c[j]]=1;
		for(int j=2;j<=cnt;++j){
			g[j]=lca(c[j-1],c[j]);
			while(dep[stk[top]]>dep[g[j]]){
				if(dep[stk[top-1]]<dep[g[j]])ad(g[j],stk[top]);
				else ad(stk[top-1],stk[top]);--top;
			}
			if(stk[top]!=g[j])stk[++top]=g[j];
			stk[++top]=c[j];
		}
		while(top>1)ad(stk[top-1],stk[top]),--top;
		dfs2(stk[1]),*dnt=0,f[i]=pans%P;
		for(int j=1;j<=cnt;++j)tp[c[j]]=head[c[j]]=head[g[j]]=0;
		for(int j=i<<1;j<=n;j+=i)f[i]=(f[i]-f[j]+P)%P;
		ans+=pd(f[i],pd(i,inv[phi[i]]));
	}
	write(pd((ans<<1)%P,pd(inv[n-1],inv[n])));return 0;
}