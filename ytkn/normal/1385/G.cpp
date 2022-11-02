#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

struct edge{
    int to, cost;
};

vector<int> v[200000];
vector<edge> G[200000];
int a0[200000], a1[200000];
int dist[200000];
bool used[200000];

void clear(int n){
    for(int i = 0; i < n; i++) v[i].clear();
    for(int i = 0; i < n; i++) G[i].clear();
    for(int i = 0; i < n; i++) used[i] = false;
}

vector<int> buf[2];
bool ok;
void dfs(int v, int d){
    // cout << "dfs(" << v << "," << d << ")" << endl;
    used[v] = true;
    dist[v] = d;
    buf[d].push_back(v);
    for(edge e : G[v]){
        if(!used[e.to]){
            dfs(e.to, d^e.cost);
        }else{
            if(dist[e.to] != d^e.cost){
                ok = false;
                return;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a0[i]; a0[i]--;
        v[a0[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> a1[i]; a1[i]--;
        v[a1[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(v[i].size() != 2){
            clear(n);
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 0; i < n; i++){
        int v0 = v[i][0];
        int v1 = v[i][1];
        if(v0 == v1) continue;
        if(a0[v0] == a0[v1] || a1[v0] == a1[v1]) {
            G[v0].push_back((edge){v1, 1});
            G[v1].push_back((edge){v0, 1});
        }else{
            G[v0].push_back((edge){v1, 0});
            G[v1].push_back((edge){v0, 0});
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            buf[0].clear(); buf[1].clear(); ok = true;
            dfs(i, 0);
            if(!ok){
                cout << -1 << endl;
                clear(n);
                return;
            }
            if(buf[0].size() < buf[1].size()){
                for(int j : buf[0]) ans.push_back(j);
            }else{
                for(int j : buf[1]) ans.push_back(j);
            }
        }
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i+1 << ' ';
    cout << endl;
    clear(n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}