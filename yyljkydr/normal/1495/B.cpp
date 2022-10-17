#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],f[N],g[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        f[i]=a[i]>a[i-1]?f[i-1]+1:1;
    for(int i=n;i>=1;i--)
        g[i]=a[i]>a[i+1]?g[i+1]+1:1;
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++)
        if(max(f[i],g[i])>ans)
            ans=max(f[i],g[i]),cnt=1;
        else if(max(f[i],g[i])==ans)
            cnt++;
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        int px=max(f[i],g[i]);
        if(px<ans)
            continue;
        if(px==ans&&cnt>1)
            continue;
        if(f[i]==g[i]&&(f[i]&1))
            tot++;
    }
    printf("%d\n",tot);
}