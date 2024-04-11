#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

struct DJS
{
    int p[N],sz[N];
    void init(int n)
    {
        for (int i=0;n>=i;i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int x)
    {
        return p[x]==x?x:p[x]=Find(p[x]);
    }
    void Union(int x,int y)
    {
        x = Find(x);
        y = Find(y);
        if (x==y) return;
        if (sz[x] > sz[y]) swap(x,y);
        p[x]=y;
        sz[y] += sz[x];
    }
} djs;

vector<int> G[N];
int vis1[N];
int vis2[N],vis_id = 880301;
int deg[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    vector<int> v;
    djs.init(n);
    for (int i=1;n>=i;i++)
    {
        v.push_back(i);
    }
    sort(v.begin(),v.end(),[](const int &a,const int &b)
         {
             return deg[a] < deg[b];
         });
    bool first = true;
    for (int i:v)
    {
        ++vis_id;
        if (vis1[i]) continue;
        for (int j:G[i])
        {
            vis2[j] = vis_id;
        }
        for (int j=1;n>=j;j++)
        {
            if (vis2[j] != vis_id)
            {
                djs.Union(i,j);
                if (first) vis1[j] = true;
            }
        }
        first = false;
    }
    vector<int> ans;
    for (int i=1;n>=i;i++)
    {
        if (djs.Find(i) == i) ans.push_back(djs.sz[i]);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for (int i=0;(int)ans.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}