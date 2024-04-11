#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

int n;
LL T, a, b;
const int maxn = 2e5 + 5;
int s[maxn];
LL t[maxn];
pair<int, int> itv[maxn];

int main(){
    int m;
    cin >> m;
    while(m--){
        scanf("%d", &n);
        scanf("%lld%lld%lld", &T, &a, &b);
        int A = 0, B = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d", &s[i]);
            A += (s[i] == 0);
        }
        B = n - A;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &t[i]);
        }
        for(int i = 1;i <= n;i++){
            itv[i] = make_pair(t[i], s[i]);
        }
        itv[n + 1] = make_pair(T + 1, 0);
        sort(itv + 1, itv + n + 1 + 1);
        int cnt0 = 0, cnt1 = 0;
        LL ans = 0;
        for(int i = 1;i <= n + 1;i++){
            LL time = cnt0 * a + cnt1 * b;
            LL cnt2 = A - cnt0, cnt3 = B - cnt1;
            //cout << cnt0 << " " << cnt1 << endl;
            //cout << time << endl;
            if(1LL * cnt2 * a + time < itv[i].first){
                LL num = min(cnt3, (itv[i].first - 1 - time - 1LL * cnt2 * a) / b);
                ans = max(ans, cnt0 + cnt1 + cnt2 + num);
            }else if(time < itv[i].first){
                LL num = min(cnt2, (itv[i].first - 1 - time) / a);
                ans = max(ans, cnt0 + cnt1 + num);
            }
            if(itv[i].second == 0){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}