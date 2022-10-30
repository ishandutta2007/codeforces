#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 22;
ull fact[N];
int cnt[N];


ull calc(int n) {
    ull ans = 1;
    for (int i = 0; i < n; i++) {
        ull x = 0;
        for (int y = 0; y <= i+1; y++) x+=cnt[y];
        ans *= x-i;
    }
    for (int i = 0; i < N; i++) ans /= fact[cnt[i]];
    return ans;
}

void solve() {
    ll k;
    scanf("%lld", &k);
    memset(cnt,0,sizeof cnt);
    int tot=0;
    for (int i = 2; k > 0; i++) {
        ++cnt[k%i];
        k/=i;
        ++tot;
    }
    ull ans = calc(tot);
    //printf("ans=%llu\n",ans);
    if (cnt[0] > 0) {
        --cnt[0];
        ans -= calc(tot-1);
    }
    

    ans--;
    printf("%llu\n", ans);

}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}