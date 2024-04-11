#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

int a[N];

bool chk(int w)
{
    vector<int>p;
    for(int i=1;i<=n;i++)
        if(a[i]!=w)
            p.push_back(a[i]);
    for(int i=0;i<p.size();i++)
        if(p[i]!=p[p.size()-i-1])
            return 0;
    return 1;
}

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[n-i+1])
                continue;
            ans=0;
            ans|=chk(a[i]);
            ans|=chk(a[n-i+1]);
            break;
        }
        puts(ans?"YES":"NO");
    }
}