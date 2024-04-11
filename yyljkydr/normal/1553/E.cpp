#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n,m;

int p[N],cnt[N],to[N],vis[N];

vector<int>ans;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&p[i]),cnt[(i-p[i]+n)%n]++;
        for(int k=0;k<n;k++)
        {
            if(cnt[k]<n-2*m)
                continue;
            for(int j=1;j<=n;j++)
                if((j-p[j]+n)%n!=k)
                    to[j]=(p[j]+k-1)%n+1;
                else
                    to[j]=j;
            for(int j=1;j<=n;j++)
                vis[j]=0;
            int sum=0;
            for(int j=1;j<=n;j++)
            {
                if(vis[j])
                    continue;
                int x=to[j],tot=1;
                while(x!=j)//E
                {
                    vis[x]=1;
                    x=to[x];
                    tot++;
                }
                vis[x]=1;
                sum+=tot-1;
            }
            if(sum<=m)
                ans.push_back(k);
        }        
        printf("%d ",ans.size());
        for(auto x:ans)
            printf("%d ",x);
        puts("");
    }
}