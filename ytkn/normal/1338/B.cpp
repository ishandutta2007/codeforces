#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
vector<int> G[100000];
int depth[100000];
bool used[100000];
bool is_leaf[100000];
int parent[100000];

void dfs(int v, int d){
    used[v] = true;
    depth[v] = d;
    int cnt = 0;
    for(int to : G[v]){
        if(!used[to]){
            dfs(to, d+1);
            cnt++;
            parent[to] = v;
        }
    }
    if(cnt == 0) is_leaf[v] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int r;
    for(int i = 0; i < n; i++){
        if(G[i].size() >= 2) {
            r = i;
            break;
        }
    }
    // cout << r << endl;
    parent[r] = -1;
    dfs(r, 0);
    int ans_min, ans_max;
    int cnto = 0, cnte = 0;
    for(int i = 0; i < n; i++){
        if(is_leaf[i]){
            if(depth[i]%2 == 0) cnte++;
            else cnto++;
        }
    }
    if(cnte == 0 || cnto == 0) ans_min = 1;
    else ans_min = 3;
    set<int> st;
    ans_max = n-1;
    for(int i = 0; i < n; i++){
        if(is_leaf[i]){
            if(st.count(parent[i])) ans_max--;
            else st.insert(parent[i]);
        }
    }
    cout << ans_min << ' ' << ans_max << endl;
}