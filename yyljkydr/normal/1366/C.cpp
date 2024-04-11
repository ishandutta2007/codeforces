#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,m;

int c[N][2];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=2;i<=n+m;i++)
            c[i][0]=c[i][1]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                c[i+j][x]++;
            }
        int l=2,r=n+m;
        int ans=0;
        while(l<r)
        {
            int a=c[l][0]+c[r][0],b=c[l][1]+c[r][1];
            ans+=min(a,b);
            l++,r--;
        }
        printf("%d\n",ans);
    }
}