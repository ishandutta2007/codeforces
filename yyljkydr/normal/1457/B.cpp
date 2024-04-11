#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k,c[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        int ans=1e9;
        for(int i=1;i<=100;i++)
        {
            int tot=0;
            for(int j=1,t;j<=n;j=t)
            {
                if(c[j]==i)
                    t=j+1;
                else
                    t=j+k,tot++;
            }
            ans=min(ans,tot);
        }
        printf("%d\n",ans);
    }
}