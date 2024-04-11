#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long a[2][2],temp[2][2],res[2][2];

long long solve(long long x,long long mod)
{
    a[0][0]=1;
    a[0][1]=1;
    a[1][0]=1;
    a[1][1]=0;
    res[0][0]=1;
    res[0][1]=0;
    res[1][0]=0;
    res[1][1]=1;
    while(x){
        if(x&1) {
            memset(temp,0,sizeof(temp));
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    for(int k=0;k<2;k++)
                        temp[i][j]=(temp[i][j]+res[i][k]*a[k][j])%mod;
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    res[i][j]=temp[i][j];
        }
        memset(temp,0,sizeof(temp));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    temp[i][j]=(temp[i][j]+a[i][k]*a[k][j])%mod;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=temp[i][j];
        x/=2;
    }
    return (res[0][1]+res[0][0])%mod;
}

long long power(long long x,long long y,long long mod)
{
    long long res=1LL;
    while(y) {
        if(y&1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return res;
}

int  main()
{
    long long n,k,mod,l;
    scanf("%I64d%I64d%I64d%I64d",&n,&k,&l,&mod);
    if(l==0) {
        if(k==0)
            printf("%I64d\n",1%mod);
        else
            printf("0\n");
        return 0;
    }
    long long x=solve(n,mod);
    long long y=((power(2LL,n,mod)-x)%mod+mod)%mod;
    long long res=1LL;
    for(int i=0;i<l;i++) {
        if(k%2==0)
            res=(res*x)%mod;
        else
            res=(res*y)%mod;
        k/=2;
    }
    if(k)
        res=0LL;
    printf("%I64d\n",res);
    return 0;
}