#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, a, d;
    int m;
    scanf("%lld %d %lld %lld", &n, &m, &a, &d);

    vector <long long> t(m);
    for(int i = 0; i < m; i++)scanf("%lld", &t[i]);

    long long curtime = 1, ans = 0;
    int i = 0;

    while(true){
        while(i < m && t[i] < curtime)i++;

        if(i == m){
            long long rem = max(0LL, n - (curtime - 1) / a);
            long long cnt = d / a + 1;
            ans += (rem + cnt - 1) / cnt;

            break;
        }else{
            long long rem = max(0LL, n - (curtime - 1) / a);
            long long cur = min(rem, (t[i] - 1) / a - (curtime - 1) / a);

            if(cur == 0){
                ans++;
                curtime = t[i] + d + 1;
            }else{
                curtime = curtime + (a - (curtime % a)) % a;

                long long cnt = d / a + 1;
                long long r = (cur - 1) / cnt;

                ans += r + 1;
                curtime = curtime + r * cnt * a + d + 1;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}