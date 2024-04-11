#include<bits/stdc++.h>
using namespace std;
 
const int N=255+7,P=998244353;
 
int n,K;
 
int f[N][N],C[N][N];
 
int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1ll*ret*a%P;
        b>>=1;
        a=1ll*a*a%P;
    }
    return ret;
}
 
void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}
 
int main()
{
    scanf("%d%d",&n,&K);
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
    }
    f[0][0]=1;
    for(int i=1;i<=K;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<=j;k++)
                inc(f[i][j],1ll*f[i-1][k]*C[j][k]%P*qpow(K-i+1,j*(j-1)/2-k*(k-1)/2)%P);
    printf("%d\n",f[K][n-1]);
}