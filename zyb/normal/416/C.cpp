#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int w;
    int v;
    int id;
} a[1005];
int m;
struct node1
{
    int k;
    int id;
}b[1005];
int cmp(node b,node c)
{
    if(b.v==c.v)
        return b.w<c.w;
    return b.v>c.v;
}
int cmp1(node1 b,node1 c)
{
    return b.k<c.k;
}
int find(int p)
{
    for(int i=1;i<=m;i++)
    {
        if(b[i].k!=-1 && b[i].k>=p)
        {
            b[i].k=-1;
            return b[i].id;
        }
    }
    return 0;
}
int main()
{
    int n;
    memset(b,-1,sizeof(b));
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].w,&a[i].v);
        a[i].id=i;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i].k);
        b[i].id=i;
    }
    sort(b+1,b+m+1,cmp1);
    sort(a+1,a+n+1,cmp);
    node1 c[1005];
    int j=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=find(a[i].w);
        if(tmp)
        {
            ans+=a[i].v;
            c[j].k=a[i].id;
            c[j].id=tmp;
            j++;
        }
    }
    printf("%d %d\n",j-1,ans);
    for(int i=1;i<j;i++)
    {
        printf("%d %d\n",c[i].k,c[i].id);
    }
    return 0;
}