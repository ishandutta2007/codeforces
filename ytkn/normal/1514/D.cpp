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
#include <cmath>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

struct Mo {
    vector<int> left, right, index; // the interval's left, right, index
    vector<bool> v;
    int window;
    int nl, nr, ptr;
    
    Mo(int n) : window((int)sqrt(n)), nl(0), nr(0), ptr(0), v(n, false) { }
    
    /* push */
    void push(int l, int r) { left.push_back(l), right.push_back(r); }
    
    /* sort intervals */
    void build() {
        index.resize(left.size());
        iota(index.begin(), index.end(), 0);
        sort(begin(index), end(index), [&](int a, int b)
        {
            if (left[a] / window != left[b] / window) return left[a] < left[b];
            return bool((right[a] < right[b]) ^ (left[a] / window % 2));
        });
    }
    
    /* extend-shorten */
    void extend_shorten(int id) {
        v[id].flip();
        if (v[id]) insert(id);
        else erase(id);
    }
    
    /* next id of interval */
    int next() {
        if (ptr == index.size()) return -1;
        int id = index[ptr];
        while (nl > left[id]) extend_shorten(--nl);
        while (nr < right[id]) extend_shorten(nr++);
        while (nl < left[id]) extend_shorten(nl++);
        while (nr > right[id]) extend_shorten(--nr);
        return index[ptr++];
    }
    
    /* insert, erase (to be set appropriately) */
    void insert(int id);
    void erase(int id);
};

int A[300100], res[300100];
int l[300100], r[300100];
int cnt[300100], hist[300100];
int num_kind = 0, mode = 0;

void Mo::insert(int id) {
    int val = A[id];
    if (cnt[val] == 0) ++num_kind;
    --hist[cnt[val]];
    ++cnt[val];
    ++hist[cnt[val]];
    mode = max(mode, cnt[val]);
}

void Mo::erase(int id) {
    int val = A[id];
    --hist[cnt[val]];
    if(cnt[val] == mode && hist[cnt[val]] == 0) --mode;
    --cnt[val];
    ++hist[cnt[val]];
    if (cnt[val] == 0) --num_kind;
}

int main() {
    int n, q; cin >> n >> q;
    mode = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    Mo mo(n);
    for(int i = 0; i < q; i++) {
        cin >> l[i] >> r[i]; l[i]--;
        mo.push(l[i], r[i]);
    }
    mo.build();
    for(int i = 0; i < q; i++) {
        int x = mo.next();
        res[x] = mode;
        // cout << mo.next() << ' ' << mode << endl;
        // cout << x << ':' << res[x] << endl;
    }
    // cout << endl;
    for(int i = 0; i < q; i++) {
        int len = r[i]-l[i];
        int rem = len-res[i];
        // cout << len << ' ' << res[i] << endl;
        cout << max(1, res[i]-rem) << endl;
    }
}