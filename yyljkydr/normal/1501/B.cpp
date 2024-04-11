#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
            a[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            int l=i-x+1,r=i;
            l=max(l,1);
            a[l]++,a[r+1]--;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            a[i]+=a[i-1];
            printf("%d ",a[i]>0);
        }
        puts("");
    }
}