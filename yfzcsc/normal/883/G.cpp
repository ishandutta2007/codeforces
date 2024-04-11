#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=300007;

struct _e
{
	int o,x,y;
}e[N];

std::vector<pii>p[N];
int n,m,s,c,a1[N],a2[N];
bool vis[N];

inline void dfs1(int x)
{
	if(vis[x])return;
	vis[x]=1;
	foe(i,p[x])
	{
		if(!i->yy)
			dfs1(i->xx);
		else
		{
			if(a1[abs(i->yy)])continue;
			a1[abs(i->yy)]=i->yy>0?1:2;
			dfs1(i->xx);
		}
	}
}

inline void dfs2(int x)
{
	if(vis[x])return;
	vis[x]=1;
	foe(i,p[x])
	{
		if(!i->yy)dfs2(i->xx);
	}
}

inline void dfs3(int x,int*a)
{
	if(vis[x])return;
	vis[x]=1;
	foe(i,p[x])
	{
		if(!i->yy)
			dfs3(i->xx,a);
		else
		{
			if(a[abs(i->yy)]==(i->yy>0?1:2))dfs3(i->xx,a);
		}
	}
}

int main()
{
	in,n,m,s;
	fo1(i,m)
	{
		in,e[i].o,e[i].x,e[i].y;
		if(e[i].o==1)
		{
			p[e[i].x].pb(mp(e[i].y,0));
		}
		else
		{
			++c;
			p[e[i].x].pb(mp(e[i].y,c));
			p[e[i].y].pb(mp(e[i].x,-c));
		}
	}
	dfs1(s);
	mset(vis,0);
	dfs2(s);
	c=0;
	fo1(i,m)if(e[i].o==2)
	{
		++c;
		if(vis[e[i].x]&&!vis[e[i].y])
			a2[c]=2;
		else a2[c]=1;
	}
	int t=0;
	mset(vis,0);
	dfs3(s,a1);
	fo1(i,n)t+=vis[i];
	out,t,'\n';
	fo1(i,c)out,a1[i]==1?'+':'-';out,'\n';
	t=0;
	mset(vis,0);
	dfs3(s,a2);
	fo1(i,n)t+=vis[i];
	out,t,'\n';
	fo1(i,c)out,a2[i]==1?'+':'-';out,'\n';
}