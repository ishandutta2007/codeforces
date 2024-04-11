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

int dp[2][(1 << 12) + 100];
int a[12 + 10][2000 + 10], n, m;
int pre[(1 << 12) + 10][15][15], mini[(1 << 12) + 10][15];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> a[i][j];
    vector<int> ve(m), maks(m, 0);
    iota(ALL(ve), 0);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        maks[j] = max(maks[j], a[i][j]);
    sort(ALL(ve), [&](int x, int y){
      return maks[x] > maks[y];
    });
    m = min(n, m);
    for(int now = 0; now < m; now++){
      int x = ve[now];
      for(int mask = 0; mask < 1 << n; mask++){
        mini[mask][now] = 0;
        for(int y = 0; y < n; y++){
          pre[mask][now][y] = 0;
          for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
              pre[mask][now][y] += a[(i + y) % n][x];
            }
          }
          mini[mask][now] = max(mini[mask][now], pre[mask][now][y]);
        }
      }
    }
    for(int now = m; now >= 0; now--){
      for(int mask = 0; mask < 1 << n; mask++){
        int &ret = dp[now & 1][mask];
        if(now == m){
          if(__builtin_popcount(mask) == n)
            ret = 0;
          else ret = -1e9;
          continue;
        }
        ret = -1e9;
        ret = dp[(now + 1) & 1][mask];
        int inv = (1 << n) - 1 - mask;
        for(int nex = inv; nex > 0; nex = (nex - 1) & (inv)){
          // for(int i = 0; i < n; i++){
            ret = max(ret, dp[(now + 1) & 1][nex | mask] + mini[nex][now]);
          // }
        }
      }
    }
    cout << dp[0][0] << '\n';
  }
    
}