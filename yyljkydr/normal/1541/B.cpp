#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N],p[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n*2;i++)
            p[i]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),p[a[i]]=i;
        int ans=0;
        for(int i=1;i<=n*2;i++)
        {
            if(!p[i])
                continue;
            for(int j=i;j<=n*2;j+=i)
            {
                if(!p[j/i])
                    continue;
                if(j==i*i)
                    continue;
                if(p[j/i]+p[i]==j)
                    ans++;
            }
        }
        printf("%d\n",ans/2);
    }
}