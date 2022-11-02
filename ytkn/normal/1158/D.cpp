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

template<typename T>
inline T add(T a, T b){
    return a+b;
}

template<typename T>
class point {
    public:
    T x, y;
    point<T>(T x, T y): x(x), y(y){};
    point<T>(): x(0), y(0){};
    point<T> operator + (point<T> p){
        return point<T>(add(x, p.x), add(y, p.y));
    };
    point<T> operator - (point<T> p){
        return point<T>(add(x, -p.x), add(y, -p.y));
    };
    point<T> operator * (T d){
        return point<T>(x*d, y*d);
    };
    T dot(point<T> p){
        return add(x*p.x, y*p.y);
    };
    T det(point<T> p){
        return add(x*p.y, -y*p.x);
    };
};


template<typename T>
bool comp_p(point<T> p, point<T> q){
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

template<typename T>
vector<int> convex_hull(vector<point<T>> ps){
    int n = ps.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j){ return comp_p<T>(ps[i], ps[j]); });
    sort(ps.begin(), ps.end(), comp_p<T>);
    vector<point<T>> ans;
    vector<int> ans_indices;
    for(int i = 0; i < n; i++){
        while(ans.size() > 1 && (ans.back()-ans[ans.size()-2]).det(ps[i] - ans.back()) <= 0) {
            ans.pop_back();
            ans_indices.pop_back();
        }
        ans.push_back(ps[i]);
        ans_indices.push_back(indices[i]);
    }
    int bottom_size = ans.size();
    for(int i = n-2; i >= 0; i--){
        while(ans.size() > bottom_size && (ans.back()-ans[ans.size()-2]).det(ps[i] - ans.back()) <= 0) {
            ans.pop_back();
            ans_indices.pop_back();
        }
        ans.push_back(ps[i]);
        ans_indices.push_back(indices[i]);
    }
    ans.pop_back();
    ans_indices.pop_back();
    return ans_indices;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<point<ll>> p;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        p.push_back(point<ll>(x, y));
    }
    string s; cin >> s;
    vector<int> ans;
    vector<bool> used(n);
    auto ch = convex_hull(p);
    int nx = -1;
    used[ch[0]] = true;
    ans.push_back(ch[0]);
    if(s[0] == 'L'){
        nx = ch[1];
    }else{
        nx = ch.back();
    }
    for(int k = 1; k < n; k++){
        if(k == n-2){
            ans.push_back(nx);
            used[nx] = true;
            for(int i = 0; i < n; i++){
                if(!used[i]) ans.push_back(i);
            }
            break;
        }
        vector<point<ll>> points;
        vector<int> indices;
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            points.push_back(p[i]);
            indices.push_back(i);
        }
        auto ch = convex_hull(points);
        int m = ch.size();
        auto idx = [&](){
            for(int i = 0; i < m; i++){
                if(indices[ch[i]] == nx) return i;
            }
            assert(false);
        }();
        ans.push_back(nx);
        used[nx] = true;
        if(s[k] == 'L'){
            int ii = (idx+1)%m;
            nx = indices[ch[ii]];
        }else{
            int ii = (idx-1+m)%m;
            nx = indices[ch[ii]];
        }
    }
    for(int x: ans) cout << x+1 << ' ';
    cout << endl;
}