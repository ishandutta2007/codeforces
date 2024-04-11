#include <vector>
#include <stdio.h>
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

const int N=2e5+3;

int n,m,k;
vector<int>nxt[N];
bool tag[N];
int ans[N<<1];
int cutt;
inline void dfs(int x)
{
    tag[x]=true;
    for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)
    {
        if(tag[*i])continue;
        ans[++cutt]=(*i);
        dfs(*i);
        ans[++cutt]=x;
    }
    return;
}
int main()
{
    n=rin();m=rin();k=rin();
    for(int i=1;i<=m;i++){int x=rin(),y=rin();nxt[x].push_back(y);nxt[y].push_back(x);}
    ans[++cutt]=1;dfs(1);
    int lens=((n<<1)-1)/k+1;
    for(int i=1,j=0;i<=k;i++)
    {
        int L=min(lens,cutt-j);
        if(L==0){printf("1 1\n");continue;}
        printf("%d ",L);
        for(;L;L--)printf("%d ",ans[++j]);printf("\n");
    }
    return 0;
}

//vjudge 