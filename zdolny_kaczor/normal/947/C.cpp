#include<bits/stdc++.h>
using namespace std;

#define REP(i, M) for(int i = 0; i < M; i++)
#define R(p, k) for(int i = p; i <= k; i++)
#define RI(j, p, k) for(int j = p; j <= k; j++)
#define PB push_back
#define FI first
#define SE second
#define LL long long 


#define DEB 0

#if DEB
  #define CEN cerr << endl;
  #define CEL(a) cerr << #a << ": " << a << " "; 
  #define CES(s) cerr << s << endl;
#else
  #define CEN 
  #define CEL(a) 
  #define CES(s) 
#endif


const int MN = (LL)1000 * 1000 + 5, INF = (LL)1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 5; 
int n, m, Q, q;
int res = 0;
string s;
int val[MN];
multiset<int> per;
const int ML = 30;

int32_t main(){
  int i, j, a, b, t;
  char c;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(7) << fixed;
  
  cin >> n;
  REP(i, n) {
    cin >> val[i];
  }
  
  REP(i, n) {
    cin >> a;
    per.insert(a);
  }
  
  CES("ok");
  for(int i = 0; i < n; i++) {
    CEL(i);
    int v = val[i], pref = 0;
    auto b = per.begin();
    auto e = per.end();
    
//     CES("go");
//       CEL(*b);
//       auto e2 = e;
//       CEL(*(--e2));
//       CEN;
    
    for(int l = ML - 1; l >=0 ;l--){
      auto en = per.end();
      if((1LL << l) & v) {
        CEL(1);
        auto it = per.lower_bound(pref | (1LL << l));
        if(it != en && (e == en || (*it) < (*e))) {
          b = it;
          pref |= (1LL << l);
        }
        
      }
      else{
        CEL(0);
        auto it = per.lower_bound(pref | (1LL << l));
        //CEL((pref & (1LL << l)));
        if(it != en) {
          if ((*it) > (*b)) {
            if(e == en || (*it) < (*e))
              e = it;
          }
          else {
            pref |= (1LL << l);
          }
        }
      }
      CEL(l);
      CEL((1LL << l));
      CEL(*b);
//       auto e2 = e;
//       CEL(*(--e2));
      CEN;
    }
    CEL(*b);
    //cerr << "!" << (*b) << "! ";
    cout << ((*b) ^ val[i]) << " ";
    per.erase(b);
  }
  cout << endl;
  
  return 0;
}