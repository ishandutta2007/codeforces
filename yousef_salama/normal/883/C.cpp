#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long f, T, t0, a1, t1, p1, a2, t2, p2;
    cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;

    if(p2 < p1){
        swap(a1, a2);
        swap(t1, t2);
        swap(p1, p2);
    }

    t1 = min(t0, t1);
    t2 = min(t0, t2);

    auto calc = [&](long long rem_f, long long rem_T){
        if(rem_f * t1 > rem_T)return -1LL;
        if(rem_f * t0 <= rem_T)return 0LL;

        long long diff = rem_f * t0 - rem_T;
        long long delta = a1 * (t0 - t1);

        return p1 * ((diff + delta - 1) / delta);
    };

    long long ans = -1;
    for(int i = 0; ; i++){
        long long rem = calc(max(0LL, f - a2 * i), T - min(f, a2 * i) * t2);
        if(rem != -1){
            rem += p2 * i;
            if(ans == -1 || rem < ans)ans = rem;
        }
        if(a2 * i >= f)break;
    }
    cout << ans << '\n';

    return 0;
}