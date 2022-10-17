#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,k,a[N];

bool vis[10000002];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=2;j*j<=a[i];j++)
                while(a[i]%(j*j)==0)
                    a[i]/=j*j;
        }
        int ans=1;
        vis[a[1]]=1;
        int last=1;
        for(int i=2;i<=n;i++)
            if(vis[a[i]])
            {
                ans++;
                for(int j=last;j<i;j++)
                    vis[a[j]]=0;
                vis[a[i]]=1;
                last=i;
            }
            else
                vis[a[i]]=1;
        for(int i=last;i<=n;i++)
            vis[a[i]]=0;
        printf("%d\n",ans);
    }
}