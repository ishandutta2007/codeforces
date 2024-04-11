#include<bits/stdc++.h>
using   namespace   std;
#define ll long long
#define llu unsigned    long    long
#define ld  double
#define llu unsigned    long    long
#define rep(i,x,y)      for(ll  i=(ll)x;i<(ll)y;++i)
#define For(i,x,y)      for(ll  i=(ll)x;i<=(ll)y;++i)
#define FOr(i,x,y)      for(ll  i=(ll)(x);i>=(ll)(y);--i)
#define pi  acos(-1)    
#define mk  make_pair
#define pa  pair<ll,ll>
#define lf  else    if
#define IL  inline
#define max(x,y)                ((x)<(y)?(y):(x))
#define min(x,y)                ((x)<(y)?(x):(y))
#define sqr(x)                      ((x)*(x))
#define Mul(x,y)                ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)                ((x)=((x)+(y))%mod)
#define Max(x,y)                ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)                ((x)=((x)>(y)?(y):(x)))
#define E(x)                    return  writeln(x),0
#define LL                      (long   long)
#define p(x)                    printf("~%lld~\n",LL(x))
#define pp(x,y)                 printf("~~%lld	%lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)              printf("~~~%lld	%lld    %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)           printf("~~~%lld	%lld    %lld    %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)                 freopen(x".in","r",stdin)
#define f_out(x)                freopen(x".out","w",stdout)
#define open(x)                 f_in(x),f_out(x)
#define fi  first
#define se  second
#define GuYue       puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double>   E;
namespace   SHENZHEBEI{
#ifdef  LOCAL
                struct  _{_(){freopen("cf.in","r",stdin);}}_;
#endif  
#define NEG 1
                inline  char    gc(){   return  getchar();  }
#if NEG
                inline  ll  read(){             ll  x=0,fa=1;   char    ch=gc();            for (;!isdigit(ch);ch=gc()) if  (ch=='-')   fa=-1;      for (;isdigit(ch);ch=gc())      x=x*10-48+ch;           return  x*fa;   }
                inline  void    write(ll    x){             if  (x<0)    putchar('-'),x=-x;      if  (x>=10)          write(x/10);                putchar(x%10+'0');      }
#else
                inline  ll  read(){             ll  x=0;    char    ch=gc();            for (;!isdigit(ch);ch=gc());                for (;isdigit(ch);ch=gc())      x=x*10-48+ch;           return  x;          }
                inline  void    write(ll    x){             if  (x>=10)          write(x/10);                putchar(x%10+'0');      }
#endif
    void    writeln(ll  x){write(x);puts("");}
}using  namespace   SHENZHEBEI;
const ll N=1000010;
vector<ll>ans[N];
ll dfn[N],h[N],q[N],cur[N],head[N],nxt[N],vet[N],val[N],n1,n2,S,T,k,tot=1,LBC,m,answ;
void insert(ll x,ll y,ll w){nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;val[tot]=w;}
void AddEdge(ll x,ll y,ll w){insert(x,y,w);insert(y,x,0);}
bool bfs(){
	ll he=0,ta=1;q[1]=S;
	For(i,S,T)h[i]=-1;h[S]=0;
	for(;he!=ta;){
		ll x=q[++he];if (x==T)return 1;
		for(ll i=head[x];i;i=nxt[i])if (val[i]&&h[vet[i]]==-1)h[q[++ta]=vet[i]]=h[x]+1;
	}return 0;
}
ll dfs(ll x,ll f){
	if (x==T||!f)return f;
	ll used=0,w;
	for(ll i=cur[x];i;i=nxt[i])if (h[vet[i]]==h[x]+1){
		w=dfs(vet[i],min(val[i],f-used));
		val[i]-=w;val[i^1]+=w;used+=w;
		if (val[i])cur[x]=i;if (f==used)return f;
	}if (!used)h[x]=-1;return used;
}
ll dinic(){
	for(;bfs();){
		For(i,S,T)cur[i]=head[i];
		answ+=dfs(S,1e9);
	}
}
void calc(ll cogito){
	for(ll i=2;i<LBC;i+=2)if (val[i])ans[cogito].push_back(i/2);
}
int main(){
	n1=read(),n2=read(),m=read();
	S=0,T=n1+n2+1;k=1e9;
	For(i,1,m){ll x=read(),y=read();AddEdge(x,y+n1,1);++dfn[x];++dfn[y+n1];}
	For(i,1,n1+n2)Min(k,dfn[i]);
	LBC=tot;
	For(i,1,n1)AddEdge(S,i,dfn[i]-k);
	For(i,1,n2)AddEdge(i+n1,T,dfn[i+n1]-k);
	FOr(cogito,k,0){
		dinic();calc(cogito);
		for(ll i=LBC+1;i<tot;i+=2)val[i]++;
	}
	For(i,0,k){
		write(ans[i].size());putchar(' ');
		rep(j,0,ans[i].size())write(ans[i][j]),putchar(' ');puts("");
	}
}