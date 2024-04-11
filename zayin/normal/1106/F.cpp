#include<bits/stdc++.h>
#define maxn 105
#define g 3
#define P 998244352
#define modu 998244353
#define maxm 35005
using namespace std;
typedef long long LL;

int N,n,fn;

struct Matrix {
    LL A[maxn][maxn];
    Matrix(LL x=0)  {
        memset(A,0,sizeof(A));
        for (int i=0;i<maxn;++i)
            A[i][i]=x;
    }

    const LL* operator [] (const int& i) const {
        return A[i];
    }
    LL* operator [] (const int& i)  {
        return A[i];
    }
    Matrix operator * (const Matrix& M) const   {
        Matrix Ans;
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                for (int k=0;k<N;++k)
                    Ans[i][j]=(Ans[i][j]+A[i][k]*M[k][j])%P;
        return Ans;
    }

    void print()    {
        for (int i=0;i<N;++i)
        {
            for (int j=0;j<N;++j)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
} Ans(1),A;

LL exgcd(LL a,LL b,LL& x,LL& y)
{
    if (!b) return x=1,y=0,a;
    LL d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}

LL pw(LL a,LL k)    {
    LL ans=1;
    for (;k;k>>=1)
    {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

LL gk[maxm]={1};
map<LL,LL> Ig;

int main()
{
    scanf("%d",&N);
    for (int i=0;i<N-1;++i)
        A[i][i+1]=1;
    for (int i=N-1;~i;--i)
        scanf("%lld",&A[N-1][i]);
    
    scanf("%d%d",&n,&fn);
    for (--n;n;n>>=1)
    {
        if (n&1)
            Ans=Ans*A;
        A=A*A;
    }

    for (int i=1;i<maxm;++i)
        gk[i]=gk[i-1]*g%modu;
    for (int i=0;i<maxm;++i)
        Ig[gk[i]]=i,assert(pw(g,Ig[gk[i]])==gk[i]);

    LL b=gk[maxm-1],Im;
    for (LL t=1,i=0;i<maxm;++i,t=t*b%modu)
    {
        LL q=pw(t,modu-2)*fn%modu;
        if (!Ig.count(q))   continue;
        // cout<<i<<" "<<pw(g,Ig[q])<<" "<<q<<" "<<q*t%modu<<endl;
        Im=i*(maxm-1)+Ig[q];
        break;
    }

    assert(pw(g,Im)==fn);


    LL x,y,k=Ans[0][N-1],d=exgcd(k,P,x,y);
    if (Im%d)
        puts("-1");
    else
    {
        x=(x%P+P)%P;
        LL t=x*(Im/d)%(P/d);
        // cout<<k*x%P<<" "<<Im<<endl;
        printf("%lld\n",pw(g,t));
    }
    return 0;
}