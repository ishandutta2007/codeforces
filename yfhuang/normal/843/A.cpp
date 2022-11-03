#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>




using namespace std;

const int maxn = 1e5 + 5;

pair<int,int> a[maxn];
int n;
int s[maxn],top;
vector<int> G[maxn];
int k;
bool vis[maxn];
void dfs(int u,int type){
    if(vis[u]){
        k++;
        if(type){
            printf("%d",top);
            while(top){
                printf(" %d",s[top--]);
            }
            cout << endl;
        }
        return;
    }
    vis[u] = 1;
    if(type) s[++top] = u;
    for(auto v : G[u]){
        dfs(v,type);
    }
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++){
        G[a[i].second].push_back(i);
    }
    k = 0;
    top = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++){
        if(!vis[i]) dfs(i,0);
    }
    printf("%d\n",k);
    top = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++){
        if(!vis[i])dfs(i,1);
    }
    return 0;
}