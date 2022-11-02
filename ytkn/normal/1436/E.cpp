#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>
#include <random>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

int n;
int a[100005];
int nx[100005][20];
int next_zero[100005];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
}

// void init(){
//     vector<int> pre(n+1, n);
//     for(int i = n-1; i >= 0; i--){
//         nx[i][0] = pre[a[i]+1];
//         pre[a[i]] = i;
//         next_zero[i] = pre[0];
//     }
//     for(int j = 1; j < 20; j++){
//         for(int i = 0; i < n; i++){
//             if(nx[i][j-1] == n) nx[i][j] = n;
//             else nx[i][j] = nx[nx[i][j-1]][j-1];
//         }
//     }
// }

// int go_right(int i, int x){
//     int cur = i;
//     for(int j = 0; j < 20; j++){
//         if(cur == n) return n;
//         cur = nx[cur][j];
//     }
//     return cur;
// }

template <typename T>
struct segtree{
    int n;
    T UNIT;
    vector<T> dat;
    T (*calc)(T, T);

    segtree(int n_, T unit, T (*_calc)(T, T)){
        UNIT = unit;
        calc = _calc;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(2*n);
        for(int i = 0; i < 2*n; i++) dat[i] = UNIT;
    }

    void insert(int k, T a){
        dat[k+n-1] = a;
    }
    void update_all(){
        for(int i = n-2; i >= 0; i--){
            dat[i] = calc(dat[i*2+1], dat[i*2+2]);
        }
    }
    //k(0-indexed)a
    void update(int k, T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = calc(dat[k*2+1], dat[k*2+2]);
        }
    }

    //[a, b)
    //[a, b]query(a, b+1)
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return UNIT;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return calc(vl, vr);
        }
    }
};

const int INF = 1e9;

bool all_zero(){
    for(int i = 0; i < n; i++){
        if(a[i] != 0) return false;
    }
    return true;
}

// 0-indexed
void solve(){
    if(all_zero()){
        cout << 1 << endl;
        return;
    }
    vector<bool> find(n+1, false);
    segtree<int> sgt(n, -INF, [](int a, int b){ return max(a, b); });
    for(int i = 0; i < n; i++) sgt.update(i, n);
    for(int i = n-1; i >= 0; i--){
        if(a[i] != 0){
            int r = sgt.query(a[i], a[i]+1);
            if(sgt.query(0, a[i]) < r) find[a[i]] = true;
        }
        sgt.update(a[i], i);
    }
    for(int i = 1; i < n; i++){
        int r = sgt.query(i, i+1);
        if(sgt.query(0, i) < r) find[i] = true;
    }
    if(sgt.query(0, n) < n) find[n] = true;
    for(int i = 1; i <= n; i++){
        if(!find[i]) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << n+2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}