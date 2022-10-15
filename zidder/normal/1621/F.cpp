#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
  long long a, b, c;
  cin >> n >> a >> b >> c;
  swap(a, b);
  string s;
  cin >> s;
  int o=0;
  vector<pair<int, int> > z;
  int zs = 0;
  if (s[0] == '0') {z.emplace_back(1, 1);zs = 1;}
  for (int i=1;i<n;++i){
    if (s[i] == s[i-1] && s[i] == '1'){
      o++;
    }
    else {
      if (s[i] == '0' && s[i-1] == '1'){
        z.emplace_back(0, 1);
      } else {
        if (s[i] == '0'){
          z.back().second++;
        }
      }
    }
    if (s[i] == '0') zs++;
  }
  int zo = zs - (int)z.size();

  if (s[s.size() - 1] == '0') {z.back().first=1;}
  sort(z.begin(), z.end());

  long long ans = 0;
  ans = (a + b) * min(o, zo);
  if (o > zo) ans += a;
  else if (zo > o) ans += b;

  long long cs = 0;
  for (pair<int, int> zp: z){
    int zi = zp.second;
    int bz = zp.first;
    if (bz){
      if (zo <= o){
        cs += (a + b) * zo;
        o -= zo;
        zo = 0;
      }
      if (o > 1){
        o--;
        cs += a - c;
        ans = max(ans, cs + a);
      }
      continue;
    }
    // cout << o << " " << zi << endl;
    if (o < zi - 1) break;
    cs += (zi - 1) * (a + b);
    cs -= c;
    cs += a;
    o -= zi - 1;
    zo -= (zi - 1);
    long long ans1 = cs + min(o, zo) * (a + b);
    if (o > zo) ans1 += a;
    else if (zo > o) ans1 += b;
    ans = max(ans, ans1);
  }
  cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}