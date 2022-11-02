#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;
vector<int> v;
vector<int> G[100000];
vector<int> ver;
ll a[100000];
bool used[100000];
int dist[100000];
int pre[100000];
const int INF= 1e+8;

void clear(){
    for(int i = 0; i < ver.size(); i++){
        used[ver[i]] = false;
        dist[ver[i]] = 0;
    }
}

int loop;

void bfs(int v, int r){
    used[v] = true;
    queue<int> que;
    que.push(v);
    while(!que.empty()){
        int top = que.front();
        //cout << top << ' ' << dist[top] << endl;
        que.pop();
        for(int i = 0; i < G[top].size(); i++){
            if(G[top][i] == r){
                continue;
            }
            if(!used[G[top][i]]){
                que.push(G[top][i]);
                used[G[top][i]] = true;
                dist[G[top][i]] = dist[top]+1;
                pre[G[top][i]] = top;
            }else{
                if(top == r) continue;
                if(G[top][i] != pre[top] && pre[G[top][i]] != top) {
                    loop = min(loop, dist[top]+dist[G[top][i]]+1);
                }
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        //cout << bitset<10>(a[i]) << endl;
    }

    for(int i = 0; i <= 60; i++){
        ll m = (ll)1<<i;
        v.clear();
        for(int i = 0; i < N; i++){
            if(a[i]&m){
                v.push_back(i);
            }
        }
        if(v.size() <= 1) continue;
        if(v.size() >= 3){
            cout << 3 << endl;
            return 0;
        }
        G[v[0]].push_back(v[1]);
        G[v[1]].push_back(v[0]);
        ver.push_back(v[0]);
        ver.push_back(v[1]);
        //cout << v[0] << ' ' << v[1] << endl;
    }
    int ans = INF;
    for(int i = 0; i < N; i++){
        if(G[i].size() != 0){
            //cout << "root:" << i << endl;
            clear();
            loop = 1e+8;
            bfs(i, i);
            ans = min(ans, loop);
            //cout << ans << endl;
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}