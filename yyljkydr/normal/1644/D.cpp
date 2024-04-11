#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=998244353;

int T,n,m,k,q;

int vx[N],vy[N],x[N],y[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&q);
        for(int i=1;i<=q;i++)
            scanf("%d%d",&x[i],&y[i]);
        int ans=1;
        int cx=0,cy=0;
        for(int i=q;i>=1;i--)
        {
            if(cx==n||cy==m)
                break;
            if(vx[x[i]]&&vy[y[i]])
                continue;
            cx+=vx[x[i]]^1;
            cy+=vy[y[i]]^1;
            vx[x[i]]=vy[y[i]]=1;
            ans=1ll*ans*k%P;
        }
        for(int i=1;i<=q;i++)
            vx[x[i]]=vy[y[i]]=0;
        printf("%d\n",ans);
    }
}