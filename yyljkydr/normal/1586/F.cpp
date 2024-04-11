#include<bits/stdc++.h>
using namespace std;

const int N=2e3+7;

int n,k;

int ans[N][N];

int main()
{
    scanf("%d%d",&n,&k);
    int m=1,col=0;
    while(m<n)
    {
        ++col;
        int e=min(k,(n+m-1)/m);
        int lm=m;
        m*=e;
        for(int i=2;i<=e;i++)
            for(int j=1;j<=lm;j++)
                for(int k=j+1;k<=lm;k++)
                    ans[j+(i-1)*lm][k+(i-1)*lm]=ans[j][k];
        for(int i=1;i<=e;i++)
            for(int j=i+1;j<=e;j++)
                for(int p=1;p<=lm;p++)
                    for(int q=1;q<=lm;q++)
                        ans[p+(i-1)*lm][q+(j-1)*lm]=col;
    }
    printf("%d\n",col);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            printf("%d%c",ans[i][j]," \n"[i*j==n*n]);
    puts("");
}