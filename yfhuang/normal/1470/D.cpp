#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;

int n, m;
const int maxn = 3e5 + 5;
vector<int> G[maxn];

int fa[maxn], sz[maxn];

int Find(int x){
    return x == fa[x] ? x: fa[x] = Find(fa[x]);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        set<int> A, B, L;
        for(int i = 1;i <= n;i++){
            fa[i] = i;
            sz[i] = 1;
            L.insert(i);
        }
        for(int i = 1;i <= m;i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            int fx = Find(u);
            int fy = Find(v);
            if(fx != fy){
                fa[fx] = fy;
                sz[fy] += sz[fx];
            }
        }
        bool flag = true;
        for(int i = 1;i <= n;i++){
            int fx = Find(i);
            if(fx == i){
                if(sz[i] != n){
                    flag = false;
                }
            }
        }
        if(!flag){
            for(int i = 1;i <= n;i++){
                G[i].clear();
            }
            cout << "NO" << endl;
            continue;
        }
        int u = *L.begin();
        B.insert(u);
        L.erase(u);
        while(!B.empty()){
            int u = *B.begin();
            B.erase(u);
            A.insert(u);
            vector<int> del;
            for(auto v : G[u]){
                if(L.find(v) != L.end()){
                    L.erase(v);
                    del.push_back(v);
                }
                if(B.find(v) != B.end()){
                    B.erase(v);
                    del.push_back(v);
                }
            }
            for(auto v : del){
                for(auto w : G[v]){
                    if(L.find(w) != L.end()){
                        L.erase(w);
                        B.insert(w);
                    }
                }
            }
        }
        cout << "YES" << endl;
        cout << A.size() << endl;
        int cnt = 0;
        for(auto it : A){
            cnt++;
            cout << it << ((cnt == A.size()) ? '\n' : ' ');
        }
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
    }
    return 0;
}