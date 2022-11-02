#include<bits/stdc++.h>
#define maxn 500050
using namespace std;

int n,m;
int a[maxn];

void init()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
}

int R[maxn],T[maxn],cnt[maxn];

void solve()
{
    for (int i=n;i;--i)
        R[i]=R[i+1]+(a[i]==m);
    
    memset(T,0x3f,sizeof(T));
    int sum=0,ans=0;
    for (int i=1;i<=n;++i)
    {
        T[a[i]]=min(T[a[i]],-sum+cnt[a[i]]++);
        ans=max(ans,cnt[a[i]]-T[a[i]]+R[i+1]);
        sum+=a[i]==m;
    }
    printf("%d\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}