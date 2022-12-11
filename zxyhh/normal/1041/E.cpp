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
#define maxn 1005
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
	    ll x=0;int ch=GC(); bool f=1;
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
int X[maxn],Y[maxn],cnt,a[maxn],b[maxn],vis[maxn],st[maxn],top;
int n,m;
inline void Add(int u,int v){X[++cnt]=u,Y[cnt]=v;}
inline bool cmp(int A,int B){return A>B;}
inline int gcd(int A,int B){return B==0?A:gcd(B,A%B);}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    n=rd();
    rep(i,1,n-1){
        vis[a[i]=rd()]=1,b[i]=rd();
        if(a[i]>b[i]) swap(a[i],b[i]);
    }
    rep(i,1,n-1) if (b[i]!=n) {PC('N'),PC('O'),PC('\n');flush();return 0;} 
    rep(i,1,n-1) if (!vis[i]) st[++top]=i;
    sort(a+1,a+1+n,cmp);
    m=n;
    int q=233;
    for(int i=2,la=1;i<=n;i++)
        if (a[i]!=a[i-1]){
            int j=i-la-1;
            if (top<j){PC('N'),PC('O'),PC('\n');flush();return 0;}
            rep(k,1,j){
                if (st[top]>a[i-1]) {PC('N'),PC('O'),PC('\n');flush();return 0;}
                Add(m,st[top]),m=st[top--];
            }
            q+=gcd(q,b[i]);
            Add(m,a[i-1]),m=a[i-1];
            la=i;
        }
    PC('Y'),PC('E'),PC('S'),PC('\n');;
    rep(i,1,cnt) wrt(X[i],' '),wrt(Y[i],'\n');
    flush();
    return 0;
}