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

const int inf = 1e9;

pair<int, int> simulate(vector<int> v, vector<int> winner){
    assert(v.size() == 4);
    assert(winner.size() == 3);
    int p = -1, q = -1, r = -1, s = -1;
    int cnt = max(v[0], v[1]);
    if(winner[0] == 0){
        p = v[0];
        q = v[1];
    }else{
        p = v[1];
        q = v[0];
    }
    cnt += max(v[2], v[3]);
    if(winner[1] == 0){
        r = v[2];
    }else{
        r = v[3];
    }
    cnt += max(q, r);
    if(winner[2] == 0){
        s = q;
    }else{
        s = r;
    }
    int nx = p+(s<<1);
    return make_pair(nx, cnt);
}

int pre_calc[4][4][4];

void init(){
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            for(int c = 0; c < 4; c++) pre_calc[a][b][c] = -inf;
            for(int winner = 0; winner < 8; winner++){
                vector<int> u(3);
                for(int i = 0; i < 3; i++){
                    if(winner&(1<<i)) u[i] = 1;
                }
                vector<int> v(4);
                if(a&1) v[0] = 1;
                if(a&2) v[2] = 1;
                if(b&1) v[1] = 1;
                if(b&2) v[3] = 1;
                auto [nx, cnt] = simulate(v, u);
                chmax(pre_calc[a][b][nx], cnt);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, k; cin >> n >> k;
    vector<int> a(k);
    vector<bool> ok(1<<n);
    for(int i = 0; i < k; i++){
        cin >> a[i]; a[i]--;
        ok[a[i]] = true;
    }
    auto pre = vec2d(1<<(n-1), 4, -inf);
    for(int x = 0; x < (1<<(n-1)); x++){
        int x1 = 2*x, x2 = 2*x+1;
        if(ok[x1] && ok[x2]){
            pre[x][3] = 1;
        }else if(ok[x1] || ok[x2]){
            pre[x][2] = 1;
            pre[x][1] = 1;
        }else{
            pre[x][0] = 0;
        }
    }
    for(int i = n-1; i >= 1; i--){
        int m = 1<<(i-1);
        auto cur = vec2d(m, 4, -inf);
        for(int x = 0; x < m; x++){
            int x1 = x*2, x2 = x*2+1;
            for(int a = 0; a < 4; a++){
                if(pre[x1][a] < 0) continue;
                for(int b = 0; b < 4; b++){
                    if(pre[x2][b] < 0) continue;
                    for(int c = 0; c < 4; c++){
                        if(pre_calc[a][b][c] < 0) continue;
                        chmax(cur[x][c], pre[x1][a]+pre[x2][b]+pre_calc[a][b][c]);
                    }
                }
            }
        }
        pre = cur;
    }
    int ans = -inf;
    for(int i = 0; i < 4; i++){
        int x = i == 0 ? 0 : 1;
        chmax(ans, pre[0][i]+x);
    }
    cout << ans << endl;
}