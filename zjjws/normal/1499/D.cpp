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

const int N=1e7+3;
bool pri[N<<1];
int tag[N<<1];
int v[N<<1];
int pw[33];
vector<int>prime;
inline void init()
{
    int ed=N<<1;
    for(int i=2;i<=ed;i++)
    {
        if(!pri[i])prime.push_back(i),tag[i]=1,v[i]=i;
        for(vector<int>::iterator j=prime.begin();j!=prime.end();j++)
        {
            int now=(*j)*i;if(now>ed)break;
            pri[now]=true;v[now]=*j;tag[now]=tag[i]+tag[*j]-(i%(*j)==0);if(i%(*j)==0)break;
        }
    }
    pw[0]=1;for(int i=1;i<=30;i++)pw[i]=pw[i-1]<<1;
    return;
}

int D[33];
int C[33];
int tail;
int ans=0;
int c,d;
inline void dfs(int x,int num)
{
    if(num>tail){if((x+d)%c==0)ans+=pw[tag[(x+d)/c]];return;}
    dfs(x,num+1);for(int i=1;i<=C[num];i++)x*=D[num],dfs(x,num+1);return;
}
inline void work()
{
    c=rin();d=rin();
    int x=rin();ans=0;for(tail=0;x!=1;){D[++tail]=v[x];for(C[tail]=0;x%D[tail]==0;x/=D[tail])C[tail]++;}
    dfs(1,1);printf("%d\n",ans);
    return;
}
int main()
{
    init();
    for(int T=rin();T;T--)work();
    return 0;
}