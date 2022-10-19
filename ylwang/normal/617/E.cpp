#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=100010,M=1200010;
int n,m,k,l,r,T,cnt[M],a[N],pos[N];
ll ans;

struct Ask
{
    int l,r,id;
    ll ans;
}ask[N];

ll write(ll x)
{
    if (x>9) write(x/10);
    putchar(x%10+48);
} 

bool cmp1(Ask x,Ask y)  //
{
    if (pos[x.l]<pos[y.l]) return 1;
    if (pos[x.l]>pos[y.l]) return 0;
    return x.r<y.r;
}

bool cmp2(Ask x,Ask y)
{
    return x.id<y.id;
}

void add(int x)
{
    ans+=(ll)cnt[a[x]^k];  //a[x]^k
    cnt[a[x]]++;
}

void del(int x)
{
    cnt[a[x]]--;
    ans-=(ll)cnt[a[x]^k];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    T=(int)sqrt(n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]^=a[i-1];
        pos[i]=(i-1)/T+1;
    } 
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&ask[i].l,&ask[i].r);
        ask[i].l--;
        ask[i].id=i;
    }
    sort(ask+1,ask+1+m,cmp1);
    cnt[0]=1;
    for (int i=1;i<=m;i++)
    {
        for (;l<ask[i].l;l++) del(l);
        for (;l>ask[i].l;l--) add(l-1);
        for (;r<ask[i].r;r++) add(r+1);
        for (;r>ask[i].r;r--) del(r);
        ask[i].ans=ans;  //
    }
    sort(ask+1,ask+1+m,cmp2);
    for (int i=1;i<=m;i++)
        write(ask[i].ans),putchar(10);
    return 0;
}