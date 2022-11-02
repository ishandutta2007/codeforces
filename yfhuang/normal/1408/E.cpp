#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int m, n;
const int maxn = 1e5 + 5;

int a[maxn], b[maxn];

int fa[maxn * 2];

int Find(int x){
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for(int i = 1;i <= m;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> b[i];
    }
    vector<pair<int, pi>> edges;
    for(int i = 1;i <= m;i++){
        int s;
        cin >> s;
        for(int j = 1;j <= s;j++){
            int v;
            cin >> v;
            edges.push_back(mp(a[i] + b[v], mp(i, v)));
        }
    }
    sort(edges.begin(), edges.end());
    for(int i = 1;i <= n + m;i++){
        fa[i] = i;
    }
    long long sum = 0;
    for(int i = edges.size() - 1;i >= 0;i--){
        auto edge = edges[i];
        int w = edge.fi;
        int u = edge.se.fi;
        int v = edge.se.se;
        v += m; 
        int fx = Find(u);
        int fy = Find(v);
        if(fx != fy){
            fa[fx] = fy;
        }else{
            sum += w;
        }
    }
    cout << sum << endl;
    return 0;
}