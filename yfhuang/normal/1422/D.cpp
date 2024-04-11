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

int n, m;

const int maxn = 1e5 + 5;
pi v[maxn], h[maxn];
pi a[maxn];

ll dis[maxn];
int sx, sy, fx, fy;

void bfs(){
    queue<int> q;
    q.push(0);
    for(int i = 0;i <= m;i++){
        dis[i] = 1e18;
    }
    dis[0] = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        int x = a[p].fi;
        int y = a[p].se;
        int to;
        int L = lower_bound(v, v + 1 + m, mp(x, p)) - v;
        L--;
        if(L >= 0){
            to = v[L].se;
            if(dis[to] > dis[p] + abs(x - v[L].fi)){
                dis[to] = dis[p] + abs(x - v[L].fi);
                q.push(to);
            }
        }
        int R = upper_bound(v, v + 1 + m, mp(x, p)) - v;
        if(R <= m){
            to = v[R].se;
            if(dis[to] > dis[p] + abs(x - v[R].fi)){
                dis[to] = dis[p] + abs(x - v[R].fi);
                q.push(to);
            }
        } 
        int U = lower_bound(h, h + 1 + m, mp(y, p)) - h;
        U--;
        if(U >= 0){
            to = h[U].se;
            if(dis[to] > dis[p] + abs(y - h[U].fi)){
                dis[to] = dis[p] + abs(y - h[U].fi);
                q.push(to);
            }
        }
        int D = upper_bound(h, h + 1 + m, mp(y, p)) - h;
        if(D <= m){
            to = h[D].se;
            if(dis[to] > dis[p] + abs(y - h[D].fi)){
                dis[to] = dis[p] + abs(y - h[D].fi);
                q.push(to);
            }
        } 
    }
    ll ans = 1e18;
    for(int i = 0;i <= m;i++){
        ans = min(ans, dis[i] + abs(fx - a[i].fi) + abs(fy - a[i].se)); 
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;
    for(int i = 1;i <= m;i++){
        cin >> a[i].fi >> a[i].se;
        v[i] = mp(a[i].fi, i);
        h[i] = mp(a[i].se, i);
    }
    a[0] = mp(sx, sy);
    v[0] = mp(sx, 0);
    h[0] = mp(sy, 0);
    sort(v, v + 1 + m);
    sort(h, h + 1 + m);
    bfs();
    return 0;
}