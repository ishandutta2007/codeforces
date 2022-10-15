#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v[200200],ans[200200];
int color[200200],a[200200],b[200200],n,pat,p[200200],m,j;
void dfs(int x)
{
    int m=v[x].size(),i,curr=0;
    for (i=0; i<m; i++)
    {
        if (v[x][i]==1) continue;
        if (color[v[x][i]]!=0) continue;
        p[v[x][i]]=x;
        curr++;
        if (curr==color[x]) curr++;
        color[v[x][i]]=curr;
        dfs(v[x][i]);
    }
}
int main()
{
    int i;
    scanf("%d", &n);
    for (i=1; i<n; i++)
    {
        scanf("%d", a+i);
        scanf("%d", b+i);
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    dfs(1);
    for (i=1; i<=n; i++)
        pat=max(pat,color[i]);
    for (i=1; i<n; i++)
    {
        if (a[i]==p[b[i]]) ans[color[b[i]]].push_back(i);
        else ans[color[a[i]]].push_back(i);
    }
    printf("%d\n", pat);
    for (i=1; i<=pat; i++)
    {
        m=ans[i].size();
        printf("%d", m);
        for (j=0; j<m; j++)
            printf(" %d", ans[i][j]);
        printf("\n");
    }
    return 0;
}