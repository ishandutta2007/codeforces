#include <bits/stdc++.h>
#define reg register
#define ll long long
#define ull unsigned long long
#define db double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define pb push_back
#define er erase
#define SZ(x) (int) x.size()
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mkp make_pair
using namespace std;
char ch, B[1 << 20], *S = B, *T = B;
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 20, stdin), S == T) ? 0 : *S++)
#define isd(c) (c >= '0' && c <= '9')
int aa, bb;
int rd() {
  while(ch = getc(), !isd(ch) && ch != '-');
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while(ch = getc(), isd(ch))
    aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
const int MAXN = 2e5 + 10;
const int BASE = 233;
char s[MAXN];
int n, a[MAXN], tot, flag[MAXN], cnt[MAXN];
ull power[MAXN], Hash[MAXN];
ull get(int l, int r) {
  int len = r - l + 1;
  return 1ll * Hash[r] - Hash[l - 1] * power[len];
}
ull check(int l, int r) {
  int L = lower_bound(a + 1, a + tot + 1, l) - a;
  int R = upper_bound(a + 1, a + tot + 1, r) - a - 1;
  if(L <= R) {
    ull x = (a[L] - l) & 1, v = x * power[R - L];
    if(L < R)
      v += get(L + 1, R);
    return v;
  }
  return 0;
}
int main() {
	power[0]=1;
	for(reg int i = 1; i < MAXN; ++i)
	power[i] = power[i - 1] * BASE;
	scanf("%d%s", &n, s + 1);
	int digit = 0;
	for(reg int i = 1; i <= n; ++i) {
		cnt[i] = cnt[i - 1];
		if(s[i] == '1')digit++;
	    else{
	      	flag[++tot]=digit&1;
	      	digit=0;
	      	a[tot] = i;
	      	++cnt[i];
	    }
	}
	for(reg int i = 1; i <= tot; ++i)
	    Hash[i] = Hash[i - 1] * BASE + flag[i];
	int q;
	scanf("%d", &q);
	while(q--) {
	    int l1, l2, len, r1, r2;
	    scanf("%d%d%d", &l1, &l2, &len);
	    r1 = l1 + len - 1;
	    r2 = l2 + len - 1;
	    if(cnt[r1] - cnt[l1 - 1] == cnt[r2] - cnt[l2 - 1] && check(l1, r1) == check(l2, r2))
	      printf("Yes\n");
	    else
	      printf("No\n");
	}
   return 0;
}