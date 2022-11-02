#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

set<int> leaves[200000], G[200000];

void solve(){
    // cout << "=====" << endl;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y; x--; y--;
        G[x].insert(y);
        G[y].insert(x);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(G[i].size() == 1){
            int to = *G[i].begin();
            leaves[to].insert(i);
        }
    }
    priority_queue<P> que;
    for(int i = 0; i < n; i++){
        que.push(P(leaves[i].size(), i));
    }
    while(true){
        P top = que.top();
        if(top.first < k) break;
        que.pop();
        int v = top.second;
        if(top.first != leaves[v].size()) continue;
        // cout << top.first << ' ' << top.second << endl;
        vector<int> to_erase;
        for(int i : leaves[v]){
            to_erase.push_back(i);
            if(to_erase.size() >= k) break;
        }

        for(int i : to_erase){
            leaves[v].erase(i);
            G[v].erase(i);
            G[i].erase(v);
        }
        if(G[v].size() == 1){
            int to = *G[v].begin();
            leaves[to].insert(v);
            que.push(P(leaves[to].size(), to));
        }
        ans++;
        que.push(P(leaves[v].size(), v));
    }
    cout << min(n-1, ans) << endl;
    for(int i = 0; i < n; i++){
        leaves[i].clear();
        G[i].clear();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}