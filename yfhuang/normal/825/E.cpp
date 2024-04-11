#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;

vector<int> G[maxn];
int deg[maxn];
int ans[maxn];

int main(){
    int n,m;
    while(cin >> n >> m){
        priority_queue<int > pq;
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
        for(int i = 1;i <= m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            deg[a]++;
            G[b].push_back(a);
        }
        for(int i = 1;i <= n;i++){
            sort(G[i].begin(),G[i].end());
            if(deg[i] == 0) pq.push(i);
        }
        int tot = 0;
        while(!pq.empty()){
            int p = pq.top();pq.pop();
            ans[p] = n - (tot++);
            for(int i = 0;i < G[p].size();i++){
                int v = G[p][i];
                deg[v]--;
                if(deg[v] == 0) pq.push(v);
            }
        }
        for(int i = 1;i <= n;i++) printf("%d ",ans[i]);
    }
    return 0;
}