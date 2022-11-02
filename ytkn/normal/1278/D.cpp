#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

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

int r[1000000];
int idx[1000000];
vector<P> p;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        r[a] = b;
        idx[a] = i;
        idx[b] = i;
    }
    ll cnt = 0;
    set<int> st;
    UnionFind uf(N);
    for(int i = 0; i < 2*N; i++){
        if(r[i] == 0) continue;
        vector<int> v;
        for(auto iter = st.begin();iter != st.end(); iter++){
            if(*iter < i) {
                v.push_back(*iter);
            }
            if(*iter >= i && *iter < r[i]) {
                cnt++;
                uf.unionSet(idx[i], idx[*iter]);
                // cout << idx[i] << ' ' << idx[*iter] << endl;
                if(cnt >= N){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            if(*iter > r[i]) break;
        }
        for(auto iter = v.begin();iter != v.end(); iter++){

            st.erase(*iter);
        }
        // cout << i << ' ' << r[i] << endl; 
        // for(auto iter = st.begin();iter != st.end(); iter++){
        //     cout << *iter << ' ';
        // }
        // cout << endl;
        st.insert(r[i]);
    }
    bool allSameRoot = true;
    for(int i = 0; i < N; i++){
        if(uf.root(0) != uf.root(i)) allSameRoot = false;
    }
    cout << (allSameRoot ? "YES" : "NO") << endl;
}