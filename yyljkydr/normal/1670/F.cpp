#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e3+1e2+7,P=1e9+7;

int n,l,r,z;

int f[2][N*2][2],C[N][N];

int calc(int lst,int x,int y)
{
    if(x<y)
        return 0;
    if(x>y)
        return 1;
    return lst;
}

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

int solve(int x)
{
    int now=1,last=0;
    for(int i=0;i<n*2;i++)
        f[now][i][0]=f[now][i][1]=0;
    f[now][0][0]=1;
    for(int i=0;i<=61;i++)
    {
        int p=x>>i&1;
        int t=z>>i&1;
        swap(now,last);
        for(int i=0;i<n*2;i++)
            for(int j=0;j<2;j++)
                f[now][i][j]=0;
        for(int j=0;j<n*2;j++)
            for(int k=t;k<=n;k+=2)
                for(int s=0;s<2;s++)
                {
                    int ns=calc(s,((j>>1)+k)&1,p);
                    inc(f[now][(j>>1)+k][ns],1ll*f[last][j][s]*C[n][k]%P);
                }
    }
    return f[now][0][0];
}

signed main()
{
    scanf("%lld%lld%lld%lld",&n,&l,&r,&z);
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
    }
    printf("%lld\n",(solve(r)-solve(l-1)+P)%P);
}