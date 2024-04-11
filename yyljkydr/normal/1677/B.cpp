#include<bits/stdc++.h>
using namespace std;

const int N=2e6+1e3+7;

int T,n,m;

char s[N];

int a[N],c[N],d[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s+n*m);
        for(int i=0;i<=n*m+1;i++)
            c[i]=d[i]=0;
        for(int i=1;i<n*m;i++)
            s[i]='0';
        for(int i=1;i<n*m*2;i++)
            a[i]=a[i-1]+s[i]-'0';
        for(int l=1;l+m-1<n*m*2;l++)
        {
            int r=l+m-1;
            if(a[r]-a[l-1])
                continue;
            int L=r-n*m+1;
            int R=r-m+1;
            if(L<=0)
            {
                int k=abs(L)+1;
                L+=(k+m-1)/m*m;
            }
            if(L>R)
                continue;
            c[L]++;
            if(R+m<=n*m)
                c[R+m]--;
        }
        for(int i=m;i<=n*m;i++)
            c[i]+=c[i-m];
        for(int i=1;i<n*m*2;i++)
        {
            a[i]=s[i]-'0';
            if(i>=n)
                a[i]+=a[i-m];
        }
        for(int i=(n-1)*m+1;i<n*m*2;i++)
        {
            int j=i-n*m;
            int s=a[i]-(j<0?0:a[j]);
            if(s)
                continue;
            int L=max(i-(n*m)+1,1);
            int R=i-(n*m-m+1)+1;
            d[L]++;
            if(R+1<=n*m)
                d[R+1]--;
        }
        for(int i=1;i<=n*m;i++)
            d[i]+=d[i-1];
        for(int i=1;i<=n*m;i++)
            printf("%d%c",n+m-c[i]-d[i]," \n"[i==n*m]);
    }
}