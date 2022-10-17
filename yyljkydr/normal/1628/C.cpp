#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T;

int n,a[N][N];

int ans,c[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]),c[i][j]=0;
        ans=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(!c[i-1][j])
                {
                    c[i-1][j]^=1;
                    c[i][j-1]^=1;
                    c[i][j+1]^=1;
                    c[i+1][j]^=1;
                    ans^=a[i][j];
                }
        }
        printf("%d\n",ans);
    }
}