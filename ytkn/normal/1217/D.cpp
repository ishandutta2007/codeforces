#include <iostream>
#include <vector>

using namespace std;

struct edge{
    int from, to;
};

edge es[5000];
vector<edge> G[5000];
vector<edge> G_in[5000];

int cnt_in[5000];
int cnt_out[5000];

bool checked[5000];

int cnt;

void dfs(int v){
    checked[v] = true;
    cnt++;
    for(int i = 0; i < G[v].size(); i++){
        int to = G[v][i].to;
        if(!checked[to]) {
            cnt_in[to]--;
            if(cnt_in[to] <= 0){
                dfs(to);
            }
        }
    }
    for(int i = 0; i < G_in[v].size(); i++){
        int from = G_in[v][i].from;
        if(!checked[from]) {
            cnt_out[from]--;
            if(cnt_in[from] <= 0){
                dfs(from);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge e = (edge){u, v};
        es[i] = e;
        G[u].push_back(e);
        G[v].push_back(e);
        cnt_out[u]++;
        cnt_in[v]++;
        //cout << e.to << ' ' << e.from << endl;
    }
    bool loop = false;
    for(int i = 0; i < n; i++){
        //cout << cnt_in[i] << ' ' << cnt_out[i] << endl;
        if(!checked[i] && (cnt_in[i] <= 0 || cnt_out[i] <= 0)){
            dfs(i);
        }
    }
    //cout << cnt << endl;
    if(cnt != n) {
        loop = true;
    }
    if(loop){
        cout << 2 << endl;
        for(int i = 0; i < m; i++){
            int ans = 1;
            //cout << es[i].to << ' ' << es[i].from << endl;
            if(es[i].to < es[i].from) ans = 2;
            cout << ans;
            if(i != m-1) cout << ' ';
            else cout << endl;
        }
    }else{
        cout << 1 << endl;
        for(int i = 0; i < m-1; i++){
            cout << 1 << ' ';
        }
        cout << 1 << endl;
    }
}