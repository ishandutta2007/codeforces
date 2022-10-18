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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;
int n, ai, bi, ci, q, xi, sz, o[100005], L[100005], p[100005][20];
vector < pair <int, int> > g[100005];
char comm;
long long v[100005][20], d[100005];
void dfs(int i, long long c = 0){
    o[i] = sz++;
    d[i] = c;
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j].first;
        if(o[u] == -1){
            v[u][0] = g[i][j].second;
            p[u][0] = i;
            L[u] = L[i] + 1;
            
            dfs(u, c + g[i][j].second);
        }
    }
}
int lca(int u, int v){
    if(L[u] > L[v])swap(u, v);
    
    for(int i = 19; i >= 0; i--)
        if(p[v][i] != -1 && L[v] - (1 << i) >= L[u])
            v = p[v][i];
    if(u == v)return u;
    
    for(int i = 19; i >= 0; i--)
        if(p[v][i] != -1 && p[v][i] != p[u][i])
            v = p[v][i], u = p[u][i];
    return p[v][0];
}
long long dist(int u, int v){
    return d[u] + d[v] - 2 * d[lca(u, v)];
}
struct cmp{
    bool operator ()(int i, int j){
        return o[i] < o[j];
    }
};
set <int, cmp> s;
set <int, cmp> :: iterator next(set <int, cmp> :: iterator d){
    set <int, cmp> :: iterator ret = d;
    ret++;
    
    if(ret == s.end())return s.begin();
    else return ret;
}
set <int, cmp> :: iterator prev(set <int, cmp> :: iterator d){
    set <int, cmp> :: iterator ret = d;
    
    if(ret == s.begin())ret = s.end();
    ret--;
    
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int edge = 0; edge < n - 1; edge++){
        cin >> ai >> bi >> ci;
        ai--, bi--;
        g[ai].push_back(make_pair(bi, ci));
        g[bi].push_back(make_pair(ai, ci));
    }
    memset(o, -1, sizeof o);
    memset(p, -1, sizeof p);
    dfs(0);
    
    for(int k = 1; (1 << k) < n; k++){
        for(int i = 0; i < n; i++){
            if(p[i][k - 1] == -1)p[i][k] = -1;
            else p[i][k] = p[p[i][k - 1]][k - 1];
        }
    }
    for(int k = 1; (1 << k) < n; k++){
        for(int i = 0; i < n; i++){
            if(p[i][k] == -1)v[i][k] = 0;
            else v[i][k] = v[i][k - 1] + v[p[i][k - 1]][k - 1];
        }
    }
    
    
    long long cur = 0;
    cin >> q;
    while(q--){
        cin >> comm;
        if(comm == '?'){
            assert(cur % 2 == 0);
            cout << cur / 2 << endl;
        }else if(comm == '+'){
            cin >> xi;
            xi--;
            
            if(s.size() == 0){
                s.insert(xi);
                continue;
            }
            if(s.size() == 1){
                cur += 2 * dist(xi, *s.begin());
                s.insert(xi);
            }else{
                s.insert(xi);
                set <int, cmp> :: iterator d = s.find(xi);
                cur += dist(*d, *prev(d)) + dist(*d, *next(d)) - dist(*prev(d), *next(d));
            }
        }else{
            cin >> xi;
            xi--;
            
            if(s.size() < 2){
                s.erase(xi);
                continue;
            }
            if(s.size() == 2){
                cur = 0;
                s.erase(xi);
            }else{
                set <int, cmp> :: iterator d = s.find(xi);
                cur -= dist(*d, *prev(d)) + dist(*d, *next(d)) - dist(*prev(d), *next(d));
                s.erase(xi);
            }
        }
    }
    return 0;
}