#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <string> s;
vector <vector <int>> f;
vector <vector <int>> g;
const int base=999727999;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>m;
  s.resize(n);
  for(auto &x: s) cin>>x;
  f.resize(n);
  for(auto &x: f) x.resize(m, 0);
  f[0][0]=1;
  for(int i=0; i<n; i++) for(int j=0; j<m; j++){
    if(f[i][j]){
      if(s[i][j]=='#'){
        f[i][j]=0;
        continue;
      }
      if(i+1<n) f[i+1][j]=1;
      if(j+1<m) f[i][j+1]=1;
    }
  }
  if(f.back().back()==0){
    puts("0");
    return 0;
  }
  // cerr<<"OK\n";
  ///can't reach
  ///reachable
  for(auto &x: f) for(auto &y: x) y=0;
  g=f;
  f[0][0]=1;
  s[0][0]='#';
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(s[i][j]!='#'){
    // cerr<<i<<' '<<j<<' '<<f[i][j]<<'\n';
    if(i) f[i][j]=f[i-1][j];
    else f[i][j]=0;
    // cerr<<i<<' '<<j<<' '<<f[i][j]<<'\n';
    if(j) f[i][j]+=f[i][j-1];
    // cerr<<i<<' '<<j<<' '<<f[i][j]<<'\n';
    while(f[i][j]>=base) f[i][j]-=base;
    // cerr<<i<<' '<<j<<' '<<f[i][j]<<'\n';
    // cerr<<f[i][j]<<" \n"[j+1==m];
  }
  g.back().back()=1;
  s[n-1][m-1]='#';
  s[0][0]='.';
  for(int i=n-1; i>=0; i--) for(int j=m-1; j>=0; j--) if(s[i][j]!='#'){
    if(i<n-1) g[i][j]=g[i+1][j];
    else g[i][j]=0;
    if(j<m-1) g[i][j]+=g[i][j+1];
    while(g[i][j]>=base) g[i][j]-=base;
  }
  int cnt=g[0][0];
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(s[i][j]!='#'){
    if((((long long)f[i][j])*g[i][j])%base==cnt){
      if(((i!=0)||(j!=0))&&((i!=n-1)||(j!=m-1))){
        // cerr<<i<<' '<<j<<'\n';
        puts("1");
        return 0;
      }
    }
  }
  puts("2");
}