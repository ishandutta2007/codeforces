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
#define maxn 200005
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
    void write(unsigned ll x){ if (x>=10) write(x/10),PC((char)(x%10+'0')); else PC((char)(x+'0')); }
    inline void wrt(unsigned ll x,int p){if (x<0) PC('-'),x=-x; write(x); if (p) PC((char)p);}
    inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}
namespace Treap {
    int cnt,root;
    inline int rand(){
        static int seed=2333;
        return seed=int((((seed^998244353)+19260817ll)*19890604ll)%1000000007);
    }
    struct Treap
    {
        int sz,ch[2],val,fix;
        ll sum;
    }trp[maxn];
    inline int new_node(int val){
        trp[++cnt].fix=rand();trp[cnt].val=trp[cnt].sum=val;
        trp[cnt].sz=1;return cnt;
    }
    inline void updata(int p) {trp[p].sum=trp[trp[p].ch[0]].sum+trp[trp[p].ch[1]].sum+trp[p].val;
    trp[p].sz=trp[trp[p].ch[0]].sz+trp[trp[p].ch[1]].sz+1; }
    void split(int now,int k,int &x,int &y)
    {
        if (!now) x=y=0;
        else { 
            if (trp[now].val<=k) x=now,split(trp[now].ch[1],k,trp[x].ch[1],y);
            else y=now,split(trp[now].ch[0],k,x,trp[y].ch[0]);
            updata(now);
        }
    }
    int merge(int x,int y)
    {
        if (!x||!y) return x+y;
        if (trp[x].fix<trp[y].fix) {trp[x].ch[1]=merge(trp[x].ch[1],y);updata(x);return x;}
        else {trp[y].ch[0]=merge(x,trp[y].ch[0]);updata(y);return y;}
    }
}
using namespace FAST_IO;
using namespace Treap;
int n;
int a[maxn];
unsigned ll sum1,sum2;
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    n=rd();
    rep(i,1,n) a[i]=rd();
    root=new_node(a[n]);
    drp(i,n-1,1){
        int x,y,z,q,rt;
        split(root,a[i]+1,x,y);
        split(x,a[i]-2,z,x);
        split(x,a[i],x,q);
        sum1+=(1ll*a[i]*trp[z].sz-trp[z].sum);
        sum2+=(trp[y].sum-1ll*a[i]*(trp[y].sz));
        rt=merge(merge(x,new_node(a[i])),q);
        root=merge(merge(z,rt),y);
    }
    if (sum1>sum2) PC('-'),wrt(sum1-sum2,'\n');
    else wrt(sum2-sum1,'\n');
    flush();return 0;
}