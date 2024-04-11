#include <map>
#include <set>
#include <cmath>
#include <queue>
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

const int N=2e5+3;
int n,m;
int cutt[N];
int val[N];

int x[2][N];
int y[N];
map<int,bool>qy[N];
inline void work()
{
    n=rin();m=rin();
    for(int i=1;i<=n;i++)cutt[i]=val[i]=0;
    for(int i=1;i<=m;i++)y[i]=0,qy[i].clear();
    for(int i=1;i<=m;i++)
    {
        int ed=rin();
        for(int k=1;k<=ed;k++)
        {
            int v=rin();
            if(k==1)x[0][i]=v;
            if(k==2)x[1][i]=v;
            if(ed==1)cutt[v]++,y[i]=v;
            val[v]++;qy[i][v]=true;
        }
    }
    bool tag=true;
    int maxl=0,st;
    for(int i=1;i<=n;i++)if(cutt[i]>(m+1>>1)){tag=false;break;}else if(val[i]>maxl)maxl=val[i],st=i;
    if(!tag){puts("NO");return;}
    puts("YES");
    int now=cutt[st];
    for(int i=1;i<=m;i++)
    {
        if(y[i]==st){printf("%d ",st);continue;}
        if(now<(m+1>>1)&&qy[i][st]){printf("%d ",st);now++;continue;}
        if(x[0][i]!=st){printf("%d ",x[0][i]);continue;}
        printf("%d ",x[1][i]);
    }
    printf("\n");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 