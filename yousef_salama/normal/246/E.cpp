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
#define MAXN 100005
using namespace std;
int n, m, ri, vi, ki, ans[100005], p[100005], d[100005];
string s;
map <int, int> mp[100005];
set < pair <string, int> > v[100005];
vector <int> g[100005];
vector < pair <int, int> > Q[100005];
bool root[100005], visited[100005];

void calc(int i){
    visited[i] = true;
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        calc(u);
        
        if(v[p[u]].size() < v[p[i]].size()){
            for(set < pair <string, int> > :: iterator it = v[p[u]].begin(); it != v[p[u]].end(); it++){
                pair <string, int> cur = make_pair((*it).first, (*it).second + 1 + d[p[u]] - d[p[i]]);
                if(!v[p[i]].count(cur)){
                    v[p[i]].insert(cur);
                    mp[p[i]][cur.second]++;
                }
            }
        }else{
            for(set < pair <string, int> > :: iterator it = v[p[i]].begin(); it != v[p[i]].end(); it++){
                pair <string, int> cur = make_pair((*it).first, (*it).second - 1 + d[p[i]] - d[p[u]]);
                if(!v[p[u]].count(cur)){
                    v[p[u]].insert(cur);
                    mp[p[u]][cur.second]++;
                }
            }
            d[p[u]]++;
            swap(p[i], p[u]);
        }
    }
    for(int j = 0; j < Q[i].size(); j++){
        ans[Q[i][j].second] = mp[p[i]][Q[i][j].first - d[p[i]]];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> ri;
        ri--;
    
        p[i] = i;
        mp[i][0] = 1;
        v[i].insert(make_pair(s, 0));
        
        if(ri >= 0)g[ri].push_back(i);
        else root[i] = true;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> vi >> ki;
        vi--;
        
        Q[vi].push_back(make_pair(ki, i));
    }
    for(int i = 0; i < n; i++)
        if(root[i] && !visited[i]){
            calc(i);
        }
    for(int i = 0; i < m; i++)
        cout << ans[i] << endl;
    return 0;
}