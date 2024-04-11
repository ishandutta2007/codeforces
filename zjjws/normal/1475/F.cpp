#include <stdio.h>
#define LL long long
using namespace std;
const int Rea=1e5+3;
struct Rin
{
    char c;
    inline char gc()
    {
        static char rea[Rea];
        static char *head,*tail;
        return head==tail&&(tail=(head=rea)+fread(rea,1,Rea,stdin),head==tail)?EOF:*head++;
    }
    inline Rin&operator >>(int &x)
    {
        x=0;
        bool tag=false;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(tag)x=-x;
        return *this;
    }
    inline Rin&operator >>(bool &x){for(c=gc();c!='0'&&c!='1';c=gc());x=(c=='1');return *this;}
}rin;

const int N=1e3+3;
int n,m;
bool A[N][N];
inline void work()
{
    rin>>n;m=n;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)rin>>A[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){bool now;rin>>now;A[i][j]^=now;}
    // for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)if((i==1)+(i==n)+(j==1)+(j==m)==2)printf("?");else printf("%d",A[i][j]);printf("\n");}
    //
    //
    // $n$  $\cdots$
    bool tag=false;
    for(int i=2;i<=n;i++)
    {
        if(A[i][1]==A[1][1]){for(int j=1;j<=m;j++)if(A[i][j]!=A[1][j]){tag=true;break;}}
        else {for(int j=1;j<=m;j++)if(A[i][j]==A[1][j]){tag=true;break;}}
    }
    if(!tag)puts("Yes");
    else puts("No");
    return;
}
int main()
{
    int T;for(rin>>T;T;T--)work();
    return 0;
}