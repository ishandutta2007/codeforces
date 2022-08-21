#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define fs first
#define sc second
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
template <class T, class U> void chmin(T& t, const U& u) { if (u < t) t = u; }
template <class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,M; cin >> N >> M;
    VV<int> a(N,V<int>(M));
    rep(i,M) rep(j,N) cin >> a[j][i];
    show(a);
    int mn = M; V<int> ans; rep(i,M) ans.pb(i);
    rep(i,N-1){
        using P = pair<int,int>;
        V<P> v(M);
        rep(j,M) v[j] = P(a[i][j] - a[N-1][j],j);
        sort(all(v),greater<P>());
        show(v);
        int sum = 0;
        rep(j,M){
            sum += v[j].fs;
            if(sum >= 0){
                if(mn > M-1-j){
                    mn = M-1-j;
                    ans.clear();
                    for(int k=j+1;k<M;k++) ans.pb(v[k].sc);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(int v: ans) cout << v+1 << " ";
    cout << endl;
}