#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;

int a[N], b[N];

int n,m,ta,tb,k;

bool check(int t) {
    vector<int> va,vb;
    for (int i = 1;i <= n; ++i) {
        if (a[i] <= t) va.push_back(a[i]);
    }
    for (int i = 1;i <= m; ++i) {
        if (b[i] <= t) vb.push_back(b[i]);
    }
    if ((int)va.size() <= k || (int)vb.size() <= k) return true;
    int pre=0;
    for (int tt:va) {
        int _ = lower_bound(vb.begin(),vb.end(),tt+ta) - vb.begin();
        if (pre + (int)vb.size() - _ <= k) return true;
        ++pre;
    }
    return false;
}

int main () {
    scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
    for (int i = 1;i <= n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 1;i <= m; ++i) {
        scanf("%d",&b[i]);
    }
    int l = 0, r = 2000000006;
    while (r-l != 1) {
        int mid = (l + 0ll + r)>> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    //r is the answer
    if (r == 2000000006) cout << -1 << endl;
    else cout << r + 0ll + tb << endl;
}