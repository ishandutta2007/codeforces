#include<bits/stdc++.h>
using namespace std;

multiset<int>G[101000];
int n, m, deg[101000];
vector<int>vec;

#define pii pair<int,int>
#define fi first
#define se second
vector<pii>ans;

void dfs(int x){
    while (G[x].size()){
        int y=*G[x].begin();
        G[x].erase(G[x].find(y));
        G[y].erase(G[y].find(x));
        dfs(y);
    }
    vec.push_back(x);
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        int x, y; scanf("%d%d",&x,&y);
        G[x].insert(y);
        G[y].insert(x);
        ++deg[x]; ++deg[y];
    }
    for (int i=1;i<=n;++i)
        if (deg[i]&1) vec.push_back(i);
    while (vec.size()){
        int x=vec.back(); vec.pop_back();
        int y=vec.back(); vec.pop_back();
        G[x].insert(y);
        G[y].insert(x);
    }
    dfs(1);
    for (int i=1;i<vec.size();++i)
        ans.push_back(i&1? (pii){vec[i-1],vec[i]}: (pii){vec[i],vec[i-1]});
    if (ans.size()&1) ans.push_back({1,1});
    cout<<ans.size()<<endl;
    for (auto o:ans) printf("%d %d\n",o.fi,o.se);
}