#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m;

int a[N],b[N],c[N],ans[N],pos[N];

vector<int>v[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            v[i].clear(),pos[i]=-1;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&c[i]);
        for(int i=1;i<=n;i++)
            if(a[i]!=b[i])
                v[b[i]].push_back(i);
            else
                pos[a[i]]=i;
        int last=-1;
        int ok=1;
        for(int i=m;i>=1;i--)
            if(v[c[i]].size())
                ans[i]=v[c[i]].back(),last=ans[i],v[c[i]].pop_back();
            else
            {
                if(last==-1)
                {
                    if(pos[c[m]]==-1)
                        ok=0;
                    else
                        ans[i]=pos[c[m]];
                }
                else
                    ans[i]=last;
            }
        for(int i=1;i<=n;i++)
            if(v[i].size())
                ok=0;
        if(!ok)
            puts("NO");
        else
        {
            puts("YES");
            for(int i=1;i<=m;i++)
                printf("%d%c",ans[i]," \n"[i==m]);
        }
    }
}