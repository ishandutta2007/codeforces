#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL x=0;
    char c;
    bool tag=false;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-'){c=getchar();tag=true;break;}
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^'0');
    if(tag)x=-x;
    return x;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
string a;
bool x[2][N];
bool y[2][N];
inline void work()
{
    int n;
    cin>>a;n=a.length();
    for(int i=0;i<=n+1;i++)x[0][i]=x[1][i]=y[0][i]=y[1][i]=false;
    x[0][0]=x[1][0]=y[1][n+1]=y[0][n+1]=true;
    for(int i=1;i<=n;i++)
    {
        if(a[i-1]=='0')x[0][i]=max(x[0][i-1],x[1][i-1]);
        x[1][i]=x[0][i-1];
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i-1]=='1')y[0][i]=max(y[0][i+1],y[1][i+1]);
        y[1][i]=y[0][i+1];
    }
    for(int i=1;i<=n;i++)
    {
        if(x[0][i]&&(y[1][i+1]||y[0][i+1])){puts("YES");return;}
        if(x[1][i]&&y[0][i+1]){puts("YES");return;}
    }
    puts("NO");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 