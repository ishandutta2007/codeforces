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
#include <random>
#include <chrono>
using namespace std;

const int maxn = 2e5 + 5;

int n;
int x[maxn], y[maxn];

int v[maxn];
int coeff[maxn];
int tot;

vector<int> G[maxn];

void dfs(int u, int coeff){
    v[u] *= coeff;
    for(auto to : G[u]){
        dfs(to, v[u]);
    }
}

vector<int> solve(vector<int> cur){
    vector<int> ans;
    for(int j = 0;j < 6;j++){
        for(int k = 0;k < 6;k++){
            int id1 = j / 2;
            int id2 = k / 2;
            if(id1 == id2)
                continue;
            int sign1 = (j % 2 == 0) ? 1 : -1;
            int sign2 = (k % 2 == 0) ? 1 : -1;
            int px = sign1 * x[cur[id1]] + sign2 * x[cur[id2]];
            int py = sign1 * y[cur[id1]] + sign2 * y[cur[id2]];
            if(1LL * px * px + 1LL * py * py <= 1e12){
                //cout << cur[id1] << " " << cur[id2] << endl;
                v[cur[id1]] = sign1;
                v[cur[id2]] = sign2;
                ++tot;
                x[tot] = px;
                y[tot] = py;
                G[tot].push_back(cur[id1]);
                G[tot].push_back(cur[id2]);
                int id3 = 0 ^ 1 ^ 2 ^ id1 ^ id2;
                ans.push_back(cur[id3]);
                ans.push_back(tot);
                return ans;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }else if(n == 2){
        int px = x[1] + x[2];
        int py = y[1] + y[2];
        if(1LL * px * px + 1LL * py * py > 2.25 * 1e12){
            cout << 1 << " " << -1 << endl; 
        }else{
            cout << 1 << " " << 1 << endl;
        }
        return 0;
    }
    tot = n;
    vector<int> cur;
    cur.push_back(1);
    cur.push_back(2);
    for(int i = 3;i <= n;i++){
        cur.push_back(i);
        cur = solve(cur);
    }
    tot++;
    int id1 = cur[0], id2 = cur[1];
    //cout << id1 << " " << id2 << endl;
    int px = x[id1] + x[id2];
    int py = y[id1] + y[id2];
    if(1LL * px * px + 1LL * py * py > 2.25 * 1e12){
        v[id1] = 1;
        v[id2] = -1;
        G[tot].push_back(id1);
        G[tot].push_back(id2);
        v[tot] = 1;
        dfs(tot, 1);
    }else{
        v[id1] = 1;
        v[id2] = 1;
        G[tot].push_back(id1);
        G[tot].push_back(id2);
        v[tot] = 1;
        dfs(tot, 1);
    }
    for(int i = 1;i <= n;i++){
        printf("%d%c", v[i], i == n ? '\n' : ' ');
    }
    return 0;
}