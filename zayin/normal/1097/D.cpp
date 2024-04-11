#include<bits/stdc++.h>
#define maxn 150
#define modu 1000000007
using namespace std;
typedef long long LL;

LL mk=1,N,p[maxn],k[maxn];

struct Matrix
{
    LL A[maxn][maxn];

    Matrix()    {
        memset(A,0,sizeof(A));
    }

    Matrix operator * (const Matrix & M)    const   {
        Matrix ans;
        for (int i=0;i<=mk;++i)
            for (int j=0;j<=mk;++j)
                for (int k=0;k<=mk;++k)
                    ans.A[i][j]=(ans.A[i][j]+A[i][k]*M.A[k][j])%modu;
        return ans;
    }

} Ans,A;

int m;
LL n;

LL dp[maxn][maxn],f[maxn];

void fac(LL n)
{
    for (LL i=2;i*i<=n;++i)
    {
        if (n%i)    continue;
        for (p[++N]=i;n%i==0;n/=i) 
            ++k[N];
        mk=max(mk,k[N]);
    }
    if (n==1)   return ;
    ++N;
    p[N]=n,k[N]=1;
}

LL pw(LL a,LL k)    {
    LL ans=1;
    for (;k;k>>=1)  {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int main()
{
    scanf("%lld%d",&n,&m);
    fac(n);

    for (int i=0;i<=mk;++i)
        for (int j=i;j<=mk;++j)
            A.A[i][j]=pw(j+1,modu-2);
    
    for (int i=0;i<=mk;++i) Ans.A[i][i]=1;
    for (;m;m>>=1)
    {
        if (m&1)
            Ans=Ans*A;
        A=A*A;
    }

    // for (int i=0;i<=mk;++i)
    // {
    //     for (int j=0;j<=mk;++j)
    //         cout<<Ans.A[i][j]<<" ";
    //     cout<<endl;
    // }

    LL ans=1;
    for (int i=1;i<=N;++i)
    {
        LL t=0;
        for (int j=0;j<=k[i];++j)
            t=(t+pw(p[i],j)*Ans.A[j][k[i]])%modu;
        ans=ans*t%modu;
        // cout<<i<<" "<<t<<" "<<m-1<<" "<<k[i]+m-1<<endl;
        // cout<<endl;
    }

    printf("%lld\n",ans);
    return 0;
}