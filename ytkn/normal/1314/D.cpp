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
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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
const ll inf = 1e18;
const ll ans = inf;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    auto a = vec2d(n, n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            // a[i][j] = randint(0, 100);
        }
    }
    auto min_route = vec2d(n, n, vector<P>());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i == k || j == k) continue;
                int cost = a[i][k]+a[k][j];
                min_route[i][j].push_back(P(cost, k));
            }
            sort(min_route[i][j].begin(), min_route[i][j].end());
            while(min_route[i][j].size() > 5) min_route[i][j].pop_back();
        }
    }
    int m = k/2;
    vector<int> v = {0};
    vector<bool> used(n);
    ll ans = inf;
    function<void(int)> dfs = [&](int depth){
        if(depth == m-1){
            for(int x: v) used[x] = true;
            v.push_back(0);
            ll tmp = 0;
            for(int i = 0; i <= m-1; i++){
                int s = v[i], t = v[i+1];
                bool ok = false;
                for(auto [dist, u]: min_route[s][t]){
                    if(used[u]) continue;
                    tmp += dist;
                    ok = true;
                    break;
                }
                if(!ok) {
                    for(int x: v) used[x] = false;
                    v.pop_back();
                    return;
                }
            }
            chmin(ans, tmp);
            for(int x: v) used[x] = false;
            v.pop_back();
            return;
        }
        for(int nx = 0; nx < n; nx++){
            v.push_back(nx);
            dfs(depth+1);
            v.pop_back();
        }
    };
    dfs(0);
    cout << ans << endl;
}