#include<bits/stdc++.h>
#define maxn 200050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,a[maxn];

LL cnt[maxn];

bool vis[maxn];
vector<int> A;

int T[maxn];

LL F[maxn]={1};

LL inv(LL a)
{
    LL ans=1;
    for (int k=modu-2;k;k>>=1)
    {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int lowbit(int i)
{
    return i&(-i);
}

void change(int i)
{
    for (;i;i-=lowbit(i))
        ++T[i];
}

int query(int i)
{
    int ans=0;
    for (;i<=n;i+=lowbit(i))
        ans+=T[i];
    return ans;
}

LL C2(LL n)
{
    return n*(n-1)/2%modu;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  F[i]=F[i-1]*i%modu;
    
    LL ans=0;
    for (int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        if (!~a[i]) continue;
        vis[a[i]]=1;
        ans+=query(a[i]);
        change(a[i]);
    }

    for (int i=1;i<=n;++i)
        if (!vis[i])
            A.push_back(i);
    
    // for (auto x:A)
    //     cout<<x<<" ";
    // cout<<endl;

    ans=(ans+C2(A.size())*inv(2))%modu;

    // cout<<ans<<endl;

    for (int i=1;i<=n;++i)
    {
        cnt[i]=cnt[i-1]+(a[i]==-1);
        if (!~a[i]) continue;
        int c1=A.end()-lower_bound(A.begin(),A.end(),a[i]),c2=A.size()-c1;

        // cout<<i<<" "<<c1<<" "<<c2<<endl;
        LL t=(cnt[i]*c1+(A.size()-cnt[i])*c2)%modu*inv(A.size())%modu;
        ans=(ans+t)%modu;
    }
    printf("%lld\n",ans);
    return 0;
}