#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int r[N];
int ans[N];
int p[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&r[i]);
        p[i] = i;
    }
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if (r[x] > r[y]) --ans[x];
        if (r[x] < r[y]) --ans[y];
    }
    sort(p+1,p+n+1,[](const int &a,const int &b)
     {
         return r[a] < r[b];
     });
    int ptr=0;
    for (int i=1;n>=i;i++)
    {
        while (r[ p[ptr] ] < r[ p[i] ]) ++ptr;
        ans[ p[i] ] += (ptr-1);
    }
    for (int i=1;n>=i;i++)
    {
        if (i != 1) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}