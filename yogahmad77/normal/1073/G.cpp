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
const int mx = 2e5 + 10;

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
  string s;
  void build_suffix(string ss) {
    s = ss;
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
} ini;
int n, q, di[mx];
string ss;

long long hitung(vector<int> a){
    sort(ALL(a), [&](int i, int j){
        return di[i] < di[j];
    });
    vector<int> lcp;
    for(int i = 1; i < sz(a); i++) lcp.pb(ini.compute_lcp(a[i - 1], a[i]));
    vector<int> ve(sz(lcp));
    iota(ALL(ve), 0);
    sort(ALL(ve), [&](int i, int j){
        return lcp[i] < lcp[j];
    });
    set<int> ini;
    ini.insert(-1);
    ini.insert(sz(ve));
    long long ret = 0;
    for(int i : ve){
        auto it = ini.upper_bound(i);
        int kanan = *it;
        it--;
        int kiri = *it;
        int tadi = 0;
        if(kanan < sz(ve)) tadi = max(tadi, lcp[kanan]);
        if(kiri >= 0) tadi = max(tadi, lcp[kiri]);
        int banyak = kanan - kiri;
        ret += 1LL * banyak * (banyak - 1) / 2 * (lcp[i] - tadi);
        ini.insert(i);
    }
    // for(int i : lcp) cout << i << ' ';
    // debug(ret);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> ss;
    ini.build_suffix(ss);
    for(int i = 0; i < n; i++) di[ini.SA[i]] = i;
    while(q--){
        int A, B;
        cin >> A >> B;
        vector<int> a(A), b(B), c(A + B);
        for(int i = 0; i < A; i++) cin >> a[i], a[i] -= 1;
        for(int i = 0; i < B; i++) cin >> b[i], b[i] -= 1;
        for(int i = 0; i < A; i++) c[i] = a[i];
        for(int i = 0; i < B; i++) c[A + i] = b[i];
        cout << hitung(c) - hitung(a) - hitung(b) << '\n';
    }
}