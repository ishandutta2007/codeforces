#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
int t[1000009];
unordered_map<long long, int> ma;
struct bitree {
  int n;
  vector<long long> t;
  
  bitree(int n0) {
    n = n0;
    t.assign(n + 1, 0);    
  }
  
  long long query(int i) {
    long long sum = 0;
    for(; i > 0; i -= i & -i) sum += t[i];
    return sum;
  }
  
  void update(int i, int diff) {
    for(; i <= n; i += i & -i) t[i] += diff;
  }
};

int main() {
  cin>>n;
  v.resize(n);
  for(int i=1; i<=n; i++)
  {
    cin>>v[i-1];
    t[i]=v[i-1];
  }
  sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++)
  {
    ma[v[i]]=i+1;
  }
  bitree bt1(n);
  bitree bt2(n);
  long long answer=0;
  for(int i=1; i<=n; i++)
  {
    bt1.update(ma[t[i]], 1);
    long long nagyobb=bt1.query(n)-bt1.query(ma[t[i]]);
    bt2.update(ma[t[i]], nagyobb);
    answer+=(bt2.query(n)-bt2.query(ma[t[i]]));
  }
  
  cout<<answer<<endl;
  return 0;
}