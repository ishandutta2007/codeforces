#include <bits/stdc++.h>
#define LL long long
#define jh(a,b) a^=b^=a^=b
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
const int R=1e5+3;
const int N=1e5+3;
struct milk
{
    int bj;
    LL sum;
    LL mids;
    LL cutt;
    int l,r;
    int ls,rs;
    bool mid;//
}t[N<<2];
struct cow
{
    int l,r;
    int t;
}q[N];
struct Wallace
{
    LL s;
    int num;
    bool z;
}a[N<<1];
LL to[N<<1];
int num;
int nam;
int l,r;
int n;
int k;
inline void bing(int i){t[i].cutt=t[t[i].ls].cutt+t[t[i].rs].cutt;t[i].cutt+=(t[i].mid)?t[i].mids:0;return;}
inline void down(int i)
{
    if(!t[i].bj)return;
    if(!t[i].ls)return;
    int ls=t[i].ls,rs=t[i].rs;
    if(t[i].bj<=2)
    {
        t[ls].bj=t[rs].bj=t[i].bj;
        t[ls].cutt=(t[i].bj==1)?(t[ls].sum):0;
        t[rs].cutt=(t[i].bj==1)?(t[rs].sum):0;
        (t[i].bj==1)?(t[ls].mid=t[rs].mid=1):(t[ls].mid=t[rs].mid=0);
    }
    else
    {
        t[ls].bj=3-t[ls].bj;
        t[rs].bj=3-t[rs].bj;
        t[ls].cutt=t[ls].sum-t[ls].cutt;
        t[rs].cutt=t[rs].sum-t[rs].cutt;
        t[ls].mid=!t[ls].mid;
        t[rs].mid=!t[rs].mid;
    }
    t[i].bj=0;
    return;
}
inline void cover_down(int i)
{
    down(i);
    if(l<=t[i].l&&t[i].r<=r)
    {
        t[i].bj=k;
        t[i].mid=(k==1)?1:0;
        t[i].cutt=(k==1)?t[i].sum:0;
        return;
    }
    if(t[t[i].ls].r>=l)cover_down(t[i].ls);
    if(t[t[i].rs].l<=r)cover_down(t[i].rs);
    if(l<=t[t[i].ls].r&&r>=t[t[i].rs].l)t[i].mid=(k==1)?1:0;
    bing(i);
    return;
}
inline void invert_down(int i)
{
    if(l<=t[i].l&&t[i].r<=r)
    {
        t[i].bj=3-t[i].bj;
        t[i].mid=!t[i].mid;
        t[i].cutt=t[i].sum-t[i].cutt;
        return;
    }
    down(i);
    if(t[t[i].ls].r>=l)invert_down(t[i].ls);
    if(t[t[i].rs].l<=r)invert_down(t[i].rs);
    if(l<=t[t[i].ls].r&&r>=t[t[i].rs].l)t[i].mid=!t[i].mid;
    bing(i);
    return;
}
inline LL cheak(int i)
{
    down(i);
    if(t[i].l==t[i].r||t[i].cutt==0)return (t[i].l!=1)?to[t[i].l]:1;
    if(t[i].cutt==t[i].sum)return to[t[i].r]+1;
    if(t[t[i].ls].cutt!=t[t[i].ls].sum)return cheak(t[i].ls);
    if(!t[i].mid&&t[i].mids!=0)return to[t[t[i].ls].r]+1;
    return cheak(t[i].rs);
}
struct Rin
{
    char c;
    inline char gc()
    {
        static char rea[R];
        static char *head=rea,*tail=rea;
        return head==tail&&(tail=(head=rea)+fread(rea,1,R,stdin),head==tail)?EOF:*head++;
    }
    inline Rin&operator >>(int &x)
    {
        x=0;
        char c;
        bool bj=false;
        for(c=gc();(c>'9'||c<'0')&&c!='-';c=gc());
        if(c=='-')bj=true,c=gc();
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(bj)x=-x;
        return *this;
    }
    inline Rin&operator >>(LL &x)
    {
        x=0;
        char c;
        bool bj=false;
        for(c=gc();(c>'9'||c<'0')&&c!='-';c=gc());
        if(c=='-')bj=true,c=gc();
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(bj)x=-x;
        return *this;
    }
    inline Rin&operator <<(int &x)
    {
        if(!x)putchar(48);
        else
        {
            static int a[66];
            static int lens=0;
            if(x<0){putchar('-');x=-x;}
            for(;x>0;x/=10)a[++lens]=x%10;
            for(;lens>0;lens--)putchar(a[lens]+48);
        }
        return *this;
    }
    inline Rin&operator <<(LL &x)
    {
        if(!x)putchar(48);
        else
        {
            static int a[66];
            static int lens=0;
            if(x<0){putchar('-');x=-x;}
            for(;x>0;x/=10)a[++lens]=x%10;
            for(;lens>0;lens--)putchar(a[lens]+48);
        }
        return *this;
    }
}rin;
inline void add(int now){(a[now].z)?q[a[now].num].r=num:q[a[now].num].l=num;return;}
inline bool myru(Wallace x,Wallace y){return x.s<y.s;}
inline void init(int l,int r,int i)
{
    t[i].l=l;t[i].r=r;
    t[i].bj=t[i].ls=t[i].rs=t[i].cutt=t[i].mid=0;
    t[i].sum=to[r]-to[l]+1;
    if(l==r)return;
    int mid=(l+r)>>1;
    t[i].mids=to[mid+1]-to[mid]-1;
    t[i].ls=++nam;init(l,mid,nam);
    t[i].rs=++nam;init(mid+1,r,nam);
    return;
}
int main()
{
    int i,j;
    bool if_have_1=false;
    rin>>n;
    for(i=1;i<=n;i++)
    {
        rin>>q[i].t>>a[i].s>>a[i+n].s;
        if(a[i].s==1||a[i+n].s==1)if_have_1=true;
        a[i].num=a[i+n].num=i;
        a[i].z=false;a[i+n].z=true;
    }
    if(!if_have_1){for(i=1;i<=n;i++)puts("1");return 0;}
    int m=(n<<1);
    sort(a+1,a+m+1,myru);
    for(i=1;i<=m;i=j){to[++num]=a[i].s;for(j=i;a[j].s==a[i].s;j++)add(j);}
    init(1,num,++nam);
    for(i=1;i<=n;i++)
    {
        l=q[i].l;r=q[i].r;
        k=q[i].t;
        if(q[i].t<=2)cover_down(1);
        else invert_down(1);
        printf("%lld\n",cheak(1));
    }
    return 0;
}