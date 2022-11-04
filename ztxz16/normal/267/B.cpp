//by hyy
//on 2010.12.5

#include <stdio.h>
#include <stdlib.h>

int n,i,j,k;
int map[16][16],du[16],x[160],y[160],ansx[160],ansy[160];

void dfs(int v);

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d %d",&x[i],&y[i]),map[x[i]][y[i]]++,map[y[i]][x[i]]++,du[x[i]]++,du[y[i]]++;
    for(i=0;i<=6;i++)
    if (du[i]>0) j=i;
    for(i=0;i<=6;i++)
    if ((du[i]&1)==1) j=i,k++;
    if (k==1 || k>2)
    {
             printf("No solution\n");
             return 0;
    }
    k=0;
    dfs(j);
    if (k<n)
    {
            printf("No solution\n");
            return 0;
    }
    for(i=k;i>=1;i--)
    {
       for(j=1;j<=n;j++)
       if (ansx[i]==x[j] && ansy[i]==y[j])
       {
          printf("%d +\n",j);
          x[j]=7;
          break;
       }
       else if (ansx[i]==y[j] && ansy[i]==x[j])
       {
            printf("%d -\n",j);
            x[j]=7;
            break;
       }
    }
    return 0;
}

void dfs(int v)
{
     int x;
     for(x=0;x<=6;x++)
     if (map[v][x]>0)
     {
        map[v][x]--; map[x][v]--;
        dfs(x);
        k++;
        ansx[k]=v; ansy[k]=x;
     }
     return;
}