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
#define mx 200003
int par[mx];

int find(int x){
  if(x == par[x])
    return x;
  return par[x] = find(par[x]);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n), l(200000, -1), r(200000, -1), cnt(200000, 0);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i] -= 1;
    cnt[a[i]] += 1;
    r[a[i]] = i;
  }
  for(int i = n - 1; i >= 0; i--)
    l[a[i]] = i;
  for(int i = 0; i < 2e5; i++)
    par[i] = i;
  vector<int> ve(200000);
  iota(ALL(ve), 0);
  sort(ALL(ve), [&](int x, int y){
    return r[x] < r[y];
  });
  priority_queue<pair<int, int>> pq;
  for(int i : ve){
    if(r[i] == -1)
      continue;
    // debug(i);
    while(!pq.empty() && pq.top().f > l[i]){
      auto now = pq.top().s;
      pq.pop();
      now = find(now);
      int x = find(i);
      par[now] = x;
      // cout << "gabung " << now << ' ' << x << endl;
    }
    pq.push({r[i], find(i)});
  }
  vector<vector<int>> isi(200000);
  int jaw = 0;
  for(int i = 0; i < 200000; i++){
    if(cnt[i] == 0)
      continue;
    isi[find(i)].pb(i);
  }
  for(int i = 0; i < 200000; i++){
    if(sz(isi[i]) == 0)
      continue;
    int L = 1e9, R = -1, maks = 0;
    for(int x : isi[i]){
      // debug(x);
      L = min(L, l[x]);
      R = max(R, r[x]);
      maks = max(maks, cnt[x]);
    }
    jaw += R - L + 1 - maks;
    // debug(jaw);
  }
  cout << jaw << endl;
}