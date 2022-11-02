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

int n, m, q;
bool ok[1000][1000];

bool in(int i, int j){
    return 0 <= i && i < n && 0 <= j &&  j < m;
}

ll count(int i, int j, int dx, int dy){
    if(in(i+dx, j+dy) && ok[i+dx][j+dy]) return count(i+dx, j+dy, dy, dx)+1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ok[i][j] = true;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans++;
            int dx = n-1-i, dy = m-1-j;
            if(dx > dy) swap(dx, dy);
            if(dx == dy){
                ans += 4*dx;
            }else{
                ans += 4*dx+1;
            }
        }
    }
    // cout << ans << endl;
    while(q--){
        int x, y; cin >> x >> y; x--; y--;
        // cout << x << ' ' << y << ' ' << ok[x][y] << endl;
        // cout << count(x, y, -1, 0) << ' ' << count(x, y, 0, 1) << ' ' << count(x, y, 0, -1) << ' ' << count(x, y, 1, 0)+1 << endl;
        ll d = (count(x, y, -1, 0)+1)*(count(x, y, 0, 1)+1) + (count(x, y, 0, -1)+1)*(count(x, y, 1, 0)+1)-1;
        if(ok[x][y]){
            ans -= d;
        }else{
            ans += d;
        }
        ok[x][y] = !ok[x][y];
        cout << ans << endl;
    }

}