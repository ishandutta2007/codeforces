#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,P=998244353;

int T;

int n,A,B,a[N],b[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&A,&B,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        long long tot=0;
        for(int i=1;i<=n;i++)
            tot+=1ll*(b[i]+A-1)/A*a[i];
        int ok=0;
        for(int i=1;i<=n;i++)
        {
            tot-=1ll*(b[i]+A-1)/A*a[i];
            long long nw=1ll*((b[i]+A-1)/A-1)*a[i];
            if(tot+nw<B)
                ok=1;
            tot+=1ll*(b[i]+A-1)/A*a[i];
        }
        puts(ok?"YES":"NO");
    }    
}