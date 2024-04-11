#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=1e9+7;

int T;

int n,k,a[N];

int C[1001][1001];

int main()
{
    C[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=1000;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int x=a[n-k+1];
        int s=0,t=0;
        for(int i=1;i<=n;i++)
            s+=a[i]==x;
        for(int i=n-k+1;i<=n;i++)
            t+=a[i]==x;
        printf("%d\n",C[s][t]);
    }
}