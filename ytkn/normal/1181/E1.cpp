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
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        data = data_;
        sort(begin(data), end(data));
        data.erase(unique(begin(data), end(data)), end(data));
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

int a[1000], b[1000], c[1000], d[1000];

bool solve(const vector<int> &v){
    // print_vector(v);
    if(v.size() <= 1) return true;
    {// 
        vector<int> x;
        for(int i: v) {
            x.push_back(a[i]);
            x.push_back(c[i]);
        }
        auto cp = Compress<int>(x);
        int m = cp.size();
        vector<int> add(m), del(m);
        for(int i: v){
            add[cp[a[i]]]++;
            del[cp[c[i]]]++;
        }
        int cnt = add[0];
        for(int x = 1; x+1 < m; x++){
            cnt -= del[x];
            if(cnt == 0){
                vector<int> vl, vr;
                for(int i: v){
                    if(cp[a[i]] >= x) vr.push_back(i);
                    else vl.push_back(i);
                }
                // cout << "X" << endl;
                return solve(vl) && solve(vr);
            }
            cnt += add[x];
        }
    }
    // 
    {
        vector<int> y;
        for(int i: v) {
            y.push_back(b[i]);
            y.push_back(d[i]);
        }
        auto cp = Compress<int>(y);
        int m = cp.size();
        vector<int> add(m), del(m);
        for(int i: v){
            add[cp[b[i]]]++;
            del[cp[d[i]]]++;
        }
        int cnt = add[0];
        for(int x = 1; x+1 < m; x++){
            cnt -= del[x];
            if(cnt == 0){
                vector<int> vl, vr;
                for(int i: v){
                    if(cp[b[i]] >= x) vr.push_back(i);
                    else vl.push_back(i);
                }
                // cout << "Y:" << cp.data[x] << endl;
                return solve(vl) && solve(vr);
            }
            cnt += add[x];
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    if(solve(v)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}