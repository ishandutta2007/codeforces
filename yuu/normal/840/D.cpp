#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[300001];
vector <int> pos[300001];
bool count(int i, int l, int r, int low){
  if(pos[i].size()-1<low) return 0;
  int t=upper_bound(pos[i].begin(), pos[i].end(), r)-pos[i].begin();
  if(t<low) return 0;
  return pos[i][t-low]>=l;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n>>q;
  for(int i=1; i<=n; i++){
    cin>>a[i];
    pos[a[i]].push_back(i);
  }
  for(int i=1; i<=n; i++) pos[i].push_back(n+1);
  for(int i=1, l, r, k; i<=q; i++){
    cin>>l>>r>>k;
    int low=(r-l+1)/k;
    while(low*k<=r-l+1) low++;
    int best=n+1;
    for(int j=1; j<=80; j++){
      int x=a[rng()%(r-l+1)+l];
      if(count(x, l, r, low)) best=min(best, x);
    }
    if(best==n+1) best=-1;
    cout<<best<<'\n';
  }
}