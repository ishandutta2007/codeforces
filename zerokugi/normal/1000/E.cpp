#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i, x) for(int i=0;i<(int)(x);i++)
#define REPS(i, x) for(int i=1;i<=(int)(x);i++)
#define RREP(i, x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i, x) for(int i=((int)(x));i>0;i--)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i, c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define __builtin_popcount __builtin_popcountll

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
    os << "[";
    FOR(it, t) {
        if (it != t.begin()) os << ",";
        os << *it;
    }
    os << "]";
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &t) {
    os << "{";
    FOR(it, t) {
        if (it != t.begin()) os << ",";
        os << *it;
    }
    os << "}";
    return os;
}

template<class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) { return os << "(" << t.first << "," << t.second << ")"; }

template<class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}

template<class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first - t.first, s.second - t.second);
}

const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;

template <typename T=int>
struct Zipper{
    vector<T> dec;
    unordered_map<T, int> enc;
    Zipper(){}
    void add(T t){dec.pb(t);}
    size_t size(){return dec.size();}
    void compile(){
        sort(ALL(dec)); UNIQUE(dec);
        REP(i, dec.size()) enc[dec[i]] = i;
    }
    T operator[](int i){return dec[i];}
    int operator()(T t){return enc[t];}
    int lb(T t){return lower_bound(ALL(dec), t) - dec.begin();}
    int ub(T t){return upper_bound(ALL(dec), t) - dec.begin();}
};

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n, -1){}
    bool unite(int x, int y) {
        if ((x = root(x)) != (y = root(y))){
            if (d[y] < d[x]) swap(x, y);
            d[x] += d[y]; d[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y){return root(x) == root(y);}
    int root(int x){return d[x] < 0 ? x : d[x] = root(d[x]);}
    int size(int x=-1) {return x<0 ? d.size() : -d[root(x)];}
};


UnionFind BCC(vector<vector<int>> &g){
    vi steps(g.size());
    vi visited(g.size());
    UnionFind uf(g.size());

    function<int(int, int, int)> BCCdfs = [&](int r, int p, int step){
        if(visited[r] >= 1) return steps[r];
        steps[r] = step;
        visited[r] ++;
        int minstep = INF;
        FOR(v, g[r])if(*v!=p){
                int ret = BCCdfs(*v, r, step+1);
                if(ret <= step) uf.unite(r, *v);
                chmin(minstep, ret);
            }
        return minstep;
    };

    REP(i, g.size()){
        if(!visited[i]) BCCdfs(i, -1, 0);
        sort(ALL(g[i]));
        REP(j, (int)g[i].size()-1) if(g[i][j] == g[i][j+1]) uf.unite(i, g[i][j]);
    }
    return uf;
}

pair<vector<vi>, vi> makeNewGraph(const vector<vi> &g, UnionFind &uf){
    int n = g.size();
    Zipper<int> zip;
    REP(i, n)if(uf.root(i) == i) zip.add(i);
    zip.compile();
    vector<vi> ng(zip.size());
    REP(i, n) for(int v : g[i]) if(uf.root(i) != uf.root(v)) ng[zip(uf.root(i))].push_back(zip(uf.root(v)));
    REP(i, zip.size()) sort(ALL(ng[i])), UNIQUE(ng[i]);
    vi proj(n);
    REP(i, n) proj[i] = zip(uf.root(i));
    return mp(ng, proj);
}
int n, m;

typedef pair<int, int> Result;
Result visit(int p, int v, const vector<vi> &g) {
    Result r(0, v);
    for(int e : g[v]) if (e != p) {
            Result t = visit(v, e, g);
            t.first += 1;
            if (r.first < t.first) r = t;
        }
    return r;
}
int diameter(const vector<vi> &g) {
    Result r = visit(-1, 0, g);
    Result t = visit(-1, r.second, g);
    return t.first; // (r.second, t.second) is farthest pair
}

int main(int argc, char *argv[]) {
    cin >> n >> m;
    vector<vi> g(n);
    REP(i, m) {
        int u, v;
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto uf = BCC(g);
    auto ng = makeNewGraph(g, uf).first;
    cout << diameter(ng) << endl;
    return 0;
}