#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 5000 + 10, MOD = 1e9 + 7;
bool ok[MAXN][MAXN];
char s[MAXN];
int n;

struct SA {
  static const int MAXN = 5000 + 10;
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
  inline int lcp(int a, int b) {
    a=rk[a],b=rk[b];
    //if (a == b) return n - a + 1;
    if (a>b) swap(a,b);
    return rmq(a+1,b);
  }
  int mx[MAXN][20], lg[MAXN];
  void rmq_init(int n) {
    for (int i=-(lg[0]=-1);i<n;++i) lg[i]=lg[i>>1]+1;
    for (int i=0;i<n;++i) mx[i][0]=ht[i];
    for (int i,j=1;(1<<j)<=n;++j) {
      for (i=0;i+(1<<j)<=n;++i)
        mx[i][j]=min(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    }
  }
  inline int rmq(int a, int b) {
    int k=lg[b-a+1];
    return min(mx[a][k],mx[b-(1<<k)+1][k]);
  }
} sa;

bool cmp(int i, int j) {
  int l = j - i;
  if (s[i] == '0') return false;
  int c = sa.lcp(i, j);
  if (c >= l) return false;
  else return s[i + c] < s[j + c];
}

int dp[MAXN][MAXN];

int main() {
  scanf("%d%s", &n, s);
  sa.build(s, n);
  sa.get_height(s, n);
  sa.rmq_init(n);
  for (int l = 1; l <= n; ++ l) {
    for (int i = l; i + l <= n; ++ i) {
      ok[l][i + 1] = cmp(i - l, i);
    }
  }
  for (int i = 1; i <= n; ++ i) {
    for (int l = 1; l <= i; ++ l) {
      if (l == i) dp[i][l] = 1;
      else if (s[i - l] != '0') {
        dp[i][l] = dp[i - l][l - 1];
        if (ok[l][i - l + 1]) {
          dp[i][l] += dp[i - l][l];
          dp[i][l] -= dp[i - l][l - 1];
        }
        dp[i][l] %= MOD;
      }
      //cout << i << " " << l << " " << dp[i][l] << endl;
      dp[i][l] += dp[i][l - 1];
      dp[i][l] %= MOD;
    }
    for (int l = i + 1; l <= n; ++ l) dp[i][l] = dp[i][l - 1];
  }
  printf("%d\n", dp[n][n]);
  return 0;
}