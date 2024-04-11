#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
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

typedef pair<int, int> P_;
typedef pair<ll, P_> P;

vector<P> v;
int x[2000], y[2000];
ll k[2000];
bool used[2000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n;
    cin >> n;
    UnionFind uf(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        ll c;
        cin >> c;
        v.push_back(P(c, P_(i, i)));
    }
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            ll cost = (abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
            v.push_back(P(cost, P_(i, j)));
        }
    }
    ll ans = 0;
    vector<P_> ansr;
    vector<int> ansp;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        P p = v[i];
        ll cost = p.first;
        int j = p.second.first;
        int k = p.second.second;
        if(j == k){
            int r = uf.root(j);
            if(!used[r]){
                ans += cost;
                ansp.push_back(j);
                used[r] = true;
            }
        }else{ 
            int jr = uf.root(j);
            int kr = uf.root(k);
            if((jr != kr) && (!used[jr] || !used[kr])){
                uf.unionSet(j, k);
                ansr.push_back(P_(j, k));
                ans += cost;
                if(used[jr] || used[kr]) {
                    int r = uf.root(j);
                    used[r] = true;
                }
            }
        }
    }
    cout << ans << endl;
    cout << ansp.size() << endl;
    for(int i = 0; i < ansp.size(); i++){
        cout << ansp[i]+1;
        if(i+1 == ansp.size()) cout << endl;
        else cout << ' ';
    }
    cout << ansr.size() << endl;
    for(int i = 0; i < ansr.size(); i++){
        cout << ansr[i].first+1 << ' ' << ansr[i].second+1 << endl;
    }
}