#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(int i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(int i=(ll)(x);i>=(ll)(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define E(x)        return writeln(x),0
#define LL			(long long)
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*SS=SZB,*TT=SZB;
    inline char gc(){   if (SS==TT){  TT=(SS=SZB)+fread(SZB,1,GYN,stdin); if (SS==TT) return '\n';  }   return *SS++;    }
#if NEG
    inline ll read(){    ll x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(long long x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
	void writeln(ll x){write(x);puts("");}
	void Min(ll &x,ll y){x=x<y?x:y;}
	void Max(ll &x,ll y){x=x>y?x:y;}
}using namespace SHENZHEBEI;
const ll N=500010;
struct dt{
	ll x,y,id;
}a[N];
bool mark[40000010];
ll TTT,q[1000],pri[8000010];
ll dis[200000],vis[200010],answ[200010];
priority_queue<pa,vector<pa>,greater<pa> >Q;
bool cmp(dt a,dt b){return a.y<b.y;}
void Init(){
	TTT=40000000;
	For(i,2,TTT)if (!mark[i]){pri[++pri[0]]=i;for(ll j=2*i;j<=TTT;j+=i)mark[j]=1;}
}
void FenJie(ll x){
	q[0]=0;
	for(ll i=1;pri[i]*pri[i]<=x;++i)
	if (!(x%pri[i])){
		q[++q[0]]=pri[i];
		for(;!(x%pri[i]);x/=pri[i]);
	}
	if (x>1)q[++q[0]]=x;
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if (!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);y-=a/b*x;
}
ll mul(ll a,ll b,ll mod){
	ll ans=0;
	for(;b;b>>=1,a=(a+a)%mod)if (b&1)ans=(ans+a)%mod;
	return ans;
}
int main(){
	ll T=read();Init();
	For(i,1,T){
		ll x=read(),y=read();
		a[i]=(dt){x,y,i};
	}sort(a+1,a+T+1,cmp);
	for(ll i=1,j;i<=T;i=j+1){
		j=i;
		for(;a[j+1].y==a[i].y;)++j;
		FenJie(a[j].y);
		if (a[j].y==1)q[q[0]=1]=1e18+10000;
//		For(x,1,q[0])write(q[x]),putchar(' '),puts("");
		if (q[0]==1){
			For(k,i,j){
				answ[a[k].id]=a[k].x%q[1]?0:1;
			}
		}
		lf (q[0]==2){
			ll A=q[1],B=q[2],X,Y,XX,YY;
			exgcd(A,B,X,Y);X=(X%B+B)%B;
			exgcd(B,A,XX,YY);XX=(XX%A+A)%A;
			For(k,i,j){
				ll	n=a[k].x,x=n%A,y=n%B,
					ans=mul(x*XX,B,(A*B))+mul(y*X,A,(A*B));//k*a%b=1
//				writeln(ans);
				answ[a[k].id]=n<ans?0:1;
			}
		}
		else{
			memset(vis,0,sizeof vis);
			memset(dis,60,sizeof dis);dis[0]=0;
			Q.push(mk(0,0));
			for(;!Q.empty();){
				ll x=Q.top().se;Q.pop();
				if (vis[x])continue;vis[x]=1;
				For(j,2,q[0]){
					ll dist=dis[x]+q[j],to=dist%q[1];
					if (dis[to]>dist){
						dis[to]=dist;
						Q.push(mk(dis[to],to));
					}
				}
			}dis[0]=q[1];
			For(k,i,j)
				answ[a[k].id]=dis[a[k].x%q[1]]<=a[k].x?1:0;
		}
	}
	For(i,1,T)puts(answ[i]?"YES":"NO");
}