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
int n,m;
vector<int>a[N];
vector<int>b[N];

vector<int>c;
vector<int>d;
int now[N];
int lx,ly;
bool tag;
inline bool check()
{
    if(!tag)d.clear();
    for(int i=2;i<=n;i++)
    {
        int cutt=0;
        for(int j=1;j<=m;j++)if(a[i][j]!=now[j])cutt++;
        if(cutt>2)
        {
            if(!tag){lx=i;for(int j=1;j<=m;j++)if(a[i][j]!=now[j])d.push_back(j);}
            return false;
        }
    }
    puts("Yes");
    for(int i=1;i<=m;i++)printf("%d ",now[i]);printf("\n");
    return true;
}
inline void work()
{
    n=rin();m=rin();
    for(int i=1;i<=n;i++){a[i].push_back(0);for(int j=1;j<=m;j++){int x=rin();a[i].push_back(x);}}
    int maxl=0;
    int st,ed;
    for(int i=2;i<=n;i++)
    {
        int cutt=0;
        for(int j=1;j<=m;j++)if(a[i][j]!=a[1][j])cutt++;
        if(cutt>4){puts("NO");return;}
        if(cutt<=2)continue;
        maxl=max(maxl,cutt);
        if(cutt==4&&c.empty()){for(int j=1;j<=m;j++)if(a[i][j]!=a[1][j])c.push_back(j);st=i;}
        if(cutt==3)ed=i;
    }
    if(!maxl){puts("Yes");for(int i=1;i<=m;i++)printf("%d ",a[1][i]);puts("");return;}
    for(int i=1;i<=m;i++)now[i]=a[1][i];
    if(maxl==4)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                now[c[i]]=a[st][c[i]];now[c[j]]=a[st][c[j]];
                if(check())return;
                now[c[i]]=a[1][c[i]];now[c[j]]=a[1][c[j]];
            }
        }
    }
    if(maxl==3)
    {
        for(int i=1;i<=m;i++)if(a[1][i]!=a[ed][i])c.push_back(i);
        for(int i=0;i<3;i++)
        {
            now[c[i]]=a[ed][c[i]];
            tag=false;if(check())return;tag=true;
            for(vector<int>::iterator j=d.begin();j!=d.end();j++)
            {
                if((*j)!=c[0]&&(*j)!=c[1]&&(*j)!=c[2])continue;
                int lst=now[*j];now[*j]=a[lx][*j];
                if(check())return;
                now[*j]=lst;
            }
            now[c[i]]=a[1][c[i]];
        }
    }
    puts("No");
    return;
}
int main()
{
    work();
    return 0;
}