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
int n, xi, d[300];
pair <int, int> s[1005], e[1005];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
char ci;
vector <int> Ax, Ay;
int num[2005][2005];
void dfs(int i, int j){
    if(num[i][j])return;
    
    num[i][j] = 2;
    for(int dir = 0; dir < 4; dir++){
        int ni = i + di[dir], nj = j + dj[dir];
        if(ni >= 0 && nj >= 0 && ni < 2005 && nj < 2005){
            dfs(ni, nj);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    d['D'] = 0;
    d['U'] = 1;
    d['R'] = 2;
    d['L'] = 3;
    
    cin >> n;
    Ax.push_back(INT_MIN);
    Ax.push_back(INT_MAX);
    Ay.push_back(INT_MIN);
    Ay.push_back(INT_MAX);
    
    pair <int, int> p = make_pair(0, 0);
    Ax.push_back(p.first);
    Ay.push_back(p.second);
    Ax.push_back(p.first - 1);
    Ay.push_back(p.second - 1);
    for(int i = 0; i < n; i++){
        cin >> ci >> xi;
        
        int dir = d[ci];
        pair <int, int> cur = make_pair(p.first + di[dir] * xi, p.second + dj[dir] * xi);
        
        s[i].first = p.first;
        e[i].first = cur.first;
        s[i].second = p.second;
        e[i].second = cur.second;
        if(e[i] < s[i])swap(e[i], s[i]);
        
        Ax.push_back(cur.first);
        Ay.push_back(cur.second);
        
        Ax.push_back(cur.first - 1);
        Ay.push_back(cur.second - 1);
        
        p = cur;
    }
    sort(Ax.begin(), Ax.end());
    Ax.resize(unique(Ax.begin(), Ax.end()) - Ax.begin());
    
    sort(Ay.begin(), Ay.end());
    Ay.resize(unique(Ay.begin(), Ay.end()) - Ay.begin());
    
    for(int i = 0; i < n; i++){
        int xs = lower_bound(Ax.begin(), Ax.end(), s[i].first) - Ax.begin();
        int xe = lower_bound(Ax.begin(), Ax.end(), e[i].first) - Ax.begin();
        
        int ys = lower_bound(Ay.begin(), Ay.end(), s[i].second) - Ay.begin();
        int ye = lower_bound(Ay.begin(), Ay.end(), e[i].second) - Ay.begin();
        
        for(int x = xs; x <= xe; x++)
        for(int y = ys; y <= ye; y++)
            num[x][y] = 1;
    }
    dfs(0, 0);
    
    long long ans = 0;
    for(int x = 2; x < Ax.size() - 1; x++)
    for(int y = 2; y < Ay.size() - 1; y++){
        if(num[x][y] != 2){
            long long wx = Ax[x] - Ax[x - 1];
            long long wy = Ay[y] - Ay[y - 1];
            
            ans += wx * wy;
        }
    }
    cout << ans << endl;
    return 0;
}