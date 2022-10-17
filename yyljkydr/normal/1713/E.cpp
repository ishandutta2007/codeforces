#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int n,a[N][N];

int fa[N*2];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<n*2;i++)
            fa[i]=i;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int x=a[i][j],y=a[j][i];
                if(x==y)
                    continue;
                int fx[2]={find(i),find(i+n)};
                int fy[2]={find(j),find(j+n)};
                if(fx[0]==fy[0]||fx[1]==fy[0])
                    continue;
                if(x<y)
                    fa[fx[0]]=fy[0],fa[fx[1]]=fy[1];
                else
                    fa[fx[0]]=fy[1],fa[fx[1]]=fy[0];
            }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int fx[2]={find(i),find(i+n)};
                int fy[2]={find(j),find(j+n)};
                if(fx[0]==fy[1])
                {
                    swap(a[i][j],a[j][i]);
                }
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                printf("%d%c",a[i][j]," \n"[j+1==n]);
    }
}