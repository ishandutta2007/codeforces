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
#define I __attribute__((always_inline))inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=202;

int n,m,k,s[N][N];
bool e[N][N];
int pans;

int ds[N],dt[N],us[N],ut[N],cs[N][N],ct[N][N];

inline bool chk(int x,int y,int z)
{
	return x>=z&&x*k<=y;
}

inline uint rr()
{
	static uint S=192608170;
    S^=S<<13;
    S^=S>>17;
    S^=S<<5;
    return S;
}

const int qm=511;
int qb,qe,q[qm+1];
bool vis[N*2];

inline void add(int x)
{
	if(!vis[x])q[qe++&qm]=x,vis[x]=1;
}

inline void addfs(int x,int c)
{
	if(!chk(cs[x][c],ds[x],us[x]))add(x);
}

inline void addft(int x,int c)
{
	if(!chk(ct[x][c],dt[x],ut[x]))add(x+n);
}

int ni[N],mi[N],ki[N];

inline void shuffle(int*S,int n)
{
	fo0(i,7)std::swap(S[rr()%n+1],S[rr()%n+1]);
}

inline void fixs(int x)
{
	//out,"fixs:",x,'\n';
	int l=us[x],r=us[x]+bool(ds[x]%k),i,j;
	shuffle(mi,m);
	fo1(i_,m)if(i=mi[i_],cs[x][s[x][i]]>r)
	{
		do j=rr()%k+1;while(cs[x][j]>=r);
		cs[x][s[x][i]]--;
		cs[x][j]++;
		ct[i][s[x][i]]--;
		ct[i][j]++;
		addft(i,s[x][i]);
		addft(i,j);
		s[x][i]=j;
		//assert(chkdeg());
	}
	shuffle(ki,k);
	fo1(i_,k)for(i=ki[i_];cs[x][i]<l;)
	{
		do j=rr()%m+1;while(cs[x][s[x][j]]<=l);
		//assert(s[x][j]);
		cs[x][s[x][j]]--;
		cs[x][i]++;
		ct[j][s[x][j]]--;
		ct[j][i]++;
		addft(j,s[x][j]);
		addft(j,i);
		s[x][j]=i;
		//assert(chkdeg());
	}
}

inline void fixt(int x)
{
	//out,"fixt:",x,'\n';
	int l=ut[x],r=ut[x]+bool(dt[x]%k),i,j;
	shuffle(ni,n);
	fo1(i_,n)if(i=ni[i_],ct[x][s[i][x]]>r)
	{
		do j=rr()%k+1;while(ct[x][j]>=r);
		ct[x][s[i][x]]--;
		ct[x][j]++;
		cs[i][s[i][x]]--;
		cs[i][j]++;
		addfs(i,s[i][x]);
		addfs(i,j);
		s[i][x]=j;
		//assert(chkdeg());
	}
	shuffle(ki,k);
	fo1(i_,k)for(i=ki[i_];ct[x][i]<l;)
	{
		do j=rr()%n+1;while(ct[x][s[j][x]]<=l);
		//assert(s[j][x]);
		ct[x][s[j][x]]--;
		ct[x][i]++;
		cs[j][s[j][x]]--;
		cs[j][i]++;
		addfs(j,s[j][x]);
		addfs(j,i);
		s[j][x]=i;
		//assert(chkdeg());
	}
}

void Modify(int x,int y)
{
	//out,"modify:",x,' ',y,'\n';
	ds[x]++,dt[y]++;
	int u=ds[x]%k;
	if(u==0)pans--,us[x]++;else if(u==1)pans++;
	u=dt[y]%k;
	if(u==0)pans--,ut[y]++;else if(u==1)pans++;
	e[x][y]=1;
	fo1(i,k)if(chk(cs[x][i]+1,ds[x],us[x])&&chk(ct[y][i]+1,dt[y],ut[y]))
	{
		s[x][y]=i;
		cs[x][i]++,ct[y][i]++;
		return;
	}
	int gg=rr()%k+1;s[x][y]=gg,cs[x][gg]++,ct[y][gg]++;
	qb=qe=0;
	if(!chk(cs[x][s[x][y]],ds[x],us[x]))add(x);
	if(!chk(ct[y][s[x][y]],dt[y],ut[y]))add(y+n);
	while(qb<qe)
	{
		int x=q[qb++&qm];
		if(x<=n)fixs(x);else fixt(x-n);
		vis[x]=0;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int q;
	in,n,m,q,k;
	if(k==1)
	{
		out,0,'\n';
		fo1(i,q)out,1,' ';out,'\n';
		return 0;
	}
	fo1(i,n)ni[i]=i;
	fo1(i,m)mi[i]=i;
	fo1(i,k)ki[i]=i;
	std::vector<pii>e;
	fo1(i,q)
	{
		int x,y;
		in,x,y;
		Modify(x,y);
		e.pb(mp(x,y));
		//if(rand()%10==0)chkans();
	}
	out,pans,'\n';
	foe(i,e)out,s[i->xx][i->yy],' ';out,'\n';
}