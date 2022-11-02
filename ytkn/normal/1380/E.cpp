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

int st_idx[200000];
set<int> st[200000];
set<int> ok;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) st_idx[i] = i;
    for(int i = 0; i < n; i++){
        int x; cin >> x; x--;
        if(st[x].count(i-1) > 0) ok.insert(i-1);
        st[x].insert(i);
    }
    cout << n-ok.size()-1 << endl;
    UnionFind uf(n);
    for(int i = 0; i < m-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        int ra = uf.root(a), rb = uf.root(b);
        int a_idx = st_idx[ra], b_idx = st_idx[rb];
        if(st[a_idx].size() < st[b_idx].size()){
            for(int j : st[a_idx]){
                if(st[b_idx].count(j+1)> 0) ok.insert(j);
                if(st[b_idx].count(j-1)> 0) ok.insert(j-1);
                st[b_idx].insert(j);
            }
            uf.unionSet(a, b);
            int r = uf.root(a);
            st_idx[r] = b_idx;
        }else{
            for(int j : st[b_idx]){
                if(st[a_idx].count(j+1)> 0) ok.insert(j);
                if(st[a_idx].count(j-1)> 0) ok.insert(j-1);
                st[a_idx].insert(j);
            }
            uf.unionSet(a, b);
            int r = uf.root(a);
            st_idx[r] = a_idx;
        }
        cout << n-ok.size()-1 << endl;
    }
}