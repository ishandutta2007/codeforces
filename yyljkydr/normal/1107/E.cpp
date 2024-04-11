#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e2+1e1+7;

int n,a[N];

int f[N][N][N][2];

char s[N];

signed main()
{
    scanf("%lld",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        for(int j=1;j<i;j++)
            a[i]=max(a[i],a[j]+a[i-j]);
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i][0][0]=f[i][i][0][1]=a[1];
        f[i][i][1][(s[i]-'0')^1]=-1e18;
    }
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            for(int k=0;k<=len;k++)
                f[i][j][k][0]=f[i][j][k][1]=-1e18;
            for(int x=i;x<j;x++)
                for(int p=0;p<=x-i+1;p++)
                    for(int q=0;q<=j-x;q++)
                    {
                        f[i][j][p+q][0]=max(f[i][j][p+q][0],f[i][x][p][0]+f[x+1][j][q][0]);
                        f[i][j][p+q][1]=max(f[i][j][p+q][1],f[i][x][p][1]+f[x+1][j][q][1]);
                        // f[i][j][p][0]=max(f[i][j][p][0],f[i][x][p][0]+f[x+1][j][q][1]+a[q]);
                        // f[i][j][q][0]=max(f[i][j][q][0],f[i][x][p][1]+f[x+1][j][q][0]+a[p]);
                        // f[i][j][p][1]=max(f[i][j][p][1],f[i][x][p][1]+f[x+1][j][q][0]+a[q]);
                        // f[i][j][q][1]=max(f[i][j][q][1],f[i][x][p][0]+f[x+1][j][q][1]+a[p]);
                    }
            for(int k=0;k<=len;k++)
            {
                f[i][j][0][0]=max(f[i][j][0][0],f[i][j][k][0]+a[k]);
                f[i][j][0][0]=max(f[i][j][0][0],f[i][j][k][1]+a[k]);
                f[i][j][0][1]=max(f[i][j][0][1],f[i][j][k][0]+a[k]);
                f[i][j][0][1]=max(f[i][j][0][1],f[i][j][k][1]+a[k]);
            }
        }
    printf("%lld\n",f[1][n][0][0]);
}