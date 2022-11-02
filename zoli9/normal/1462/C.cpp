#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin>>t;
  for(int u=0; u<t; u++) {
    cin>>n;
    if(n>45) {
      cout<<-1<<'\n';
    } else {
      vector<int> valasz;
      int sz=9;
      while(n>sz) {
        valasz.push_back(sz);
        n-=sz;
        sz--;
      }
      valasz.push_back(n);
      reverse(valasz.begin(), valasz.end());
      for(int x: valasz) {
        cout<<x;
      }
      cout<<'\n';
    }
  }
	return 0;
}