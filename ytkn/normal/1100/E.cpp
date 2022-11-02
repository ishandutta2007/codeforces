#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int n, m;
int u[100000], v[100000];
ll c[100000];
P p[100000];

vector<int> G_in[100000];
vector<int> G_out[100000];
int cnt_in[100000];
int cnt_out[100000];
bool used[100000];

void dfs(int v){
    used[v] = false;
    for(int from : G_in[v]){
        cnt_out[from]--;
        if(cnt_out[from] == 0 && used[from]) dfs(from);
    }
    for(int to : G_out[v]){
        cnt_in[to]--;
        if(cnt_in[to] == 0 && used[to]) dfs(to);        
    }
}

bool loop_detect(int n_vertex){
    for(int i = 0; i < n_vertex; i++) used[i] = true;
    for(int i = 0; i < n_vertex; i++) cnt_in[i] = G_in[i].size();
    for(int i = 0; i < n_vertex; i++) cnt_out[i] = G_out[i].size();
    for(int i = 0; i < n_vertex; i++){
        if(cnt_in[i] == 0 || cnt_out[i] == 0){
            if(used[i]) dfs(i);
        }
    }
    for(int i = 0; i < n_vertex; i++) {
        if(used[i]) return true;
    }
    return false;
}

bool judge(int w){
    for(int i = 0; i < n; i++){
        G_in[i].clear();
        G_out[i].clear();
    }
    for(int i = 0; i < m; i++){
        if(c[i] >= w){
            G_in[v[i]].push_back(u[i]);
            G_out[u[i]].push_back(v[i]);
        }
    }
    return loop_detect(n);
}

vector<int> G[100000];
bool used_tsort[100000];
vector<int> tsort_result;
int tsort_idx[100000];

void dfs_tsort(int v){
    used_tsort[v] = true;
    for(int to : G[v]){
        if(!used_tsort[to]) dfs_tsort(to);
    }
    tsort_result.push_back(v);
}

void tsort(){
    for(int i = 0; i < n; i++){
        if(!used_tsort[i]) dfs_tsort(i);
    }
    reverse(tsort_result.begin(), tsort_result.end());
    for(int i = 0; i < n; i++) tsort_idx[tsort_result[i]] = i;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        u[i]--; v[i]--;
    }
    if(!judge(1)){
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    int l = 1, r = (1e9)+1;
    while(r-l > 1){
        int w = (l+r)/2;
        if(judge(w)) l = w;
        else r = w;
    }
    int cnt = 0;
    vector<int> vs;
    for(int i = 0; i < m; i++){
        if(c[i] >= r) {
            G[u[i]].push_back(v[i]);
        }
    }
    tsort();
    for(int i = 0; i < m; i++){
        if(c[i] < r) {
            if(tsort_idx[u[i]] > tsort_idx[v[i]]){
                vs.push_back(i+1);
                cnt++;
            }
        }
    }
    cout << r-1 << ' ' << cnt << endl;
    for(int i : vs) cout << i << ' ';
    cout << endl;
}