#include <stdio.h>
#define LL long long
using namespace std;
const int N=1e2+3;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
inline double min(double x,double y){return x<y?x:y;}
inline double max(double x,double y){return x>y?x:y;}

int n;

double f[2][N][N*N];
int main()
{
    int i,j,k;
    n=rin();
    int vs=0;
    for(i=0;i<N;i++)for(j=N*N-1;j>=0;j--)f[0][i][j]=f[1][i][j]=-0x3f3f3f3f;
    f[0][0][0]=0;
    for(i=1;i<=n;i++)
    {
        bool now=(i&1);
        int v=rin();
        double w=rin();
        double w_=w/2;
        vs+=v;
        for(j=0;j<=i;j++)
        {
            for(k=0;k<=vs;k++)
            {
                f[now][j][k]=f[!now][j][k]+w_;
                if(k>=v&&j)f[now][j][k]=max(f[now][j][k],f[!now][j-1][k-v]+w);
                // printf("f[%d][%d][%d]:%.2lf\n",i,j,k,f[now][j][k]);
            }
        }
    }
    bool now=n&1;
    for(i=1;i<=n;i++)
    {
        double ans=0;
        for(k=0;k<=vs;k++)ans=max(ans,min(k,f[now][i][k]));
        printf("%.10lf ",ans);
    }
    printf("\n");
    return 0;
}