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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> x(n), y(n);
    set<P> st;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        st.insert(P(x[i], y[i]));
    }
    map<P, int> dist;
    map<P, P> start;
    priority_queue<T, vector<T>, greater<T>> que;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            int xx = x[i]+dx[j];
            int yy = y[i]+dy[j];
            P p(xx, yy);
            if(st.count(p) == 0) {
                dist[p] = 0;
                que.push(T(0, xx, yy));
                start[p] = p;
            }
        }
    }
    while(!que.empty()){
        auto [d, x, y] = que.top(); que.pop();
        for(int i = 0; i < 4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            P pp(xx, yy);
            if(st.count(pp) == 0) continue;
            if(dist.count(pp) == 0 || dist[pp] > d+1){
                dist[pp] = d+1;
                start[pp] = start[P(x, y)];
                que.push(T(d+1, xx, yy));
            }
        }
    }
    for(int i = 0; i < n; i++){
        auto [xx, yy] = start[P(x[i], y[i])];
        cout << xx << ' ' << yy << endl;
    }
}