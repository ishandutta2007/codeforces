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
int n, a, b, M, Name[100005];
bool vis[100005];
map <int, int> mp;
vector <int> v[100005];
void dfs(int i){
    vis[i] = true;
    cout << Name[i] << ' ';
    for(int j = 0; j < v[i].size(); j++)
        if(!vis[v[i][j]]){
            dfs(v[i][j]);
            break;
        }
    return;
}
int main(){
    cin >> n;
    M = 0;
    for(int itr = 0; itr < n; itr++){
        cin >> a >> b;
        if(!mp.count(a)){
            Name[M] = a;
            mp[a] = M++;
        }
        if(!mp.count(b)){
            Name[M] = b; 
            mp[b] = M++;
        }
        v[mp[a]].push_back(mp[b]);
        v[mp[b]].push_back(mp[a]);
    }
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < M; i++)
        if(v[i].size() == 1){
            dfs(i);
            cout << endl;
            break;
        }
    return 0;
}