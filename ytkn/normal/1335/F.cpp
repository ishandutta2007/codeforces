#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int n, m;
vector<int> G[1000000];
vector<int> G_inv[1000000];
bool used[1000000];
int depth[1000000];
int c[1000000];

int idx(int h, int w){
    return h*m+w;
}

void clear(){
    for(int i = 0; i < n*m; i++){
        used[i] = false;
        G[i].clear();
        G_inv[i].clear();
    }
}

bool is_in_loop(int i, int j){
    int k = idx(i, j);
    return G[k].size() == 1 && G_inv[k].size() == 1;
}

int loop_idx;
int find_loop(int v){
    used[v] = true;
    for(int to : G[v]){
        if(!used[to]){
            find_loop(to);
        }else{
            loop_idx = to;
        }
    }
    used[v] = false;
}

int loop;
vector<int> buf;

void dfs(int v, int d){
    used[v] = true;
    buf.push_back(v);
    depth[v] = d;
    for(int to : G_inv[v]){
        if(!used[to]){
            dfs(to, d+1);
        }else{
            loop = d+1;
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char s;
            cin >> s;
            c[idx(i, j)] = s-'0'; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            int from = idx(i, j);
            int to;
            if(c == 'L') to = idx(i, j-1);
            if(c == 'R') to = idx(i, j+1);                
            if(c == 'D') to = idx(i+1, j);                                
            if(c == 'U') to = idx(i-1, j); 
            G[from].push_back(to);
            G_inv[to].push_back(from);                   
        }
    }
    int ans = 0;
    int ans_black = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!used[idx(i, j)]){
                find_loop(idx(i, j));
                dfs(loop_idx, 0);
                ans += loop;
                vector<bool> used_black(buf.size(), false);
                for(int v : buf){
                    int d = depth[v]%loop;
                    if(!used_black[d] && c[v] == 0){
                        ans_black++;
                        used_black[d] = true;
                    }
                }
                buf.clear();
            }
        }
    }
    cout << ans << ' ' << ans_black << endl;
    clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}