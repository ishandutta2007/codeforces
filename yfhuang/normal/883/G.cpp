#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
using namespace std;
const int maxn=3e5+50;
int n,m,s;
vector<int> e1[maxn];
vector<pair<int,int>> e2[maxn];
int tot;
bool v[maxn];
char ans[maxn];

void dfs1(int x){
    v[x]=1;
    for (int y:e1[x]){
        if (!v[y]) dfs1(y);
    }
    for (pair<int,int> tmp:e2[x]){
        if (!v[tmp.first]){
            if (tmp.second&1) ans[tmp.second/2]='-';
            else ans[tmp.second/2]='+';
            dfs1(tmp.first);
        }
    }
}

void dfs2(int x){
    v[x]=1;
    for (int y:e1[x]){
        if (!v[y]) dfs2(y);
    }
    for (pair<int,int> tmp:e2[x]){
        if (!v[tmp.first]){
            if (tmp.second&1) ans[tmp.second/2]='+';
            else ans[tmp.second/2]='-';
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    tot=1;
    for (int i=1;i<=m;i++){
        int t,u,v;
        scanf("%d%d%d",&t,&u,&v);
        if (t==1){
            e1[u].push_back(v);
        }
        else{
            e2[u].push_back(make_pair(v,++tot));
            e2[v].push_back(make_pair(u,++tot));
        }
    }
    for (int i=1;i<=tot/2;i++) ans[i]='+';
    memset(v,0,sizeof(v));
    dfs1(s);
    int ret=0;
    for (int i=1;i<=n;i++) if (v[i]) ret++;
    printf("%d\n",ret);
    for (int i=1;i<=tot/2;i++) printf("%c",ans[i]);
    puts("");
    
    memset(v,0,sizeof(v));
    dfs2(s);
    ret=0;
    for (int i=1;i<=n;i++) if (v[i]) ret++;
    printf("%d\n",ret);
    for (int i=1;i<=tot/2;i++) printf("%c",ans[i]);
    puts("");
}