#include <iostream>
#include <vector>

using namespace std;

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

bool used[100000];

vector<int> r[100000];
vector<int> v[100000];

int x[100000], y[100000];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        v[x[i]].push_back(i);
        v[y[i]].push_back(i);
    }
    UnionFind uf(k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j+1 < v[i].size(); j++){
            uf.unionSet(v[i][j], v[i][j+1]);
        }
    }
    for(int i = 0; i < k; i++){
        int r_ = uf.root(i);
        if(!used[x[i]]){
            r[r_].push_back(x[i]);
            used[x[i]] = true;
        }
        if(!used[y[i]]){
            r[r_].push_back(y[i]);
            used[y[i]] = true;
        }
    }
    int ans = 0;
    for(int i = 0; i < k; i++){
        if(r[i].size() != 0){
            //cout << r[i].size() << ' '  << uf.size(i) << endl;
            ans += min(uf.size(i), (int)r[i].size()-1);
        }
    }
    cout << k-ans << endl;
}