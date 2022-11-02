#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

template <typename T>
struct segtree{
    int n;
    T UNIT;
    vector<T> dat;
    segtree(int n_, T unit){
        UNIT = unit;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(2*n);
        for(int i = 0; i < 2*n; i++) dat[i] = UNIT;
    }

    T calc(T a, T b){
        T ans;
        ans = max(a, b);
        return ans;
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

int N;
int p[200000], idx[200000];
set<int> st[200005];
int root[200000];

const int R = 200004;
ll ans = 0;

// st[root[l]]
void dfs(int l, int r, segtree<int> &sgt){
    // cout << "dfs(" << l << "," << r << ")" << endl;
    if(l > r){
        root[l] = R;
        return;
    }
    if(l == r) {
        root[l] = l;
        st[l].insert(p[l]);
        return;
    }
    if(r == l+1){
        root[l] = l;
        st[l].insert(p[l]);
        st[l].insert(p[r]);
        return;
    }
    int p_max = sgt.query(l, r+1);
    int max_idx = idx[p_max];
    // cout << p_max <<  ' ' << max_idx << endl;
    dfs(l, max_idx-1, sgt);
    dfs(max_idx+1, r, sgt);
    int a = root[l];
    int b = root[max_idx+1];
    if(st[a].size() > st[b].size()) swap(a, b);
    root[l] = b;
    // for(int i : st[a]) cout << i << ' ';
    // cout << endl;
    // for(int i : st[b]) cout << i << ' ';
    // cout << endl;
    for(int i : st[a]){
        if(st[b].count(p_max-i-1)) ans++;
    }
    for(int i : st[a]) st[b].insert(i);
    st[b].insert(p_max);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    segtree<int> sgt(N, 0);
    for(int i = 0; i < N; i++){
        cin >> p[i];
        p[i]--;
        idx[p[i]] = i;
        sgt.update(i, p[i]);
    }
    dfs(0, N-1, sgt);
    cout << ans << endl;
}