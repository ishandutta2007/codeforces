#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

static const int MAXN = 500000 + 10;

struct SA {
  int cnt[MAXN], tr[2][MAXN], ts[MAXN];
  int sa[MAXN], rk[MAXN], ht[MAXN];
  void build(char *s, int n, int m=256) {
    int i,k,*x=tr[0],*y=tr[1];
    memset(cnt,0,sizeof(cnt[0])*m);
    for (i=0;i<n;++i) cnt[(int)s[i]]++;
    partial_sum(cnt,cnt+m,cnt);
    for (i=0;i<n;++i) rk[i]=cnt[(int)s[i]]-1;
    for (k=1;k<=n;k<<=1) {
      for (i=0;i<n;++i) x[i]=rk[i],y[i]=i+k<n?rk[i+k]+1:0;
      fill(cnt,cnt+n+1,0); 
      for (i=0;i<n;++i) cnt[y[i]]++;
      partial_sum(cnt,cnt+n+1,cnt);
      for (i=n-1;i>=0;--i) ts[--cnt[y[i]]]=i;
      fill(cnt,cnt+n+1,0);
      for (i=0;i<n;++i) cnt[x[i]]++;
      partial_sum(cnt,cnt+n+1,cnt);
      for (i=n-1;i>=0;--i) sa[--cnt[x[ts[i]]]]=ts[i];
      for (i=rk[sa[0]]=0;i+1<n;++i) {
        rk[sa[i+1]]=rk[sa[i]]+(x[sa[i]]!=x[sa[i+1]]||y[sa[i]]!=y[sa[i+1]]);
      }
    }
  }
  void get_height(char *s, int n) {
    for (int i=0,l=0,j;i<n;++i) {
      if (!rk[i]) continue;
      for (j=sa[rk[i]-1];i+l<n&&j+l<n&&s[i+l]==s[j+l];) l++;
      ht[rk[i]]=l; if (l) l--;
    }
  }
} sa;

struct ST {
  int mx[MAXN][20], lg[MAXN], n;
  void build(int a[], int n) {
    lg[0]=-1; this->n=n;
    for (int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
    for (int i=0;i<n;++i) mx[i][0]=a[i];
    for (int j=1;(1<<j)<=n;++j) {
      for (int i=0;i+(1<<j)<=n;++i) {
        mx[i][j]=min(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
      }
    }
  }
  int ask(int a, int b) {
    if (a>b) swap(a,b); int k=lg[b-a+1];
    return min(mx[a][k],mx[b-(1<<k)+1][k]);
  }
} st;

char s[MAXN];
int n, sum[MAXN];
int nx[MAXN];
vector<PII> ql[MAXN];

int u[MAXN << 2];

int main() {
  scanf("%d%s", &n, s);
  sa.build(s, n);
  sa.get_height(s, n);
  int *ht = sa.ht;
  int *sa = ::sa.sa;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') sum[i] = 1;
    else sum[i] = -1;
    if (i) sum[i] += sum[i - 1];
  }
  st.build(sum, n);
  for (int i = 0; i < n; ++i) {
    int lim = i ? sum[i - 1] : 0;
    int l = i, r = n - 1;
    while (l < r) {
      int m = (l + r + 1) >> 1;
      if (st.ask(i, m) >= lim) l = m;
      else r = m - 1;
    }
    if (sum[i] < lim) nx[i] = i - 1;
    else nx[i] = l;
  }
  for (int i = 0; i < n; ++i) {
    int val = sa[i] ? sum[sa[i] - 1] : 0;
    int len = i ? ht[i] : 0;
    if (sa[i] + len <= nx[sa[i]]) {
      ql[nx[sa[i]] + 1].push_back(PII(val, -1));
      ql[sa[i] + len].push_back(PII(val, 1));
    }
  }
  LL ret = 0;
  for (int i = n - 1; i >= 0; --i) {
    u[sum[i] + n]++;
    for (auto &x: ql[i]) {
      ret += u[x.first + n] * x.second;
    }
  }
  cout << ret << endl;
  return 0;
}