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
    inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}
using namespace FAST_IO;
int n,k;
char a[maxn];
bool le[200];
inline void solve()
{
	rep(i,1,n) PC(a[i]);
	rep(i,'a','z') 
	if (le[i]) {rep(j,1,k-n) PC((char)i);break;}
	PC('\n');
}
inline void solve1()
{
	int ans=0,lett,Min;
	drp(i,k,1)
	if (!ans)
	rep(j,a[i]+1,'z') 
	if (le[j]) {ans=i,lett=j;break;}
	rep(j,'a','z') if (le[j]){Min=j;break;}
	rep(i,1,ans-1) PC(a[i]);
	PC((char)lett);rep(i,ans+1,k) PC((char)Min);
	PC('\n');
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=rd(),k=rd();
	int ch=GC();while (!(ch>='a'&&ch<='z')&&(ch!=EOF)) ch=GC();
	rep(i,1,n) a[i]=ch,le[int(a[i])]=1,ch=GC();
	if (k>n) solve();
	else if (k<=n) solve1();
	flush();return 0;
}