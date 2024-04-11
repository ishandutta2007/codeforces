#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma") 
#pragma GCC optimize("unroll-loops")
#define int long long

struct Data {
    int ans, cnto, cntc, anso, ansc;

    Data() {
        ans = cnto = cntc = anso = ansc = 0;
    }

    Data(char c) {
        ans = 0;
        cnto = (c == '(');
        cntc = (c == ')');
        anso = 0;
        ansc = 0;
    }

    Data(int ans_,int o_,int c_,int anso_,int ansc_) {
        ans = ans_;
        cnto = o_;
        cntc = c_;
        anso = anso_;
        ansc = ansc_;
    }
};

// Be carefull. Return type of functions in templated classes
// do not give error if returning wrong datatype
template <typename T>
class SegmentTree { // 0 indexed queries
public:
    vector<T> t;
    int n;

    SegmentTree() {}

    // Creates an empty segment tree
    SegmentTree(int n_) {
        n = n_;
        t.resize(4*n);
    }

    // Create fron arr
    void build(string& a) {
        n = a.size();
        t.resize(4*n);
        build(a, 1, 0, n-1);
    }

    void build(string& a,int v,int l,int r) {
        if (l == r)
            t[v] = Data(a[l]);
        else {
            int mid = (l+r)>>1;
            build(a, v<<1, l, mid);
            build(a, (v<<1)+1, mid+1, r);
            t[v] = combine(t[v<<1], t[(v<<1)+1]);
        }
    }

    T combine(T A,T B) {
        int way1 = A.ans + B.ans + (min(A.cnto - A.anso, B.cntc - B.ansc)<<1);
        int way2 = min(A.cnto, B.cntc)<<1;
        int anso, ansc;
        if (way1 > way2) {
            if (A.cnto - A.anso < B.cntc - B.ansc) {
                anso = A.cnto + B.anso;
                ansc = B.ansc + A.cnto - A.anso + A.ansc;
            }
            else {
                anso = A.anso + B.cntc - B.ansc + B.anso;
                ansc = B.cntc + A.ansc;
            }
        }
        else 
            anso = ansc = min(A.cnto, B.cntc);
        int cnto = A.cnto + B.cnto;
        int cntc = A.cntc + B.cntc;
        int ans = max(way1, way2);
        return Data(ans, cnto, cntc, anso, ansc);
    }

    T query(int l,int r) {
        return query(1, 0, n-1, l, r);
    }

    // tl and tr are segment tree boundaries
    T query(int v,int tl,int tr,int l,int r) {
        // no overlap
        if (tr < l || r < tl)
            return Data();           // NEUTRAL ELEMENT
        
        // completely lies in  (collect all partial overlaps)
        if (l <= tl && tr <= r)
            return t[v];
        int mid = (tl+tr)>>1;
        T left = query(v<<1, tl, mid, l, r);
        T right = query((v<<1)+1, mid+1, tr, l, r);
        return combine(left, right);
    }
};

void solve() {
    string s; cin >> s;
    SegmentTree<Data> X;
    X.build(s);
    int q; cin >> q;
    while (q--) {
        int l,r; cin >> l >> r; --l, --r;
        cout << X.query(l,r).ans << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}