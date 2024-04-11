#include<bits/stdc++.h>
#define maxn 2000050
#define g 3
#define modu 998244353
using namespace std;
typedef long long LL;

LL pw(LL a,LL k)
{
    LL ans=1;
    for (;k;k>>=1)
    {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

struct NTT
{
    int N;
    LL I,w[maxn],rev[maxn];

    void init(int n)
    {
        for (N=1;N<=n;N<<=1) ;
        I=pw(N,modu-2);

        rev[0]=0,rev[1]=N>>1;
        for (int i=2;i<N;++i)
            rev[i]=rev[i>>1]>>1|rev[i&1];
        
        w[0]=1,w[1]=pw(g,(modu-1)/N);
        for (int i=2;i<N;++i)
            w[i]=w[i-1]*w[1]%modu;
    }

    void DFT(LL *A)
    {
        for (int i=0;i<N;++i)
            if (i<rev[i])
                swap(A[i],A[rev[i]]);
        for (int len=2;len<=N;len<<=1)
        {
            int m=len>>1;
            for (LL *p=A;p!=A+N;p+=len)
                for (int i=0;i<m;++i)
                {
                    LL u=p[i],v=p[i+m]*w[N/len*i]%modu;
                    p[i]=(u+v)%modu;
                    p[i+m]=(u-v+modu)%modu;
                }
        }
    }

    void IDFT(LL *A)
    {
        DFT(A);
        reverse(A+1,A+N);
        for (int i=0;i<N;++i)
            A[i]=A[i]*I%modu;
    }

}   T;

int n,m;
LL A[maxn],Ans[maxn]={1};

void init()
{
    scanf("%d%d",&n,&m);
    while (m--)
    {
        int x;
        scanf("%d",&x);
        A[x]=1;
    }
}

void solve()
{

    T.init(9*n/2);
    T.DFT(A);
    T.DFT(Ans);

    for (n>>=1;n;n>>=1)
    {
        if (n&1)
            for (int i=0;i<T.N;++i)
                Ans[i]=Ans[i]*A[i]%modu;
        for (int i=0;i<T.N;++i)
            A[i]=A[i]*A[i]%modu;
    }
    T.IDFT(Ans);


    // for (int i=0;i<T.N;++i)
    //     if (Ans[i])
    //     cout<<i<<" "<<Ans[i]<<endl;
    // cout<<"???"<<endl;
    LL ans=0;
    for (int i=0;i<T.N;++i)
        ans=(ans+Ans[i]*Ans[i])%modu;
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}