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

int dep[20][200];
int a[10][200], n, m;

int dp(int mask, int now){
  if(now == m){
    if(__builtin_popcount(mask) == n)
      return 0;
    return -1e9;
  }
  int &ret = dep[mask][now];
  if(ret != -1)
    return ret;
  ret = dp(mask, now + 1);
  for(int nex = 1; nex < 1 << n; nex++){
    if(nex & mask)
      continue;
    for(int i = 0; i < n; i++){
      int cost = 0;
      for(int j = 0; j < n; j++){
        if(nex & (1 << j)){
          cost += a[(i + j) % n][now];
        }
      }
      ret = max(ret, dp(nex | mask, now + 1) + cost);
    }
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    reset(dep, -1);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> a[i][j];
    cout << dp(0, 0) << '\n';
  }
    
}