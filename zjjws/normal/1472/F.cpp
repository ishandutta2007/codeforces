#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=2e5+3;
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
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}

int n,m;

struct gyq
{
    int x,y;
}a[N];
inline bool myru(gyq x,gyq y){return x.y<y.y;}
inline void work()
{
    n=rin();m=rin();
    for(int i=1;i<=m;i++)a[i].x=rin(),a[i].y=rin();
    sort(a+1,a+m+1,myru);
    int last=3;
    for(int i=1,j;i<=m;i=j)
    {
        for(j=i;j<=m&&a[j].y==a[i].y;j++);
        int tag=0;
        if(j==i+2)tag=3;else tag=a[i].x;
        if(last!=3)
        {
            if(tag==1||tag==2)
            {
                if((last==tag&&(a[i].y-a[i-1].y)%2==0)||(last!=tag&&(a[i].y-a[i-1].y)%2==1))
                {
                    puts("NO");
                    return;
                }
            }
            else
            {
                puts("NO");
                return;
            }
            last=3;
        }
        else last=tag;
    }
    if(last!=3)puts("NO");
    else puts("YES");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}