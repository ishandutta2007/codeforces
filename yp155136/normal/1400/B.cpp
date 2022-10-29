#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        ll p, f; scanf("%lld%lld", &p, &f);
        ll cnt_s, cnt_w; scanf("%lld%lld", &cnt_s, &cnt_w);
        ll s, w; scanf("%lld%lld", &s, &w);
        ll ans = 0;
        for (int i = 0; i <= cnt_s; ++i) {
            if (i * s > p) break;
            ll tmp_ans = i;
            ll cs = cnt_s - i, cw = cnt_w;
            ll take_w = min((p - i * s) / w, cnt_w);
            cw -= take_w;
            tmp_ans += take_w;
            ll tmp_f = f;
            if (s < w) {
                // take cs first
                ll take_s = min(tmp_f / s, cs);
                tmp_ans += take_s;
                tmp_f -= s * take_s;
                ll take_w = min(tmp_f / w, cw);
                tmp_ans += take_w;
            }
            else {
                ll take_w = min(tmp_f / w, cw);
                tmp_ans += take_w;
                tmp_f -= w * take_w;
                ll take_s = min(tmp_f / s, cs);
                tmp_ans += take_s;
            }
            ans = max(ans, tmp_ans);
        }
        printf("%lld\n", ans);
    }
}