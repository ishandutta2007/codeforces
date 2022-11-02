#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 1e6 + 5;

vector<int> G[maxn];

int n;
int val[maxn];
int op[maxn];
// AND: 1 OR: 2 XOR: 3 NOT: 4 IN: 5

int tag[maxn];

void dfs(int u){
    if(op[u] == 5){
        val[u] = G[u][0];
    }else{
        for(auto v : G[u]){
            dfs(v);
        }
        if(op[u] == 1){
            val[u] = val[G[u][0]] & val[G[u][1]];
        }else if(op[u] == 2){
            val[u] = val[G[u][0]] | val[G[u][1]];
        }else if(op[u] == 3){
            val[u] = val[G[u][0]] ^ val[G[u][1]];
        }else if(op[u] == 4){
            val[u] = !val[G[u][0]];
        }
    }
}

vector<pair<int, int> > p;

void dfs1(int u){
    //cout << u << " " << tag[u] << endl;
    if(op[u] == 5){
        if(tag[u] == 1){
            p.emplace_back(u, val[1] ^ 1);
        }else{
            p.emplace_back(u, val[1]);
        }
    }else{
        if(tag[u] == 0){
            for(auto v : G[u]){
                tag[v] = 0;
                dfs1(v);
            }
        }else{
            if(op[u] == 1){
                int v1 = val[G[u][0]];
                int v2 = val[G[u][1]];
                if(((v1 ^ 1) & v2) != (v1 & v2)){
                    tag[G[u][0]] = 1;
                }
                if((v1 & (v2 ^ 1)) != (v1 & v2)){
                    tag[G[u][1]] = 1;
                }
            }else if(op[u] == 2){
                int v1 = val[G[u][0]];
                int v2 = val[G[u][1]];
                if(((v1 ^ 1) | v2) != (v1 | v2)){
                    tag[G[u][0]] = 1;
                }
                if((v1 | (v2 ^ 1)) != (v1 | v2)){
                    tag[G[u][1]] = 1;
                }
            }else if(op[u] == 3){
                int v1 = val[G[u][0]];
                int v2 = val[G[u][1]];
                if(((v1 ^ 1) ^ v2) != (v1 ^ v2)){
                    tag[G[u][0]] = 1;
                }
                if((v1 ^ (v2 ^ 1)) != (v1 ^ v2)){
                    tag[G[u][1]] = 1;
                }
            }else if(op[u] == 4){
                tag[G[u][0]] = 1; 
            }
            for(auto v : G[u]){
                dfs1(v);
            }
        }
    } 
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++){
        cin >> s;
        int u, v;
        if(s == "AND"){
            op[i] = 1;
            cin >> u >> v;
            G[i].push_back(u);
            G[i].push_back(v);
        }else if(s == "OR"){
            cin >> u >> v;
            G[i].push_back(u);
            G[i].push_back(v);
            op[i] = 2;
        }else if(s == "XOR"){
            cin >> u >> v;
            G[i].push_back(u);
            G[i].push_back(v);
            op[i] = 3;
        }else if(s == "NOT"){
            cin >> u;
            G[i].push_back(u);
            op[i] = 4;
        }else if(s == "IN"){
            cin >> u;
            G[i].push_back(u);
            op[i] = 5;
        }
    }
    tag[1] = 1;
    dfs(1);
    //cout << val[1] << endl;
    dfs1(1);
    sort(p.begin(), p.end());
    string ans = "";
    for(int i = 0;i < p.size();i++){
        ans.push_back(p[i].second + '0');
    }
    cout << ans << endl;
    return 0;
}