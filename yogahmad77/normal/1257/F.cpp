#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<vector<int>, int> ada;
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    for(int i = 0; i < 1 << 15; i++){
      // debug(n);
      vector<int> count(n, 0);
      int mini = 1e9;
      for(int j = 0; j < n; j++){
        int hit = 0;
        int jadi = a[j] ^ i;
        for(int k = 0; k < 15; k++){
          if(jadi & (1 << k)) hit += 1;
        }
        count[j] = hit;
        mini = min(mini, hit);
      }
      for(int j = 0; j < n; j++) count[j] -= mini;
      ada[count] = i;
    }
    // debug(n);
    for(int i = 0; i < n; i++) a[i] >>= 15;
    for(int i = 0; i < 1 << 15; i++){
      vector<int> count(n, 0);
      int mini = 1e9;
      for(int j = 0; j < n; j++){
        int hit = 0;
        int jadi = a[j] ^ i;
        for(int k = 0; k < 15; k++){
          if(jadi & (1 << k)) hit += 1;
        }
        count[j] = hit;
        mini = min(mini, hit);
      }
      for(int j = 0; j < n; j++) count[j] -= mini;
      int maks = 0;
      for(int j = 0; j < n; j++) maks = max(maks, count[j]);
      for(int j = 0; j < n; j++) count[j] = maks - count[j];
      if(ada.count(count)){
        // debug(ada[count], i);
        cout << (ada[count] | (i << 15)) << endl;
        return 0;
      }
    }
    cout << -1 << endl;
}