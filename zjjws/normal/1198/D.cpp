#include <stdio.h>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline int gc(){char c=getchar();for(;c!='#'&&c!='.';c=getchar());return (c=='#');}
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}

const int N=53;

int n;
int val[N][N];
int f[N][N][N][N];
int main()
{
    n=rin();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)val[i][j]=val[i-1][j]+val[i][j-1]-val[i-1][j-1]+gc();
    // puts("El Psy Congroo");
    for(int X=1;X<=n;X++)for(int Y=1;Y<=n;Y++)
    {
        for(int xl=1;xl+X-1<=n;xl++)for(int yl=1;yl+Y-1<=n;yl++)
        {
            int xr=xl+X-1,yr=yl+Y-1;
            if(val[xr][yr]-val[xr][yl-1]-val[xl-1][yr]+val[xl-1][yl-1]==0)continue;
            f[xl][xr][yl][yr]=max(X,Y);
            for(int i=xl;i<xr;i++)f[xl][xr][yl][yr]=min(f[xl][xr][yl][yr],f[xl][i][yl][yr]+f[i+1][xr][yl][yr]);
            for(int i=yl;i<yr;i++)f[xl][xr][yl][yr]=min(f[xl][xr][yl][yr],f[xl][xr][yl][i]+f[xl][xr][i+1][yr]);
        }
    }
    printf("%d\n",f[1][n][1][n]);
    return 0;
}