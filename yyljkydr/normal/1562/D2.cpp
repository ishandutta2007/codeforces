#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7,S=6e5;

int T,n,q;

char s[N];

int a[N],b[N];

vector<int>pos[N*4];

void solve(int l,int r)
{
    int s=a[r]+a[l-1];
    //find b[x] = s; in l,r
    int x=*lower_bound(pos[s+S].begin(),pos[s+S].end(),l);
    printf("%d\n",x);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        int f=1;
        for(int i=1;i<=n;i++)
        {
            a[i]=a[i-1]+f*(s[i]=='+'?1:-1);
            b[i]=a[i]+a[i-1];
            pos[b[i]+S].push_back(i);
            f*=-1;
        }
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int len=r-l+1;
            if(len&1)
            {
                puts("1");
                solve(l,r);
            }
            else
            {
                puts((a[r]-a[l-1])?"2":"0");
                if(a[r]-a[l-1])
                {
                    printf("%d ",l);
                    solve(l+1,r);
                }
            }
        }
        for(int i=1;i<=n;i++)
            pos[b[i]+S].clear();
    }
}