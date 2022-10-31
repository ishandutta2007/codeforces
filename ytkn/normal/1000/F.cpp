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

/**
 * verified: https://codeforces.com/contest/1195/submission/161851257
 */ 
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

int n;
const int N = 500000;
int a[N];
int cnt[N];
int cnt_bucket[1000];
int bucket_size = 0;

int get_ans(){
    for(int i = 0; i <= (n-1)/bucket_size; i++){
        if(cnt_bucket[i] > 0){
            for(int x = i*bucket_size; x < (i+1)*bucket_size; x++){
                if(cnt[x] == 1) return x+1;
            }
            assert(false);
        }
    }
    return 0;
}

void add(int i){
    int bucket_num = a[i]/bucket_size;
    if(cnt[a[i]] == 1) {
        cnt_bucket[bucket_num]--;
    }
    cnt[a[i]]++;
    if(cnt[a[i]] == 1) {
        cnt_bucket[bucket_num]++;
    }
}

void del(int i){
    int bucket_num = a[i]/bucket_size;
    if(cnt[a[i]] == 1) {
        cnt_bucket[bucket_num]--;
    }
    cnt[a[i]]--;
    if(cnt[a[i]] == 1) {
        cnt_bucket[bucket_num]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
    }
    int q; cin >> q;
    bucket_size = sqrt(n);
    Mo<int> mo(bucket_size);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r; l--;
        mo.add_query(l, r);
    }
    auto ans = mo.solve(add, del, get_ans);
    print_vector(ans, '\n');
}