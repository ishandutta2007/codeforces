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

template<typename T>
class Mo{
    public:
    vector<int> l, r;
    int bucket_size;
    Mo(int bucket_size): l(vector<int>()), r(vector<int>()), bucket_size(bucket_size) {}
    void add_query(int l_, int r_){
        l.push_back(l_);
        r.push_back(r_);
    }
    template<typename ADD, typename DEL, typename GET_ANS>
    vector<T> solve(ADD add, DEL del, GET_ANS get_ans){
        int sz = l.size();
        vector<int> ord(sz);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](const int a, const int b){
            const int c = l[a] / bucket_size, d = l[b] / bucket_size;
            return (c == d) ? ((c & 1) ? (r[b] < r[a]) : (r[a] < r[b])) : (c < d);
        });
        int li = 0, ri = 0;
        vector<T> ans(sz);
        for(const int i : ord){
            while(li > l[i]) add(--li);
            while(ri < r[i]) add(ri++);
            while(li < l[i]) del(li++);
            while(ri > r[i]) del(--ri);
            ans[i] = get_ans();
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<P> ps;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        l[i] = sum;
        r[i] = sum+k;
        sum += k;
        vector<int> x(k), y(k);
        for(int j = 0; j < k; j++){
            cin >> x[j] >> y[j];
        }
        for(int j = 0; j < k; j++){
            int dx = x[(j+1)%k]-x[j];
            int dy = y[(j+1)%k]-y[j];
            int g = gcd(dx, dy);
            ps.push_back(P(dx/g, dy/g));
        }
    }
    auto cp = Compress<P>(ps);
    vector<int> indices(sum);
    for(int i = 0; i < sum; i++){
        indices[i] = cp[ps[i]];
    }
    vector<int> cnt(cp.size());
    int ans = 0;
    auto add = [&](int i){
        if(cnt[indices[i]] == 0) ans++; 
        cnt[indices[i]]++;
    };
    auto del = [&](int i){
        if(cnt[indices[i]] == 1) ans--; 
        cnt[indices[i]]--;
    };
    auto get_ans = [&](){
        return ans;
    };
    Mo<int> mo(max((int)sqrt(sum), 1));
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int li, ri; cin >> li >> ri; li--; ri--;
        mo.add_query(l[li], r[ri]);
    }
    auto w = mo.solve(add, del, get_ans);
    print_vector(w, '\n');
}