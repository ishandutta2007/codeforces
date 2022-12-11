#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define PC Putchar
#define GC Getchar
#define ll long long
#define ldb long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define maxn 100005
using namespace std;
namespace FAST_IO {
    #define IN_LEN 500000
    #define OUT_LEN 500000
    inline char Getchar() {
        static char buf[IN_LEN], *l=buf,*r=buf;
        if (l==r) r=(l=buf)+fread(buf,1,IN_LEN,stdin);
        return (l==r)?EOF:*l++;
    }
    char obuf[OUT_LEN], *ooh = obuf;
    inline void Putchar(char c) {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout),ooh = obuf;
	    *ooh++ = c;
    }
    inline ll rd(){
	    ll x=0;int ch=Getchar(); bool f=1;
	    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=GC();
	    if (ch=='-'){f=0;ch=GC();}
	    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=GC();}
	    return f?x:-x;
    }
    void write(ll x){ if (x>=10) write(x/10),PC((char)(x%10+'0')); else PC((char)(x+'0')); }
    inline void wrt(ll x,int p){if (x<0) PC('-'),x=-x; write(x); if (p) PC((char)p);}
    inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}
namespace Treap {
	inline int Rand(){
	    static int seed= 23333;
	    return seed=(int)((((seed^998244353)+19260817ll)*19890604ll)%1000000007);
    }
	struct treap
    {
    	int ch[2];
	    ll val,fix,sz,sum;
    }trp[maxn];
    int cnt,n,m,root,com;
    inline void updata(int x)
    {
    	trp[x].sz=1+trp[trp[x].ch[1]].sz+trp[trp[x].ch[0]].sz;
    	trp[x].sum=trp[x].val+trp[trp[x].ch[1]].sum+trp[trp[x].ch[0]].sum;
    }
    inline int new_node(ll x)
    {
    	trp[++cnt].sz=1;trp[cnt].val=x;trp[cnt].sum=x;
    	trp[cnt].fix=Rand();
    	return cnt;
    }
    void split(int now,ll k,int &x,int &y)
    {
    	if (!now) x=y=0;
    	else {
    		if (trp[now].val<=k) x=now,split(trp[now].ch[1],k,trp[now].ch[1],y);
    		else y=now,split(trp[now].ch[0],k,x,trp[now].ch[0]);
    		updata(now);
    	}
    }
    int merge(int A,int B)
    {
    	if (!A||!B) return A+B;
    	if (trp[A].fix<trp[B].fix){trp[A].ch[1]=merge(trp[A].ch[1],B);updata(A); return A;}
    	trp[B].ch[0]=merge(A,trp[B].ch[0]);updata(B);return B;
    }
}
using namespace FAST_IO;
using namespace Treap;
int n;
ll t[maxn],v[maxn];
ll S;
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int n=rd();
	rep(i,1,n) v[i]=rd();
	rep(i,1,n) t[i]=rd();
	rep(i,1,n){
		//if (n==1E5&&i==84) wrt(trp[root].sum,' ');
		ll ne=v[i]+S;ll s=0;
		int x=0,y=0;
		split(root,ne,x,y);root=merge(merge(x,new_node(ne)),y);
		S+=t[i];
		split(root,S,x,y);
		s+=trp[x].sum-trp[x].sz*(S-t[i]);
		s+=trp[y].sz*t[i];
		root=y;
		wrt(s,' ');
	}
	PC('\n');
	flush();
}