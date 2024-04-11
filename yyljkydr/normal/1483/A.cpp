#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m,cho[N],cnt[N];

vector<int>ava[N],to[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            to[i].clear();
        for(int i=1;i<=m;i++)
            ava[i].clear();
        for(int i=1;i<=m;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=1,x;j<=k;j++)
            {
                scanf("%d",&x);
                ava[i].push_back(x);
                if(j==1)
                    to[x].push_back(i),cho[i]=x;
            }
        }
        int lim=(m+1)>>1;
        for(int i=1;i<=n;i++)
        {
            if(to[i].size()>lim)
            {
                int y=to[i].size();
                for(auto x:to[i])
                {
                    if(ava[x].size()==1)
                        continue;
                    cho[x]=ava[x][1];
                    y--;
                    if(y<=lim)
                        break;
                }
                break;
            }
        }
        for(int i=1;i<=n;i++)
            cnt[i]=0;
        for(int i=1;i<=m;i++)
            cnt[cho[i]]++;
        int ok=1;
        for(int i=1;i<=n;i++)
            if(cnt[i]>lim)
                ok=0;
        if(!ok)
            puts("NO");
        else
        {
            puts("YES");
            for(int j=1;j<=m;j++)
                printf("%d%c",cho[j]," \n"[j==m]);
        }
    }
}