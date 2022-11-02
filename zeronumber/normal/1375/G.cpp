#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+3;
const int M=1000000007;
vector <int> h[maxn];
int n,c[2];
void dfs(int u,int fa,int o){
    c[o]++;
    for (auto v:h[u]){
        if (v==fa) continue;
        dfs(v,u,o^1);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    dfs(1,0,0);
    printf("%d\n",min(c[0],c[1])-1);
    return 0;
}