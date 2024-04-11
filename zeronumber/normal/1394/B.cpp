#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+5;
int n,m,k,id[10][10],f[50],a[10],ans;
bool ban[50][50];
bool zban[50];
vector<pi> h[maxn];
vector<int> g[maxn];
bool cmp(pi u,pi v){return u.S<v.S;}
void dfs(int x){
    if (x==k+1) {
        ++ans;return;
    }
    for (int i=1;i<=x;i++){
        a[x]=id[x][i];
        bool flag=zban[a[x]];
        for (int j=1;j<x;j++) flag|=ban[a[j]][a[x]];
        if (!flag) dfs(x+1);
    }
}
int main(){
    cin >> n >> m >> k;
    int cc=0;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=i;j++)
            id[i][j]=++cc;
    for (int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        h[u].pb((pi){v,w});
    }
    for (int i=1;i<=n;i++) sort(h[i].begin(),h[i].end(),cmp);
    for (int i=1;i<=n;i++)
    for (int j=0;j<h[i].size();j++){
        int v=h[i][j].F;
        g[v].pb(id[h[i].size()][j+1]);
    }
    for (int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        for (auto x:g[i]) f[x]++;
        //for (auto x:g[i])cout<<x<<' ';cout<<"H"<<endl;
        for (int j=1;j<=cc;j++) if (f[j])
            for (int k=j+1;k<=cc;k++) if (f[k])
                ban[j][k]=ban[k][j]=1;
        for (int j=1;j<=cc;j++) if (f[j]>1) zban[j]=1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}