#include<cstdio>
using namespace std;
int ans[100010],b[100010],n,tot;

void dfs(int x)
{
    b[x]=1;
    if(!b[(x<<1)%n])dfs((x<<1)%n);
    if(!b[(x<<1|1)%n])dfs((x<<1|1)%n);
    ans[++tot]=x;
}

int main()
{
    scanf("%d",&n);
    if(n&1)
    {
        puts("-1");
        return 0;
    }
    dfs(0);
    for(int i=n;i;i--)
        printf("%d ",ans[i]);
    putchar('0');
}