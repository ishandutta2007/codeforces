#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T,n;

int d[N];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n*2;i++)
            scanf("%lld",&d[i]);
        sort(d+1,d+n*2+1);
        bool flag=1;
        int sum=0,tot=0;
        for(int i=1;i<=n*2;i+=2)
        {
            if(d[i]!=d[i+1])
                flag=0;
            if(d[i]&1)
                flag=0;
            if(d[i]==d[i-1])
                flag=0;
            if(i>1)
            {
                if((d[i]-d[i-1])%(i-1)!=0)
                    flag=0;
                sum+=(d[i]-d[i-1])/(i-1);
                tot+=sum;
            }
        }
        tot*=2;
        if(d[1]<=tot||(d[1]-tot)%(n*2))
            flag=0;
        puts(flag?"YES":"NO");
    }
}