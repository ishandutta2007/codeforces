#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int n,a[N],to[N];

void dfs(int x,int p)
{
    a[p]=x;
    if(x==1)
        return;
    for(int i=1;i<=n;i++)
        if(to[i]==p)
            dfs(x-1,i);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("? ");
        for(int j=1;j<=n;j++)
            printf("%d%c",1+(i==j)," \n"[j==n]);
        fflush(stdout);
        int p=-1;
        scanf("%d",&p);
        if(p!=i)
            to[i]=p;
    }
    for(int i=1;i<=n;i++)
    {
        printf("? ");
        for(int j=1;j<=n;j++)
            printf("%d%c",1+(i!=j)," \n"[j==n]);
        fflush(stdout);
        int p=-1;
        scanf("%d",&p);
        if(p!=i)
            to[p]=i;
    }
    for(int i=1;i<=n;i++)
        if(!to[i])
        {
            dfs(n,i);
            break;
        }
    printf("! ");
    for(int i=1;i<=n;i++)
        printf("%d%c",a[i]," \n"[i==n]);
    fflush(stdout);
}