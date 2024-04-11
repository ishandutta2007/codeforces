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
#define maxx 105
#define maxc 15
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
using namespace FAST_IO;
int n,q,c,mx,my;
VI a[maxx][maxx];
int f[maxc][maxx][maxx];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=rd(),q=rd(),c=rd();
	rep(i,1,n) {
		int x=rd(),y=rd(),z=rd();
		a[x][y].pb(z-1);
	}
	rep(t,0,c) rep(i,1,100) rep(j,1,100) {
		f[t][i][j]=f[t][i-1][j]+f[t][i][j-1]-f[t][i-1][j-1];
	    rep(k,0,a[i][j].size()-1)
	    a[i][j][k]=a[i][j][k]+1>c?0:a[i][j][k]+1,f[t][i][j]+=a[i][j][k];
    }
    while(q--){
    	int t=rd()%(c+1),x1=rd(),y1=rd(),x2=rd(),y2=rd();
    	int ans=f[t][x2][y2]-f[t][x1-1][y2]-f[t][x2][y1-1]+f[t][x1-1][y1-1];
    	wrt(ans,'\n');
	}
	flush();
	return 0;
}