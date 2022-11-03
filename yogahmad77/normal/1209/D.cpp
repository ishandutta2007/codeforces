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
  int n, k;
  cin >> n >> k;
  vector<int> a(k), b(k), ada(k), sudah(n, 0), wis(k, 0);
  vector<vector<int>> g(n);
  for(int i = 0; i < k; i++){
    cin >> a[i] >> b[i];
    ada[i] = 2;
    a[i] -= 1, b[i] -= 1;
    g[a[i]].pb(i);
    g[b[i]].pb(i);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for(int i = 0; i < k; i++)
    pq.push({ada[i], i});
  int jaw = 0;
  while(!pq.empty()){
    auto now = pq.top();
    pq.pop();
    if(ada[now.s] != now.f || wis[now.s])
      continue;
    if(now.f == 0){
      jaw += 1;
      wis[now.s] = 1;
      continue;
    }
    wis[now.s] = 1;
    // debug(now.s);
    // debug(now.f);
    if(!sudah[a[now.s]]){
      sudah[a[now.s]] = 1;
      for(int i : g[a[now.s]]){
        // debug(i);
        ada[i] -= 1;
        pq.push({ada[i], i});
      }
    }
    if(!sudah[b[now.s]]){
      sudah[b[now.s]] = 1;
      for(int i : g[b[now.s]]){
        ada[i] -= 1;
        pq.push({ada[i], i});
        // debug(i);
      }
    }
  }
  cout << jaw << endl;
}