#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

typedef long long ll;
const int maxn = 18, maxm = 1 << maxn, maxk = 400;
int n, m, a[maxn + 3][maxn + 3], cnt;
ll dp[maxm + 3][maxn + 3], f[maxn + 3][maxm + 3], e[maxm + 3], cur[maxm + 3], ans[maxk + 3], res[maxm + 3];
map<vector<int>, int> M;
vector<int> tmp, vec[maxk + 3];

void dfs(int n, int lb) {  
    if (n >= lb) {
        tmp.push_back(n);
        M[tmp] = ++cnt;
        vec[cnt] = tmp;
        tmp.pop_back();
    }
    for (int i = lb; i <= n; i++) {
        tmp.push_back(i);
        dfs(n - i, i);
        tmp.pop_back();
    }
}

void fwt(ll a[], int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = i; j < i + k; j++) {
                a[j + k] += a[j];
            }
        }
    }
}

void ifwt(ll a[], int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = i; j < i + k; j++) {
                a[j + k] -= a[j];
            }
        }
    }
}

void ifmt(ll a[], int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = i; j < i + k; j++) {
                a[j] -= a[j + k];
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(n, 1);
    rep(i, 1, n) rep(j, 1, n) {
        scanf("%1d", &a[i][j]);
    }
    rep(i, 1, n) dp[1 << (i - 1)][i] = 1;
    rep(msk, 1, (1 << n) - 1) {
        int d = __builtin_popcount(msk);
        rep(i, 1, n) if (msk >> (i - 1) & 1) {
            int old = msk ^ (1 << (i - 1));
            rep(j, 1, n) if ((old >> (j - 1) & 1) && a[i][j] == 1) {
                dp[msk][i] += dp[old][j];
            }
            f[d][msk] += dp[msk][i];
        }
    }
    rep(i, 1, n) fwt(f[i], 1 << n);
    e[0] = 1;
    fwt(e, 1 << n);
    rep(i, 1, cnt) {
        copy(e, e + (1 << n), cur);
        rep(j, 0, vec[i].size() - 1) {
            ll *a = f[vec[i][j]];
            rep(k, 0, (1 << n) - 1) cur[k] = cur[k] * a[k];
        }
        ifwt(cur, 1 << n);
        ans[i] = cur[(1 << n) - 1];
    }
    rep(msk, 0, (1 << (n - 1)) - 1) {
        vector<int>().swap(tmp);
        for (int i = 1, l = 1; i <= n; i += l, l = 1) {
            while (i + l <= n && (msk >> (i + l - 2) & 1)) l++;
            tmp.push_back(l);
        }
        sort(tmp.begin(), tmp.end());
        res[msk] = ans[M[tmp]];
    }
    ifmt(res, (1 << (n - 1)));
    rep(i, 0, (1 << (n - 1)) - 1) printf("%lld%c", res[i], " \n"[i == (1 << (n - 1)) - 1]);
    return 0;
}