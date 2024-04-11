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
#define vi vector<int>
#define FOR(i, x, y) for(int i = x; i < y; i++)

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  string ss;
  cin >> ss;
  int n = sz(ss);
  int mini = 1e9;
  for(int i = 0; i < n; i++){
    if(i == 0){
      cout << "Mike\n";
      mini = min(mini, ss[i] - 'a');
      continue;
    }
    int x = ss[i] - 'a';
    if(x <= mini){
      cout << "Mike\n";
      mini = min(mini, x);
      continue;
    }
    mini = min(mini, x);
    cout << "Ann\n";
  }
}