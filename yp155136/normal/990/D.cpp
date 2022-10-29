#include <bits/stdc++.h>
using namespace std;

const int N = 1006;

int adj[N][N];

int main ()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    if (a>1 && b>1)
    {
        puts("NO");
        return 0;
    }
    if (a == 1 && b == 1)
    {
        if (n == 2 || n == 3)
        {
            puts("NO");
            return 0;
        }
        puts("YES");
        for (int i=1;n>=i;i++)
        {
            for (int j=1;n>=j;j++)
            {
                if (abs(i-j) == 1) printf("1");
                else printf("0");
            }
            puts("");
        }
        return 0;
    }
    puts("YES");
    int _ = max(a,b);
    for (int i=1;n>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            if (i == j) ;
            else if (i > j) adj[i][j] = adj[j][i];
            else
            {
                if (i < _ || j < _) adj[i][j] = 0;
                else adj[i][j] = 1;
            }
        }
    }
    if (a == 1)
    {
        for (int i=1;n>=i;i++)
        {
            for (int j=1;n>=j;j++)
            {
                if (i == j) continue;
                adj[i][j] = 1-adj[i][j];
            }
        }
    }
    for (int i=1;n>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            printf("%d",adj[i][j]);
        }
        puts("");
    }
}