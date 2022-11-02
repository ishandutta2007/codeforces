#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, edge> P;
typedef long long ll;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

vector<P> p;
ll ans[200001];

int main(){
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        p.push_back(P(w, edge(u, v)));
    }
    ll a = 0;
    sort(p.begin(), p.end());
    for(int i = 0; i < p.size(); i++){
        ll s1, s2;
        int w = p[i].first;
        int u = p[i].second.first;
        int v = p[i].second.second;
        //cout << u << ' ' << v << endl;
        s1 = uf.size(u);
        s2 = uf.size(v);
        a += s1*s2;
        uf.unionSet(u, v);
        ans[w] = a;
        //cout << a << endl;
    }
    for(int i = 1; i <= 200000; i++){
        if(ans[i] == 0) ans[i] = ans[i-1];
        //cout << ans[i] << endl;
    }
    ll t = (n*(n-1))/2;
    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        cout << ans[q];
        if(i != m-1) cout << ' ';
        else cout << endl;
    }
}