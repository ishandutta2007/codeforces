#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int T,n,a[N];

ll s[2];

void ins(int x,int c)
{
    s[x&1]+=c*(a[x]-a[x-1]);
}

int pok[N],sok[N];

ll g[N],smn[2][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[n+1]=0;
        s[0]=s[1]=0;
        for(int i=1;i<=n+1;i++)
            s[i&1]+=a[i]-a[i-1];
        g[0]=0;
        for(int i=1;i<=n;i++)
            g[i]=a[i]-g[i-1];
        pok[0]=1;
        for(int i=1;i<=n;i++)
            pok[i]=(g[i]>=0)&pok[i-1];
        smn[0][n+1]=smn[1][n+1]=1e18;
        for(int i=n;i>=1;i--)
            for(int j=0;j<2;j++)
                smn[j][i]=min(smn[j][i+1],j==(i&1)?g[i]:(ll)1e18);  
        if(!s[0]&&!s[1]&&pok[n])
        {
            puts("YES");
        }
        else
        {
            bool ok=0;
            for(int i=1;i<n;i++)
            {
                ll ls[2]={s[0],s[1]};
                ins(i,-1);
                ins(i+1,-1);
                ins(i+2,-1);
                swap(a[i],a[i+1]);
                ins(i,1);
                ins(i+1,1);
                ins(i+2,1);
                ok|=!s[0]&&!s[1]&&pok[i-1]&&a[i]>=g[i-1]&&(smn[(i+1)&1][i+1]-a[i]*2+a[i+1]*2>=0)&&(smn[i&1][i+2]-a[i+1]*2+a[i]*2>=0);
                swap(a[i],a[i+1]);
                s[0]=ls[0],s[1]=ls[1];
            }
            puts(ok?"YES":"NO");
        }
    }
}