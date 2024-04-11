//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int n, m, ai, bi, wi, parent[100005];
vector < pair <int, int> > g[100005];

long long dist[100005];
bool vis[100005];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &ai, &bi, &wi);
        ai--, bi--;

        g[ai].push_back(make_pair(bi, wi));
        g[bi].push_back(make_pair(ai, wi));
    }
    
    dist[0] = 0;
    for(int i = 1; i < n; i++)dist[i] = 1LL << 60;
    
    priority_queue < pair <long long, int> > q;
    q.push(make_pair(0, 0));
    
    while(!q.empty()){
        pair <long long, int> t = q.top();
        q.pop();
        
        if(vis[t.second])continue;
        vis[t.second] = true;
        
        for(int j = 0; j < g[t.second].size(); j++){
            int u = g[t.second][j].first, c = g[t.second][j].second;
            if(dist[t.second] + c < dist[u]){
                dist[u] = dist[t.second] + c;
                parent[u] = t.second;
                
                q.push(make_pair(-dist[u], u));
            }
        }
    }
    
    if(dist[n - 1] == (1LL << 60)){
        printf("-1\n");
        return 0;
    }
    
    vector <int> path;
    
    int u = n - 1;
    while(u != 0){
        path.push_back(u);
        u = parent[u];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    
    for(int i = 0; i < path.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", path[i] + 1);
    }
    printf("\n");
    
    return 0;
}