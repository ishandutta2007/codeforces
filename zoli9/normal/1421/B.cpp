#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tesztek, n;
  cin>>tesztek;
  while(tesztek--) {
    cin>>n;
    vector<vector<char> > v(n, vector<char>(n));
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        cin>>v[i][j];
      }
    }
    vector<pair<int, int> > mezok={{0, 1}, {1, 0}, {n-2, n-1}, {n-1, n-2}};
    vector<int> cel={0, 0, 1, 1};
    vector<pair<int, int> > valasz1, valasz2;
    for(int i=0; i<mezok.size(); i++) {
      if(v[mezok[i].first][mezok[i].second]-'0'==cel[i]) {
        valasz1.push_back(mezok[i]);
      } else {
        valasz2.push_back(mezok[i]);
      }
    }
    if(valasz1.size()>2) swap(valasz1, valasz2);
    cout<<valasz1.size()<<'\n';
    for(int i=0; i<valasz1.size(); i++) {
      cout<<valasz1[i].first+1<<" "<<valasz1[i].second+1<<'\n';
    }
  }
  return 0;
}