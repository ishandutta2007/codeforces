#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int t;
int n, a, b, da, db;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
int dis[maxn];

void bfs(int s){
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(auto v : G[p]){
            if(dis[v] > dis[p] + 1){
                dis[v] = dis[p] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> da >> db;
        for(int i = 1;i < n;i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(db <= 2 * da){
            cout << "Alice" << endl;
        }else{
            bfs(a);
            if(dis[b] <= da){
                cout << "Alice" << endl;
            }else{
                int mx = 0;
                for(int i = 1;i <= n;i++){
                    mx = max(mx, dis[i]);
                }
                if(mx <= 2 * da){
                    bfs(b);
                    mx = 0;
                    for(int i = 1;i <= n;i++){
                        mx = max(mx, dis[i]);
                    }
                    if(mx > 2 * da){
                        cout << "Bob" << endl;
                    }else{
                        mx = 0;
                        int mxid = b;
                        for(int i = 1;i <= n;i++){
                            if(dis[i] > mx){
                                mx = dis[i];
                                mxid = i;
                            }
                        }
                        bfs(mxid);
                        for(int i = 1;i <= n;i++){
                            mx = max(mx, dis[i]);
                        }
                        if(mx > 2 * da){
                            cout << "Bob" << endl;
                        }else{
                            cout << "Alice" << endl;
                        }
                    }
                }else{
                    cout << "Bob" << endl;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
    }
    return 0;
}