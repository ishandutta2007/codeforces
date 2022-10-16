#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int n, m;
  vector <int> a, b;
  cin>>n;
  a.resize(n);
  for(auto &x: a) cin>>x;
  cin>>m;
  b.resize(m);
  for(auto &x: b) cin>>x;
  cout<<*max_element(a.begin(), a.end())<<' '<<*max_element(b.begin(), b.end())<<'\n';
}