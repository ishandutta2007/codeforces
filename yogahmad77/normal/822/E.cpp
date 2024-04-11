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
const int mx = 4e5 + 10;
class Element_suffix{
public:
  int rank_now, rank_pref, pos;
};

class Suffix{
private:
  inline bool same_rank(Element_suffix a, Element_suffix b) {
    return a.rank_now == b.rank_now && a.rank_pref == b.rank_pref;
  }
  inline void reset_freq(bool is_sort_now) {
    for(int i = 0; i <= end; i++) freq[i] = 0;
    for(int i = 0; i < n; i++) freq[ is_sort_now ? suf[i].rank_now+1 : suf[i].rank_pref+1 ]++;
    start[0] = 0;
    for(int i = 1; i <= end; i++) {
      start[i] = freq[i-1];
      freq[i] += freq[i-1];
    }
  }
public:
  int sorted[20][mx], freq[mx], start[mx], SA[mx], end, n;
  Element_suffix suf[mx], tmp[mx];
  void build_suffix(string s) {
    n = sz(s);
    if (n == 1) {
      SA[0] = 0;
      return;
    }
    end = max(n, 1 << 8);
    for(int i = 0; i < n; i++) sorted[0][i] = (int)s[i];
    int step = 1;
    for(int cnt = 1; cnt < n; step++, cnt *= 2) {
      for(int i = 0; i < n; i++) {
        suf[i].rank_pref = sorted[step-1][i];
        suf[i].rank_now = (i + cnt < n) ? sorted[step-1][i+cnt] : -1;
        suf[i].pos = i;
      }
      reset_freq(1);
      for(int i = 0; i < n; i++) tmp[start[suf[i].rank_now+1]++] = suf[i];
      reset_freq(0);
      for(int i = 0; i < n; i++) suf[start[tmp[i].rank_pref+1]++] = tmp[i];
      for(int i = 0; i < n; i++) {
        sorted[step][suf[i].pos] = (i && same_rank(suf[i], suf[i-1])) ? sorted[step][suf[i-1].pos] : i;
      }
    } step--;
    for(int i = 0; i < n; i++) SA[sorted[step][i]] = i;
  }
int compute_lcp(int x, int y) {
  int ans = 0;
  for(int k = 20; k >= 0; k--) {
    int s = (1 << k);
    if (x + s - 1 < n && y + s - 1 < n && sorted[k][x] == sorted[k][y]) {
      ans += s;
      x += s;
      y += s;
    }
  }
  return ans;
}
};

Suffix ini; 

int n, m;
string s, t;
int dp[100003][33];

int getlcp(int x, int y){
  y += n + 1;
  return ini.compute_lcp(x, y);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> n >> s >> m >> t >> x;
	string gabung = s + '$' + t;
	ini.build_suffix(gabung);
  for(int i = 0; i < sz(gabung); i++){
    // debug(i, ini.SA[i]);
  }
	for(int now = 0; now < n; now++){
		for(int pake = 0; pake <= x; pake++){
			int &ret = dp[now][pake];
			dp[now + 1][pake] = max(dp[now + 1][pake], ret);
			if(pake + 1 <= x){
				int lcp = getlcp(now, ret);   
        // debug(now, ret, lcp);
				dp[now + lcp][pake + 1] = max(dp[now + lcp][pake + 1], ret + lcp);
			}
		}
	}
  for(int i = 0; i <= x; i++){
    if(dp[n][i] == m){
      cout << "YES\n";
      // debug(i);
      return 0;
    }
  }
  cout << "NO\n";
}