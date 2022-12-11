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
}
using namespace FAST_IO;
int n;
ll s;
struct peo
{
	ll x,v;
	ll t;
}a[maxn];
int g[1000007],g1[1000007];
inline int Pos(ll t,int k)
{
	ldb p=t/100000000.0;
	int l=a[k].x,r=1E6;
	while (r-l>1){
		int mid=(l+r)>>1;
		ldb d1=(mid-a[k].x)/double(s-a[k].v),d=a[k].x;
		if ((d1+(d-d1*double(a[k].v))/double(a[k].v+s))<=p) l=mid;
		else r=mid;
	}
	ldb d1=(r-a[k].x)/double(s-a[k].v),d=a[k].x;
	if ((d1+(d-d1*double(a[k].v))/double(a[k].v+s))<=p) return r;
	else return l;
}
inline int pos(ll t,int k)
{
	ldb p=t/100000000.0;
	int l=0,r=a[k].x;
	while (r-l>1){
		int mid=(l+r)>>1;
		ldb d1=(a[k].x-mid)/double(s-a[k].v),d=1E6-a[k].x;
		if (d1+(d-d1*double(a[k].v))/double(a[k].v+s)<=p) r=mid;
		else l=mid;
	}
	ldb d1=(a[k].x-l)/double(s-a[k].v),d=1E6-a[k].x;
	if (d1+(d-d1*double(a[k].v))/double(a[k].v+s)<=p) return l;	
	return r;
}
inline bool check(ll k)
{
	ldb p=k/100000000.0;
	int ans=0,ans1=0;
	memset(g,0,sizeof(g));
	memset(g1,0,sizeof(g1));
	rep(i,1,n)
	if (a[i].t==1){
		int x=Pos(k,i),y=a[i].x;
		if (a[i].v>double(a[i].x)/(p)) x=1E6,y=0;
		if ((a[i].v+s)<double(a[i].x)/p) x=y-1;
		g[y]++;g[x+1]--;
	}
	else {
		int x=pos(k,i),y=a[i].x;
		if (a[i].v>double(1E6-a[i].x)/(p)) x=0,y=1E6;
		if (a[i].v+s<double(1E6-a[i].x)/(p)) y=x-1;
		g1[x]++,g1[y+1]--;
	}
	rep(i,0,1E6){
		ans+=g[i],ans1+=g1[i];
		if (ans&&ans1) return 1;
	}
	return 0;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=rd(),s=rd();
	rep(i,1,n) a[i].x=rd(),a[i].v=rd(),a[i].t=rd();
	ll l=0,r=1ll*1E6*1E8;
	while (r-l>1){
		ll mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	if (check(l)) printf("%.8lf\n",l/100000000.0);
	else printf("%.8lf\n",r/100000000.0);
	return 0;
}