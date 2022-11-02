#include <cstdio>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int m, n, k, t;
const int maxn = 2e5 + 5;
int a[maxn];
int l[maxn], r[maxn], d[maxn];

pair<int, int> b[maxn];

bool check(int mid){
    int bar = a[m - mid + 1];
    int tot = 0;
    for(int i = 1;i <= k;i++){
        if(d[i] > bar){
            b[++tot] = make_pair(l[i], r[i]);
        }
    }
    sort(b + 1, b + 1 + tot);
    int maxr = 0;
    int pre = 0;
    int ans = 0;
    //cout << "mid:" << mid << "tot:" << tot << endl;
    for(int i = 1;i <= tot;i++){
        if(b[i].first > maxr){
            ans += 2 * (maxr - pre);
            ans += (b[i].first - 1) - pre;
            pre = b[i].first - 1;
        }
        maxr = max(b[i].second, maxr);
    }
    ans += (n + 1) - pre + 2 * (maxr - pre);
    //cout << mid << " " << ans << endl;
    if(ans <= t)
        return true;
    return false;
}

int main(){
    cin >> m >> n >> k >> t;
    for(int i = 1;i <= m;i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + m);
    for(int i = 1;i <= k;i++){
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
    }
    int L = 0, R = m;
    while(L < R){
        //cout << L << " " << R << endl;
        int mid = (L + R + 1) / 2;
        if(check(mid)){
            L = mid;
        }else{
            R = mid - 1;
        }
    }
    cout << L << endl;
    return 0;
}