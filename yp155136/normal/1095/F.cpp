#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct DJS {
    static const int N = 200006;
    int p[N];
    void init() {
        for (int i=0;i<N;++i) p[i]=i;
    }
    int Find(int x) {
        return p[x]==x?x:p[x]=Find(p[x]);
    }
    void Union(int x,int y) {
        p[Find(x)]=Find(y);
    }
} djs;
const int N = 200006;
ll a[N];

struct Edge{
    ll a,b,c;
    Edge(ll _a,ll _b,ll _c):a(_a),b(_b),c(_c){}
};

bool operator<(const Edge &e1,const Edge &e2) {
    return e1.c < e2.c;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;++i) {
        cin >> a[i];
    }
    int _ = (min_element(a+1,a+n+1) - a);
    vector<Edge> e;
    for (int i=1;i<=n;++i) {
        if (i!=_) {
            e.push_back(Edge(i,_,a[i]+a[_]));
        }
    }
    for (int i=1;i<=m;++i) {
        ll x,y,z;
        cin >> x >> y >> z;
        e.push_back(Edge(x,y,z));
    }
    sort(e.begin(),e.end());
    djs.init();
    ll ans=0;
    for (Edge ee:e) {
        if (djs.Find(ee.a) == djs.Find(ee.b)) continue;
        ans += ee.c;
        djs.Union(ee.a,ee.b);
    }
    cout << ans << endl;
}