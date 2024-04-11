#include<bits/stdc++.h>
using namespace std;

#define int long long

const int M=100001,P=1e9+7;

int T,n,f[M],ans[M],m;

int to(int t,int y,int x)
{
    if(t==1)
        return (x*100000+y+99999)/100000;
    else
        return (x*y+99999)/100000;
}

signed main()
{
    scanf("%lld%lld",&n,&m);
    f[0]=1;
    for(int i=1;i<=m;i++)
        f[i]=0,ans[i]=-1;
    for(int i=1;i<=n;i++)
    {
        int t,x,y;
        scanf("%lld%lld%lld",&t,&x,&y);
        for(int j=m;j>=0;j--)
            if(f[j])
            {
                int w=to(t,x,j);
                for(int k=1;w<=m&&!f[w]&&k<=y;k++,w=to(t,x,w))
                    f[w]=1,ans[w]=i;
            }
    }
    for(int i=1;i<=m;i++)
        printf("%lld%c",ans[i]," \n"[i==m]);
}