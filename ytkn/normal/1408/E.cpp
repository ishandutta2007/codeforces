#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> P_;
typedef pair<ll, P_> P;

int n, m;
int a[100000], b[100000];
vector<int> used[100000];


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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> m >> n;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<P> v;
    for(int i = 0; i < m; i++){
        int s; cin >> s;
        for(int j = 0; j < s; j++){
            ll x; cin >> x; x--;
            v.push_back(P(a[i]+b[x], P_(x, i)));
        }
    }
    UnionFind uf(n);
    ll ans = 0;
    sort(v.begin(), v.end(), greater<P>());
    for(auto p : v){
        int col = p.second.second;
        int u = p.second.first;
        if(used[col].empty()){
            used[col].push_back(u);
        }else{
            int prev = used[col][0];
            if(!uf.findSet(u, prev)){
                uf.unionSet(u, prev);
                used[col].push_back(u);
            }else{
                // cout << col+1 << ' ' << u+1 << ' ' << p.first << endl;
                ans += p.first;
            }
        }
    }
    cout << ans << endl;
}