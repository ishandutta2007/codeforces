//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

#ifdef LOCAL
const int MN = 600;
bool g[MN][MN];
#endif

int n;
void first() {
#ifdef LOCAL
/*    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a][b] = g[b][a] = true;
    }*/
    cin >> n;
    for (int i = 0; i < n / 2; i++) {
        for (int j = n / 2; j < n; j++) {
            g[i][j] = g[j][i] = true;
        }
    }    
    g[n - 2][n - 1] = g[n - 1][n - 2] = true;
#else
    cin >> n;
#endif
}

void pr_array(V<int> v) {
    int k = int(v.size());
    for (int i = 0; i < k; i++) {
        cout << v[i] + 1;
        if (i != k - 1) cout << " ";
    }
    cout << endl;
}

int qc = 0;
int query(V<int> v) {
    int k = int(v.size());
    int x = 0;
#ifdef LOCAL
    qc++;
    if (qc % 1000 == 0) {
        cerr << qc << endl;
    }
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (g[v[i]][v[j]]) x++;
        }
    }
#else
    cout << "? " << k << endl;
    pr_array(v);
    cin >> x;
#endif
    return x;
}

V<int> find_edge(int s, V<int> pred) {
    V<int> spred = pred;
    spred.push_back(s);

    int m = int(pred.size());
    if (m == 0) return {};
    if (query(spred) == query(pred)) return {};
    if (m == 1) return {pred[0]};

    V<int> res1 = find_edge(s, {pred.begin(), pred.begin() + m / 2});
    V<int> res2 = find_edge(s, {pred.begin() + m / 2, pred.end()});
    res1.insert(res1.end(), res2.begin(), res2.end());
    return res1;
}
int find_one(int s, V<int> pred) {
    V<int> spred = pred;
    spred.push_back(s);

    int m = int(pred.size());
    if (m == 0) return -1;
    if (query(spred) == query(pred)) return -1;
    if (m == 1) return pred[0];

    int res = find_one(s, {pred.begin(), pred.begin() + m / 2});
    if (res != -1) return res;
    return find_one(s, {pred.begin() + m / 2, pred.end()});
}

int main() {
    first();
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    V<int> col(n, -1);
    V<int> prev(n, -1);
    for (int st = 0; st < n; st++) {
        if (col[st] != -1) continue;
        queue<int> q;
        q.push(st);
        col[st] = 0;
        while (q.size()) {
            int p = q.front(); q.pop();
            /*
            V<int> pred;
            for (int i = 0; i < n; i++) {
                if (i != p && col[i] != 1 - col[p]) pred.push_back(i);
            }
            random_shuffle(pred.begin(), pred.end());
            V<int> edges = find_edge(p, pred);
            for (int d: edges) {*/
            while (true) {
                V<int> pred;
                for (int i = 0; i < n; i++) {
                    if (i != p && col[i] != 1 - col[p]) pred.push_back(i);
                }
                int d = find_one(p, pred);
                if (d == -1) break;
                if (col[d] != -1) {
                    V<int> l1, l2;
                    while (d != -1) {
                        l1.push_back(d);
                        d = prev[d];
                    }
                    while (p != -1) {
                        l2.push_back(p);
                        p = prev[p];
                    }
                    while (l1.size() && l2.size() && l1.back() == l2.back()) {
                        l1.pop_back();
                        l2.pop_back();
                    }                    
                    if (l1.empty()) swap(l1, l2);
                    auto l = l1;
                    l.push_back(prev[l1.back()]);
                    reverse(l2.begin(), l2.end());
                    l.insert(l.end(), l2.begin(), l2.end());

                    cout << "N " << int(l.size()) << endl;
                    pr_array(l);
                    exit(0);
                }
                col[d] = 1 - col[p];
                prev[d] = p;
                q.push(d);                
            }
        }        
    }

    V<int> c0;
    for (int i = 0; i < n; i++) {
        if (col[i] == 0) c0.push_back(i);
    }
    cout << "Y " << c0.size() << endl;
    pr_array(c0);
    return 0;
}