#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7;

int n,m,f[N][N];

char a[N],b[N];

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",a+1,b+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                f[i][j]=f[i-1][j-1]+2;
            f[i][j]=max(f[i][j],max(f[i-1][j]-1,f[i][j-1]-1));
            ans=max(ans,f[i][j]);
        }
    printf("%d\n",ans);
}