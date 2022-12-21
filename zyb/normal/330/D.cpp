#include<stdio.h>
using namespace std;
int i,j,k,l,s,m,n;
int a[1005][1005];
int dep[1000005],q[1000005],q1[1000005];
int ans,x,y;
int main()
{
    char c;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
        c=getchar();
        while ((c<'0'||c>'9')&&c!='E'&&c!='T'&&c!='S')
        c=getchar();
        if (c>='0'&&c<='9')
        a[i][j]=int(c)-48;
        if (c=='T')
        a[i][j]=-1;
        if (c=='E')
        {
            x=i;y=j;
        }
        if (c=='S')
        a[i][j]=10;
    }
    int l=0,r=1;
    q[1]=x;
    q1[1]=y;
    dep[1]=0;
    a[x][y]=-1;
    int temp=10000000;
    while (1)
    {
        int xx=q[++l],yy=q1[l],k=dep[l];
        if (k>=temp)
        break;
        if (a[xx-1][yy]!=-1&&xx-1>0)
        {
            q[++r]=xx-1;
            q1[r]=yy;
            dep[r]=k+1;
            if (a[xx-1][yy]==10)
            temp=dep[r];
            else
            if (a[xx-1][yy]>0)
            ans+=a[xx-1][yy];
            a[xx-1][yy]=-1;
        }
        if (a[xx+1][yy]!=-1&&xx+1<=n)
        {
            q[++r]=xx+1;
            q1[r]=yy;
            dep[r]=dep[l]+1;
            if (a[xx+1][yy]==10)
            temp=dep[r];
            else
            if (a[xx+1][yy]>0)
            ans+=a[xx+1][yy];
            a[xx+1][yy]=-1;
        }
        if (a[xx][yy-1]!=-1&&yy-1>0)
        {
            q[++r]=xx;
            q1[r]=yy-1;
            dep[r]=dep[l]+1;
            if (a[xx][yy-1]==10)
            temp=dep[r];
            else
            if (a[xx][yy-1]>0)
            ans+=a[xx][yy-1];
            a[xx][yy-1]=-1;
        }
        if (a[xx][yy+1]!=-1&&yy+1<=m)
        {
            q[++r]=xx;
            q1[r]=yy+1;
            dep[r]=dep[l]+1;
            if (a[xx][yy+1]==10)
            temp=dep[r];
            else
            if (a[xx][yy+1]>0)
            ans+=a[xx][yy+1];
            a[xx][yy+1]=-1;
        }
    }
    printf("%d\n",ans);
}