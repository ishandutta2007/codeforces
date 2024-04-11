#include <bits/stdc++.h>
using namespace std;
int m, n;
int fonok[500009];
int melyseg[500009];
 
int holvan(int x) {
  if(fonok[x]==0) {
    return x;
  }
  int fofonok= holvan(fonok[x]);
  fonok[x]=fofonok;
  return fofonok;
}
 
void unio(int x, int y) {
  x=holvan(x);
  y=holvan(y);
  if(x==y) return;
  if (melyseg[x]<melyseg[y]) {
    fonok[x]=y;
  }
  else fonok[y]=x;
  if (melyseg[x]==melyseg[y]) melyseg[x]++;
  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  int n, q;
  cin>>n>>q;
  set<int> deps;
  for(int i=1; i<=n; i++) deps.insert(i);
  for(int i=0; i<q; i++){
    int type, cs1, cs2;
    cin>>type>>cs1>>cs2;
    if(cs2<cs1) swap(cs2, cs1);
    if(type==1){
      unio(cs1, cs2);
    }
    else if(type==2){
      auto it=deps.lower_bound(cs1);
      if(it==deps.end()) continue;
      it++;
      for(; it!=deps.end() && (*it)<cs2; ){
        unio(cs1, *it);
        it = deps.erase(it);
      }
      if(it!=deps.end() && (*it)<=cs2) {
          unio(cs1, *it);
      }
    }
    else{
      if(holvan(cs1)==holvan(cs2)){
        cout<<"YES\n";
      }
      else{
        cout<<"NO\n";
      }
    }
  }
	return 0;
}