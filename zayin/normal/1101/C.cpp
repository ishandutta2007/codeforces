#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
int L[maxn],R[maxn];
int pos[maxn];

bool cmp(int i,int j)
{
    return L[i]<L[j];
}

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&L[i],&R[i]),pos[i]=i;
    sort(pos+1,pos+n+1,cmp);
}

int ans[maxn];

void solve()
{
    int p,last=R[pos[1]];
    for (p=2;p<=n;++p)
        if (L[pos[p]]>last)
            break;
        else
            last=max(last,R[pos[p]]);
    if (p>n)
        puts("-1");
    else
    {
        for (int i=1;i<p;++i)
            ans[pos[i]]=1;
        for (int i=p;i<=n;++i)
            ans[pos[i]]=2;
        for (int i=1;i<=n;++i)
            printf("%d ",ans[i]);
        putchar('\n');
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        solve();
    }
    return 0;
}