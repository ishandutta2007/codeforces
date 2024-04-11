#include<bits/stdc++.h>
using namespace std;

const int N=5e2+1e1+7;

int n,a[N][N],K;

int u[N*N],d[N*N],l[N*N],r[N*N],s[N][N];

int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n*n;i++)
        u[i]=n+1,l[i]=n+1,d[i]=0,r[i]=0;
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(!d[a[i][j]])
                tot++;
            u[a[i][j]]=min(u[a[i][j]],i);
            d[a[i][j]]=max(d[a[i][j]],i);
            l[a[i][j]]=min(l[a[i][j]],j);
            r[a[i][j]]=max(r[a[i][j]],j);
        }
    if(tot<=K)
    {
        printf("%d\n",K-tot);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                s[j][k]=0;
        for(int j=1;j<=n*n;j++)
        {
            if(!d[j])
                continue;
            int D=u[j],R=l[j];
            int U=max(d[j]-i+1,1),L=max(r[j]-i+1,1);
            if(U<=D&&L<=R)
            {
                s[U][L]++;
                s[U][R+1]--;
                s[D+1][L]--;
                s[D+1][R+1]++;
            }
        }
        for(int j=1;j<=n-i+1;j++)
            for(int k=1;k<=n-i+1;k++)
            {
                s[j][k]=s[j-1][k]+s[j][k-1]+s[j][k]-s[j-1][k-1];
                if(tot-s[j][k]==K||tot-s[j][k]+1==K)
                {
                    puts("1");
                    return 0;
                }
            }
    }
    puts("2");
}