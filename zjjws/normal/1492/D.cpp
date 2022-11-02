#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
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
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
int a,b,k;
int x[N];
int y[N];
inline void work()
{
    b=rin();a=rin();k=rin();//b  0a  1  k  1
    a--;
    if(a==0)
    {
        if(k>0)puts("No");
        else
        {
            puts("Yes");
            for(int i=a+b+1;i>=1;i--)printf("%d",(i==(a+b+1)));printf("\n");
            for(int i=a+b+1;i>=1;i--)printf("%d",(i==(a+b+1)));printf("\n");
        }
        return;
    }
    if(b==0)
    {
        if(k>0)puts("No");
        else
        {
            puts("Yes");
            for(int i=a+b+1;i>=1;i--)printf("1");printf("\n");
            for(int i=a+b+1;i>=1;i--)printf("1");printf("\n");
        }
        return;
    }
    if(k>a+b-1){puts("No");return;}
    int st=k+1;
    int les=a-1;
    for(int i=a+b;i>1&&les;i--)if(i!=st)x[i]=y[i]=1,les--;
    x[st]=1;y[1]=1;
    x[a+b+1]=y[a+b+1]=1;
    puts("Yes");
    for(int i=a+b+1;i>=1;i--)printf("%d",x[i]);printf("\n");
    for(int i=a+b+1;i>=1;i--)printf("%d",y[i]);printf("\n");
    return;
}
//
int main()
{
    work();
    return 0;
}