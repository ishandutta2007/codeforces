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
  cin >> n;
  vector<int> ve(n), sudah(n, 0);
  int jaw = 0, cnt = 0;
  for(int i = 0; i < n; i++)
    cin >> ve[i];
  while(cnt < n){
    int mini = 1e9;
    for(int i = 0; i < n; i++){
      if(!sudah[i]){
        mini = min(mini, ve[i]);
      }
    }
    jaw += 1;
    for(int i = 0; i < n; i++){
      if(!sudah[i] && ve[i] % mini == 0){
        sudah[i] = 1;
        cnt += 1;
      }
    }
  }
  cout << jaw << endl;
}