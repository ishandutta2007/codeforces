#include<bits/stdc++.h>
using namespace std;

const int N=1e7+1e3+7;

int T,n,a[N],b[N],t[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&t[i]);
        int now=0;
        for(int i=1;i<=n;i++)
        {
            now+=a[i]-b[i-1]+t[i];
            if(i==n)
            {
                printf("%d\n",now);
                break;
            }
            now+=max((b[i]-a[i]+1)/2,b[i]-now);
        }
    }
}