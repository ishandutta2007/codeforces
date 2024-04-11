#include<bits/stdc++.h>
#define maxn 1203500

using namespace std;
typedef long long ll;
ll ans,n,sz[maxn],t,s,p,pre[maxn];
vector <int> h[maxn];

void dfs(int fa,int u)
{
    sz[u]=1; pre[u]=fa;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i];
        if (v==fa) continue;
        dfs(u,v); sz[u]+=sz[v];
    }
}

int main()
{
    cin>>n>>s>>t;
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    dfs(0,s);
    int tmp=t;
    while (pre[tmp]!=s) tmp=pre[tmp];
    ans=(n-sz[tmp])*sz[t];
    cout << n*(n-1)-ans << endl;
    return 0;
}