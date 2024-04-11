#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 100003
#define vi vector<int>
#define FOR(i, x, y) for(int i = x; i < y; i++)

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  string ss;
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  FOR(i, 0, n)
    FOR(j, 0, n)
      cin >> v[i][j];
  vector<int> a(n), b(n);
  for(int i = 1; i < n; i++){
    for(int j = 0; j < n; j++){
      if(v[0][j] == 0 || v[i][j] == 0)
        continue;
      int gcd = __gcd(v[0][j], v[i][j]);
      int A = v[i][j] / gcd;
      int B = v[0][j] / gcd;
      a[i] = A;
      b[i] = B;
      // cout << a[i] << '/' << b[i] << endl;
      break;
    }
  }
  a[0] = 1; b[0] = 1;
  set<int> faktor;
  for(int i = 1; i * i <= v[0][1]; i++){
    if(v[0][1] % i == 0){
      faktor.insert(i);
      faktor.insert(v[0][1] / i);
    }
  }
  for(int i : faktor){
    bool ya = true;
    for(int j = 1; j < n; j++){
      if(i == 2){
        // debug(a[j] * i / b[j]);
      }
      if((1LL * a[j] * i) % b[j] == 0 && v[0][j] % i == 0){
        if(1LL * a[j] * i / b[j] != 1LL * v[0][j] / i)
          ya = false;
      }
      else ya = false;
    }
    if(ya){
      cout << i << ' ';
      for(int j = 1; j < n; j++){
        cout << 1LL * a[j] * i / b[j] << ' ';
      }
      return 0;
    }
  }
}