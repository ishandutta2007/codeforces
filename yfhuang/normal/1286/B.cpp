#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxn = 2005;
int c[maxn], p[maxn];

vector<int> G[maxn];

int sz[maxn];

void dfs(int u){
    sz[u] = 1;
    for(auto v : G[u]){
        dfs(v);
        sz[u] += sz[v];
    }
}

int b[maxn];

void dfs2(int u, int bar){
    if(b[u] >= bar){
        b[u]++;
    }
    for(auto v : G[u]){
        dfs2(v, bar);
    }
}

void dfs1(int u, int add){
    //cout << u << " " << add << " " << c[u] << endl;
    b[u] = add + c[u] + 1; 
    //cout << "!!!" << b[u] << endl;
    int cnt = 0;
    for(auto v : G[u]){
        dfs1(v, add + cnt);
        cnt += sz[v];
    }
    for(auto v : G[u]){
        dfs2(v, b[u]);
    }
}


int main(){
    cin >> n;
    int root;
    for(int i = 1;i <= n;i++){
        cin >> p[i] >> c[i];
        if(p[i] == 0)
           root = i; 
        else
            G[p[i]].push_back(i);
    }
    dfs(root);
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if(c[i] + 1 > sz[i]){
            flag = false;
        }
    }
    if(flag){
        dfs1(root, 0);
        cout << "YES" << endl;
        for(int i = 1;i <= n;i++){
            printf("%d%c", b[i], i == n ? '\n' : ' ');
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}