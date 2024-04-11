#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int n, s, a, b, k[100005];
long long dp[100005];
vector <int> g[100005];
void solve(int i, int parent){
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u != parent)solve(u, i);
    }
    dp[i] = 0;
    vector < pair<long long, int> > v;
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u != parent)v.push_back(make_pair(dp[u], u));
    }
    sort(v.rbegin(), v.rend());
    for(int j = 0; j < v.size(); j++){
        if(k[v[j].second] > 0 && (k[i] > 1 || ((i == s - 1) && k[i] > 0))){
            dp[i] += v[j].first;
            dp[i] += 2;
            k[v[j].second]--;
            k[i]--;
        }
    }
    for(int j = 0; j < g[i].size(); j++){

        int u = g[i][j];
        if(u == parent)continue;

        if(k[u] > 0 && (k[i] > 1 || ((i == s - 1) && k[i] > 0))){
            if(i == s - 1){
                dp[i] += min(k[i], k[u]) * 2;
                k[i] -= min(k[i], k[u]);
            }else{
                dp[i] += min(k[i] - 1, k[u]) * 2;
                k[i] -= min(k[i] - 1, k[u]);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> k[i];
    for(int i = 0; i < (n - 1); i++){
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    cin >> s;
    solve(s - 1, -1);
    cout << dp[s - 1] << endl;
    return 0;
}