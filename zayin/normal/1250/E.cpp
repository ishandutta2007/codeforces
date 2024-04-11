#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n;

int fa[maxn];
vector<int> G[maxn];

int dep[maxn];

int dfs1(int i)    {
    for (int j:G[i])    
        dep[i]=max(dep[i],dfs1(j));
    return ++dep[i];
}

vector<int> ans;

void dfs2(int i)    {
    int son=0;
    for (int j:G[i])
        if (dep[son]<dep[j])
            son=j;
    int last=son;
    for (int j:G[i])    {
        if (son==j) continue;
        // cout<<i<<":"<<j<<" "<<last<<endl;
        G[j].push_back(last);
        ans.push_back(last);
        dep[j]=dep[last]+1;
        last=j;
    }
    printf("%d ",i-1);
    if (last)
        dfs2(last);
}

int main()  {
    scanf("%d",&n);
    for (int i=2;i<=n;++i)   {
        scanf("%d",fa+i);
        G[++fa[i]].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    reverse(ans.begin(),ans.end());
    puts("");
    printf("%d\n",ans.size());
    for (int i:ans)
        printf("%d ",i-1);
    return 0;
}