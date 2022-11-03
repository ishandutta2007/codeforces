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
  int N;
  cin >> N;
  cin >> ss;
  int z, e, r, o, n;
  z = e = r = o = n = 0;
  for(auto i : ss){
    if(i == 'z')
      z += 1;
    if(i == 'e')
      e += 1;
    if(i == 'r')
      r += 1;
    if(i == 'o')
      o += 1;
    if(i == 'n')
      n += 1;
  }
  assert(e == o);
  int satu = n;
  int nol = z;
  FOR(i, 0, satu)
    cout << 1 << ' ';
  FOR(i, 0, nol)
    cout << 0 << ' ';
}