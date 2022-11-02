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
#include <stack>

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
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
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

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    vector<int> l(n), r(n);
    vector<int> v = {0, m};
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i]; l[i]--;
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    auto cp = Compress<int>(v);
    int mm = cp.size();
    vector<vector<int>> adds(mm+1);
    vector<vector<int>> erases(mm+1);
    vector<int> len(mm-1);
    for(int i = 0; i < mm-1; i++){
        len[i] = cp.data[i+1]-cp.data[i];
    }
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        int li = cp[l[i]], ri = cp[r[i]];
        adds[li].push_back(i);
        erases[ri].push_back(i);
    }
    vector<int> popcount(1<<8);
    for(int s = 0; s < (1<<8); s++){
        for(int i = 0; i < 8; i++){
            if(s&(1<<i)) popcount[s]++;
        }
    }
    int all_bits = (1<<8)-1;
    vector<ll> pre(1<<8), cur(1<<8);
    stack<int> remaining;
    for(int i = 7; i >= 0; i--) remaining.push(i);
    vector<int> indices(n);
    int mask = 0;
    for(int i = 0; i < mm; i++){
        for(int j: erases[i]){
            mask ^= 1<<indices[j];
            remaining.push(indices[j]);
        }
        for(int s = 0; s <= all_bits; s++){
            chmax(pre[s&mask], pre[s]);
        }
        int extra_bits = 0;
        for(int j: adds[i]){
            indices[j] = remaining.top(); remaining.pop();
            extra_bits ^= 1<<indices[j];
        }
        assert((mask&extra_bits) == 0);
        for(int s = mask; s >= 0; s = (s-1)&mask){
            for(int t = extra_bits; t >= 0; t = (t-1)&extra_bits){
                int u = s+t;
                assert((s&t) == 0);
                ll additional = popcount[u]&1 ? len[i] : 0;
                chmax(cur[u], pre[s]+additional);
                if(t == 0) break;
            }
            if(s == 0) break;
        }
        mask ^= extra_bits;
        swap(pre, cur);
    }
    cout << *max_element(pre.begin(), pre.end()) << endl;
}