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

int dist(P p1, P p2){
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    auto a = vec2d(2, n, 0);
    auto b = vec2d(2, n, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> b[i][j];
            if(a[i][j] == b[i][j]) {
                a[i][j] = 0;
                b[i][j] = 0;
            }
        }
    }
    ll ans = 0;
    vector<int> cnt(2);
    for(int j = 0; j < n; j++){
        ans += abs(cnt[0]+cnt[1]);
        cnt[0] += a[0][j];
        cnt[1] += a[1][j];

        cnt[0] -= b[0][j];
        cnt[1] -= b[1][j];

        if(cnt[0] > 0 && cnt[1] < 0){
            int x = min(abs(cnt[0]), abs(cnt[1]));
            ans += x;
            cnt[0] -= x;
            cnt[1] += x;
        }else if(cnt[0] < 0 && cnt[1] > 0){
            int x = min(abs(cnt[0]), abs(cnt[1]));
            ans += x;
            cnt[0] += x;
            cnt[1] -= x;
        }
        
    }
    if(cnt[0]+cnt[1] > 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}