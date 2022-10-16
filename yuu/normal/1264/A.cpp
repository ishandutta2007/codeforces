#include <bits/stdc++.h>
using namespace std;
#define left Len
#define right Rin
int n;
int p[400002];
int left[400002];
int right[400002];
void solve(){
  cin>>n;
  for(int i=1; i<=n; i++) cin>>p[i];
  p[0]=-1;
  p[n+1]=-1;
  for(int i=1; i<=n; i++) if(p[i]==p[i-1]) left[i]=left[i-1]; else left[i]=i;
  for(int i=n; i>=1; i--) if(p[i]==p[i+1]) right[i]=right[i+1]; else right[i]=i;
  int h=n/2+1;
  int g=0, s=0, b=0;
  int total=0;
  for(int i=1; i<=n; i++){///number of gold given out
    if(i*3*2+2>n) break;
    if(p[i]==p[i+1]) continue;
    int es=right[i+i+1];
    if(es+i+1>n) continue;
    if(right[es+i+1]>=h) continue;
    int eb=left[h]-1;
    if(eb>total){
      total=eb;
      g=i;
      s=es-g;
      b=eb-es;
    }
  }
  cout<<g<<' '<<s<<' '<<b<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int t;
  cin>>t;
  while(t--) solve();
}