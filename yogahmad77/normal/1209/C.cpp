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

int t;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> t;
  while(t--){
    int n;
    string ss;
    cin >> n;
    cin >> ss;
    vector<vector<int>> ve(10);
    vector<int> warna(n);
    for(int i = 0; i < n; i++)
      ve[ss[i] - '0'].pb(i);
    int tadi = -1, berapa = 0;
    for(int i = 0; i < 10; i++){
      for(int j : ve[i]){
        // debug(j);
        // cout << tadi << ' ' << j << endl;
        if(tadi < j){
          tadi = j;
          warna[j] = berapa + 1;
        }
        else{
          for(int x : ve[i]){
            if(x > tadi){
              warna[x] = berapa + 1;
            }
          }
          berapa += 1;
          int ini;
          for(int x : ve[i]){
            if(x < tadi){
              warna[x] = berapa + 1;
              ini = x;
            }
          }
          tadi = ini;
          break;
        }
      }
    }
    bool ya = 1;
    for(int i = 0; i < n; i++)
      if(warna[i] > 2)
         ya = 0;
    if(!ya)
      cout << "-\n";
    else{
      for(int i = 0; i < n; i++)
        cout << warna[i];
      cout << '\n';
    }
  }
}