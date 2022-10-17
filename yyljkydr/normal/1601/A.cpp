#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n,a[N],cnt[31];

vector<int>g[N];

int main()
{
    for(int i=1;i<=2e5;i++)
        for(int j=i;j<=2e5;j+=i)
            g[j].push_back(i);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        fill(cnt,cnt+30,0);
        int s=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=0;j<30;j++)
                if(a[i]>>j&1)
                    cnt[j]++,s++;
        }
        if(!s)
        {
            for(int i=1;i<=n;i++)
                printf("%d%c",i," \n"[i==n]);
            continue;
        }
        int x=0;
        for(int i=0;i<30;i++)
            x=__gcd(x,cnt[i]);
        for(auto p:g[x])
            printf("%d ",p);
        puts("");
    }
}