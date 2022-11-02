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
const int maxn = 2e5 + 5;
vector<int> G[maxn];
vector<int> rG[maxn];
int d[maxn];

void bfs(int s){
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto v : G[p]){
            if(d[v] > d[p] + 1){
                d[v] = d[p] + 1;
                q.push(v);
            }
        }
    }
}

int n, m, k;
int p[maxn];
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        rG[u].push_back(v);
        G[v].push_back(u);
    }    
    cin >> k;
    for(int i = 1;i <= k;i++){
        scanf("%d", &p[i]);
    }
    bfs(p[k]);
    int mi = 0, mx = 0;
    for(int i = 1;i < k;i++){
        //cout << d[p[i]] << " " << d[p[i + 1]] << endl;
        if(d[p[i]] != d[p[i + 1]] + 1)
            mi++, mx++;
        else{
            bool flag = false;
            for(auto v : rG[p[i]]){
                if(v == p[i + 1])
                    continue;
                if(d[v] == d[p[i + 1]])
                    flag = true;
            }
            if(flag)
                mx++;
        }
    }
    cout << mi << " " << mx << endl;
    return 0;
}