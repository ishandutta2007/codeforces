#include<bits/stdc++.h>
#define eps 1E-5
#define P 490019
#define sq2(x)  (1LL*x*x%(P-1))
#define sq3(x)  (1LL*x*x*x%(P-1))
#define add(x,y)    (x=(x+y)%P)
using namespace std;
typedef long long LL;
typedef complex<double> comp;

const double pi=acos(-1);
namespace FFT
{
    static const int N=1024;
    int rev[N];
    comp w[N];

    void FFT_init()   {
        rev[0]=0,rev[1]=N>>1;
        for (int i=2;i<N;++i)
            rev[i]=rev[i>>1]>>1|rev[i&1];
            
        w[0]=comp(1,0),w[1]=comp(cos(2*pi/N),sin(2*pi/N));
        for (int i=2;i<N;++i)
            w[i]=w[i-1]*w[1];
    }

    void DFT(comp *A)   {
        for (int i=0;i<N;++i)
            if (i<rev[i])
                swap(A[i],A[rev[i]]);
        for (int len=2;len<=N;len<<=1) {
            int m=len>>1;
            for (comp *p=A;p!=A+N;p+=len)
                for (int i=0;i<m;++i) {
                    comp u=p[i],v=p[i+m]*w[N/len*i];
                    p[i]=u+v;
                    p[i+m]=u-v;
                }
        }
    }

    void IDFT(comp *A)  {
        DFT(A);
        reverse(A+1,A+N);
        for (int i=0;i<N;++i) A[i]/=N;
    }

    comp t[N];

    template<void (*T)(comp *)>
    void TD(comp A[N][N])   {
        for (int j=0;j<N;++j)   {
            for (int i=0;i<N;++i)   t[i]=A[i][j];
            T(t);
            for (int i=0;i<N;++i)   A[i][j]=t[i];
        }
        for (int i=0;i<N;++i)   T(A[i]);
    }
};
using namespace FFT;

const int P1=491,P2=499;
const int g1=2,g2=7;

int Log1[P1],Log2[P2];

int n,m,c;
LL a[P],b[P];

void init()
{
    scanf("%d%d%d",&n,&m,&c);
    for (int x,i=0;i<n;++i)   scanf("%d",&x),add(a[sq2(i)],x);
    for (int x,i=0;i<m;++i)   scanf("%d",&x),add(b[sq3(i)],x);
}

bool spc[P];
vector<int> sp;

int id[2][P1][P2];
comp Ma[2][N][N],Mb[2][N][N],Mc[2][N][N];

LL F[P];

void predo()
{
    for (int x=1,i=0;i<P1-1;++i)    Log1[x]=i,x=x*g1%P1;
    for (int x=1,i=0;i<P2-1;++i)    Log2[x]=i,x=x*g2%P2;
    for (int i=0;i<P-1;++i)
    {
        if (i%P1==0||i%P2==0)
            spc[i]=1,sp.push_back(i);
        else
        {
            int x=Log1[i%P1],y=Log2[i%P2];
            id[i&1][x][y]=i;
            Ma[i&1][x][y]+=a[i],Mb[i&1][x][y]+=b[i];
        }
    }

    LL cnt=0;
    for (int i=0;i<P-1;++i)
        if (a[i])
            for (int j:sp)
                if (b[j])
                add(F[1LL*i*j%(P-1)],a[i]*b[j]);
    for (int j=0;j<P-1;++j)
        if (b[j]&&!spc[j])
            for (int i:sp)
                if (a[i])
                add(F[1LL*i*j%(P-1)],a[i]*b[j]);
}


void solve()
{
    for (int i=0;i<P1-1;++i)
        for (int j=0;j<P2-1;++j)
            Ma[0][i][j]+=Ma[1][i][j],Mb[0][i][j]+=Mb[1][i][j];

    for (int c=0;c<=1;++c)
    {
        TD<DFT>(Ma[c]),TD<DFT>(Mb[c]);
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                Mc[c][i][j]=Ma[c][i][j]*Mb[c][i][j];
        TD<IDFT>(Mc[c]);
    }
    
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            Mc[0][i][j]-=Mc[1][i][j];
            
    for (int c=0;c<=1;++c)
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                if (Mc[c][i][j].real()>eps)
                    add(F[id[c][i%(P1-1)][j%(P2-1)]],(LL)(Mc[c][i][j].real()+0.5));

    LL ans=0;
    for (int i=0,pc=1;i<P-1;++i,pc=(LL)pc*c%P)
        if (F[i])
            add(ans,F[i]*pc);
    printf("%lld\n",ans);
}

int main()
{
    FFT_init();
    init();
    predo();
    // cout<<clock()<<endl;
    solve();
    // cout<<clock()<<endl;
    return 0;
}