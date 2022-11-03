//
//  main.cpp
//  D
//
//  Created by  on 8/29/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <vector>

using namespace std;

int n;

const int MAX = 2e5 + 5;
typedef long long ll;

const ll mod = 1e9 + 7;

struct Edge{
    int v,next,c;
}edge[MAX];
int head[MAX];
int tot;
int low[MAX];
int dfn[MAX];
int instack[MAX];
int sstack[MAX];
int belong[MAX];
int top,Index,cnt;
int num[MAX];
void init(){
    memset(head,-1,sizeof(head));
    memset(instack,0,sizeof(instack));
    memset(dfn,0,sizeof(dfn));
    memset(num,0,sizeof(num));
    tot=top=Index=0;
}

void add_edge(int a,int b){
    edge[tot]=(Edge){b,head[a]};
    head[a]=tot++;
}
void tarjan(int u){
    dfn[u]=low[u]=++Index;
    sstack[++top]=u;
    instack[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(instack[v]) low[u]=min(dfn[v],low[u]);
    }
    if(dfn[u]==low[u]){
        cnt++;
        while(1){
            int k=sstack[top--];
            instack[k]=0;
            belong[k]=cnt;
            num[cnt]++;
            if(k==u) break;
        }
    }
}

long long mod_pow(long long a,long long n){
    long long ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const int maxn = 1e5 + 5;
//
//vector<pair<int,int> > G[maxn];
//typedef long long ll;
//
//ll dis[maxn];
//bool vis[maxn];
//int m;
//queue<int> q;
//void init(int n){
//    for(int i = 1;i <= n;i++){
//        G[i].clear();
//        dis[i] = 1e15;
//        vis[i] = 0;
//    }
//    while(!q.empty()) q.pop();
//}
//int x[maxn],y[maxn],c[maxn],w[maxn];
//ll bellman(){
//    while(!q.empty()){
//        int now = q.front();
//        q.pop();
//        vis[now] = false;
//        for(int i = 0;i < (int) G[now].size();i++){
//            int v = G[now][i].first;
//            if(dis[v] > dis[now] + (ll) G[now][i].second){
//                dis[v] = dis[now] + (ll) G[now][i].second;
//                if(vis[v] == false){
//                    q.push(v);
//                    vis[v] = true;
//                }
//            }
//        }
//    }
//    ll ans = 0;
//    for(int i = 1;i <= m;i++){
//        if(w[i] == 2){
//            if(dis[i] == 1e15) return -1;
//            ans += dis[i];
//        }
//    }
//    return ans;
//}
//int n;
//int main(){
//    int cas = 0;
//    int T;
//    cin >> T;
//    while(T--){
//        scanf("%d%d",&n,&m);
//        init(m);
//        for(int i = 1;i <= n;i++) scanf("%d",x + i);
//        for(int i = 1;i <= n;i++) scanf("%d",y + i);
//        for(int i = 1;i <= n;i++) scanf("%d",c + i);
//        for(int i = 1;i <= m;i++){
//            scanf("%d",w + i);
//        }
//        for(int i = 1;i <= n;i++){
//            G[y[i]].push_back(make_pair(x[i],c[i]));
//            if(w[y[i]] == 0){
//                dis[y[i]] = 0;
//                q.push(y[i]);
//                vis[y[i]] = true;
//            }
//        }
//        printf("Case #%d: ",++cas);
//        cout << bellman() << endl;
//    }
//}


int main(int argc, const char * argv[]) {
    cin >> n;
    init();
    for(int i = 1;i <= n;i++){
        int to;
        scanf("%d",&to);
        add_edge(i,to);
    }
    for(int i = 1;i <= n;i++) if(!dfn[i]) tarjan(i);
    ll ans = 1;
    int x = 0;
    for(int i = 1;i <= cnt;i++){
        if(num[i] > 1){
            ans = ans * (mod_pow(2,(ll)num[i]) - 2 + mod) % mod;
            x += num[i];
        }
    }
    ans = ans * mod_pow(2,n - x) % mod;
    cout << ans << endl;
    return 0;
}