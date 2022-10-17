#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n,k;

int a[N];

vector<int>v[N];

int qry(int x)
{
    printf("? %d ",x);
    for(int i=1;i<=x;i++)
        printf("%d%c",i," \n"[i==x]);
    fflush(stdout);
    int w;
    scanf("%d",&w);
    return w;
}
char s[1111];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        // for(int i=1;i<=n;i++)
        //     scanf("%d",&a[i]);
        for(int i=1;i<=k;i++)
        {
            v[i].clear();
            int s=0;
            scanf("%d",&s);
            for(int j=1;j<=s;j++)
            {
                int x;
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        int mx=qry(n);
        int l=0,r=n;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(qry(mid)==mx)
                r=mid;
            else
                l=mid;
        }
        vector<int>ans(k+1);
        for(int i=1;i<=k;i++)
        {
            bool fd=0;
            for(auto x:v[i])
                if(x==r)
                    fd=1;
            if(!fd)
                ans[i]=mx;
            else
            {
                printf("? %d",n-v[i].size());
                set<int>ss;
                for(auto x:v[i])
                    ss.insert(x);
                for(int x=1;x<=n;x++)
                    if(!ss.count(x))
                    printf(" %d",x);
                puts("");
                fflush(stdout);
                scanf("%d",&ans[i]);
            }
        }
        printf("! ");
        for(int i=1;i<=k;i++)
            printf("%d%c",ans[i]," \n"[i==k]);
        fflush(stdout);
        scanf("%s",s);
    }
}