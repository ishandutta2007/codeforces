#include <stdio.h>
#define LL long long
using namespace std;
const int N=6e5+3;
const LL INF=0x3f3f3f3f3f3f3f3f;
int n,m;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

struct gyq
{
    LL s[3];
    LL f[3][3];
    inline void init(){s[0]=0;s[1]=rin();s[2]=rin();for(int i=0;i<=2;i++)for(int j=0;j<=2;j++)f[i][j]=s[j]-s[i];return;}
}a[N];

int cts[N];
inline void jh(int &x,int &y){x^=y^=x^=y;return;}
struct zjj
{
    int tail;
    LL s[N];
    int d[N];
    int num[N];
    inline void jh_(int &x,int &y){jh(d[x],d[y]);jh(x,y);return;}
    inline void down(int x)
    {
        if((x<<1)>tail)return;
        int next=x;
        if(s[d[x<<1]]<s[d[next]])next=(x<<1);
        if(((x<<1)|1)<=tail&&s[d[(x<<1)|1]]<s[d[next]])next=((x<<1)|1);
        if(next!=x)jh_(num[d[next]],num[d[x]]),down(next);
        return;
    }
    inline void up(int x)
    {
        if(x==1||tail==0)return;
        if(s[d[x>>1]]>s[d[x]])jh_(num[d[x>>1]],num[d[x]]),up(x>>1);
        return;
    }
    inline void delete_(int x)
    {
        int now=num[x];
        if(now==tail){tail--;return;}
        jh_(num[x],num[d[tail]]);
        tail--;
        down(now);
        up(now);
        return;
    }
    inline void push_(int x,LL val)
    {
        s[x]=val;
        d[++tail]=x;
        num[x]=tail;
        up(tail);
        return;
    }
    inline LL find(){return (tail)?(s[d[1]]):(INF);}
    inline void kill_(int ans){for(int i=1;i<=tail;i++)cts[d[i]]=ans;return;}
}t[5];

inline void add_0(int x){t[0].push_(x,a[x].f[0][1]);t[1].push_(x,a[x].f[0][2]);return;}
inline void add_1(int x){t[2].push_(x,a[x].f[1][2]);t[3].push_(x,a[x].f[1][0]);return;}
inline void add_2(int x){t[4].push_(x,a[x].f[2][1]);return;}
inline void delete_0(int x){t[0].delete_(x);t[1].delete_(x);return;}
inline void delete_1(int x){t[2].delete_(x);t[3].delete_(x);return;}
inline void delete_2(int x){t[4].delete_(x);return;}

LL ans;
LL mins;
int last;
inline void work(int x,int y,int z)
{
    LL sum=t[x].find()+t[y].find();
    if(mins>sum)mins=sum,last=z;
    return;
}
inline void work_(int x,int z)
{
    LL sum=t[x].find();
    if(mins>sum)mins=sum,last=z;
    return;
}
int main()
{
    // printf("%d\n",INF);
    int i,j;
    n=rin();m=rin();
    for(i=0;i<5;i++)t[i].tail=0;
    for(i=1;i<=n;i++)a[i].init(),add_0(i);
    for(i=1;i<=m;i++)
    {
        mins=INF;
        last=-1;
        work(1,4,1);
        work(1,3,2);
        work_(2,3);
        work_(0,4);
        //685685440661
        //685685525618
        ans+=mins;
        // printf("mins:%lld\n",mins);
        if(last==1)add_2(t[1].d[1]),delete_0(t[1].d[1]),add_1(t[4].d[1]),delete_2(t[4].d[1]);
        if(last==2)add_2(t[1].d[1]),delete_0(t[1].d[1]),add_0(t[3].d[1]),delete_1(t[3].d[1]);
        if(last==3)add_2(t[2].d[1]),delete_1(t[2].d[1]);
        if(last==4)add_1(t[0].d[1]),delete_0(t[0].d[1]);
    }
    printf("%lld\n",ans);
    t[0].kill_(0);
    t[2].kill_(1);
    t[4].kill_(2);
    for(int i=1;i<=n;i++)printf("%d",cts[i]);printf("\n");
    return 0;
}