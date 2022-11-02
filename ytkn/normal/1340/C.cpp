#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

using P = pair<int, int>;
using T = tuple<int, int, int>;
const ll inf = 1e18;

ll dist[10005][1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> d;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        d.push_back(x);
    }
    sort(d.begin(), d.end());
    if(d.back() != n) d.push_back(n);
    m = d.size();
    int g, r; cin >> g >> r;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < g; j++){
            dist[i][j] = inf;
        }
    }
    deque<P> dq;
    if(d[0] < g){
        dist[0][d[0]] = 0;
        dq.push_back(P(0, d[0]));
    }else if(d[0] == g){
        dist[0][0] = 1;
        dq.push_back(P(0, 0));
    }else{
        cout << -1 << endl;
        return 0;
    }
    while(!dq.empty()){
        auto [i, j] = dq.front(); dq.pop_front();
        if(i == m-1){
            continue;    
        }
        if(i > 0){
            int dd = d[i]-d[i-1];
            if(j+dd < g){
                if(chmin(dist[i-1][j+dd], dist[i][j])) dq.push_front(P(i-1, j+dd));
            }else if(j+dd == g){
                if(chmin(dist[i-1][0], dist[i][j]+1)) dq.push_back(P(i-1, 0));
            } 
        }
        if(i+1 < m){
            int dd = d[i+1]-d[i];
            if(j+dd < g){
                if(chmin(dist[i+1][j+dd], dist[i][j])) dq.push_front(P(i+1, j+dd));
            }else if(j+dd == g){
                if(chmin(dist[i+1][0], dist[i][j]+1)) {
                    dq.push_back(P(i+1, 0));
                }
            } 
        }
    }
    ll ans = inf;
    if(dist[m-1][0] != inf) {
        ans = dist[m-1][0]*(ll)(g+r)-r;
    }
    for(int i = 1; i < g; i++) {
        if(dist[m-1][i] == inf) continue;
        chmin(ans, dist[m-1][i]*(ll)(g+r)+i);
    }
    if(ans == inf){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}