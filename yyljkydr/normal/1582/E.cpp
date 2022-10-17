#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int n,a[N];

ll s[N];

ll f[N][501];

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
        int k=1,ss=1;
        while(ss+k+1<=n)
            ss+=++k;
        f[n+1][0]=1e18;
        for(int i=1;i<=k;i++)
            f[n+1][i]=0;
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<=k;j++)
                f[i][j]=f[i+1][j];
            for(int j=1;j<=k;j++)
            {
                if(i+j-1>n)
                    break;
                if(s[i+j-1]-s[i-1]<f[i+j][j-1])
                    f[i][j]=max(f[i][j],(s[i+j-1]-s[i-1]));
            }
        }
        for(int i=k;i>=1;i--)
            if(f[1][i])
            {
                printf("%d\n",i);
                break;
            }
    }
}