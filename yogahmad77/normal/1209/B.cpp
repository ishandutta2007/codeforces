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


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  string ss;
  cin >> n;
  cin >> ss;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  for(int i = 0; i < n; i++)
    c[i] = ss[i] - '0';
  int jaw = 0;
  for(int i = 0; i < n; i++)
    jaw += c[i];
  for(int i = 1; i < 5000; i++){
    int cnt = 0;
    for(int j = 0; j < n; j++){
      if(i % a[j] == b[j] % a[j] && i >= b[j]){
        c[j] ^= 1;
      }
      cnt += c[j];
    }
    jaw = max(jaw, cnt);
  }
  cout << jaw << endl;
}