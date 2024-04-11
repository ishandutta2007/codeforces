#include<bits/stdc++.h>
#define maxn 300050
#define maxm 1000500
using namespace std;
typedef long long LL;

int n,m;
int a[maxn],b[maxn];

bool noprime[maxm];
int p[maxm],pnum;
int newa[maxm];


void predo()    {
    newa[1]=1;
    for (int i=2;i<maxm;++i)  {
        if (!noprime[i])    {
            newa[i]=i;
            p[pnum++]=i;
        }
        for (int j=0;j<pnum&&p[j]*i<maxm;++j)   {
            noprime[i*p[j]]=1;
            if (i%p[j])
                newa[i*p[j]]=newa[i]*p[j];
            else    {
                newa[i*p[j]]=newa[i/p[j]];
                break;
            }
        }
    }
}

int ans[maxn];
int cnt[maxm];

int main()  {
    predo();

    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",a+i);
        for (int i=1;i<=n;++i) a[i]=newa[a[i]];

        // for (int i=1;i<=n;++i) cout<<a[i]<<" "; cout<<endl;

        for (int t=0;t<=10;++t) {
            for (int i=1;i<=n;++i)
                ++cnt[b[i]=a[i]];
            ans[t]=0;
            for (int i=1;i<=n;++i)
                ans[t]=max(ans[t],cnt[a[i]]);
            
            for (int i=1;i<=n;++i)
                if (~cnt[a[i]]&1)
                    a[i]=1;
            
            for (int i=1;i<=n;++i)
                cnt[b[i]]=0;
        }

        scanf("%d",&m);
        while (m--) {
            LL t;
            scanf("%lld",&t);
            t=min(t,10LL);
            printf("%d\n",ans[t]);
        }
    }
    return 0;
}