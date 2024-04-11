#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef pair<int,int> pii;
typedef long long ll;
int n,k,m,mx;
ll ans;
vector<pii> vec[N];
#define lowbit(x) ((x) & (-(x)))
ll num[N],val[N];
void add(ll* v,int p,ll val) {
  for ( ; p <= mx ; p += lowbit(p))
    v[p] += val;
}
ll ask(ll* v,int p) {
  ll ret = 0;
  for ( ; p ; p -= lowbit(p))
    ret += v[p];
  return ret;
}
int query() {
  int t = k, ret = 0;
  for (int i = 20 ; i >= 0 ; -- i) {
    if (ret + (1 << i) <= mx) {
      if (t > num[ret + (1 << i)]) {
	t -= num[ret + (1 << i)];
	ret += 1 << i;
      }
    }
  }
  return ret;
}
int main() {
  int a,b,c,d;
  scanf("%d%d%d",&n,&k,&m);
  for (int i = 1 ; i <= m ; ++ i) {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    vec[a].push_back(pii(c,d));
    vec[b+1].push_back(pii(-c,d));
    mx = max(d,mx);
  }
  for (int i = 1 ; i <= n ; ++ i) {
    for (int j = 0 ; j < (int)vec[i].size() ; ++ j) {
      add(num,vec[i][j].second,vec[i][j].first);
      add(val,vec[i][j].second,1ll * vec[i][j].first * vec[i][j].second);
    }
    int tmp = query();
    ans += ask(val,tmp);
    if (tmp < mx) ans += 1ll * (tmp + 1) * (k - ask(num,tmp));
  }
  cout << ans << endl;
  return 0;
}