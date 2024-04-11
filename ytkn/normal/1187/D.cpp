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
        ans = min(a, b);
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

int a[300000];
int b[300000];
const int INF = 1e+9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int _d = 0; _d < t; _d++){
        int n;
        cin >> n;
        vector<priority_queue<int, vector<int>, greater<int>>> pq(n+1);
        segtree<int> sgt(n, INF);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sgt.insert(i,a[i]);
            pq[a[i]].push(i);
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        sgt.update_all();
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(pq[b[i]].empty()){
                ok = false;
                break;
            }
            int top = pq[b[i]].top();
            int m = sgt.query(0, top+1);
            if(b[i] > m) {
                ok = false;
                break;
            }
            sgt.update(top, INF);
            pq[b[i]].pop();
        }
        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}