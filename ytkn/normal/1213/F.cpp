#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const int N_MAX = 200000;
int N;
bool used[N_MAX];
int idx[N_MAX];
vector<int> vs;
vector<int> buf;
vector<int> G[N_MAX];
vector<int> G_inv[N_MAX];
vector<vector<int>> ans;

void clear(){
    for(int i = 0; i < N; i++) used[i] = false;
}

void dfs1(int v){
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        if(!used[G[v][i]]) dfs1(G[v][i]);
    }
    vs.push_back(v);
}

void dfs2(int v, int k){
    used[v] = true;
    idx[v] = k;
    for(int i = 0; i < G_inv[v].size(); i++){
        if(!used[G_inv[v][i]]) dfs2(G_inv[v][i], k);
    }
    buf.push_back(v);
}

void scc(){
    for(int i = 0; i < N; i++){
        if(!used[i]) dfs1(i);
    }
    clear();
    int cur = 0;
    for(int i = vs.size()-1; i >= 0; i--){
        if(!used[vs[i]]) {
            dfs2(vs[i], cur);
            cur++;
            ans.push_back(buf);
            buf.clear();
        }
    }
}

int K;
int p[200000], q[200000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> p[i]; p[i]--;
        if(i >= 1){
            G[p[i-1]].push_back(p[i]);
            G_inv[p[i]].push_back(p[i-1]);
        }
    }
    for(int i = 0; i < N; i++){
        cin >> q[i]; q[i]--;
        if(i >= 1){
            G[q[i-1]].push_back(q[i]);
            G_inv[q[i]].push_back(q[i-1]);
        }
    }
    scc();
    int max_idx = 0;
    for(int i = 0; i < N; i++) max_idx = max(idx[i], max_idx);
    if(max_idx < K-1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        vector<char> ans;
        for(int i = 0; i < N; i++){
            if(idx[i] < K) ans.push_back('a'+idx[i]);
            else ans.push_back('a'+K-1);
        }
        for(char c : ans) cout << c;
        cout << endl;
    }
}