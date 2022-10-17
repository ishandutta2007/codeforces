#include<bits/stdc++.h>
using namespace std;

const int N=117;

int T;

int n,k,h[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&h[i]);
        h[n+1]=-1;
        int ans;
        for(int i=1;i<=k;i++)
        {
            int j=1;
            while(h[j]>=h[j+1]&&j<=n)
                j++;
            if(j==n+1)
            {
                ans=-1;
                break;
            }
            h[j]++;
            if(i==k)
                ans=j;
        }
        printf("%d\n",ans);
    }
}