#include <bits/stdc++.h>
using namespace std;

int a[444444];

int main () {
    int n; cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[i]; a[i+n] = a[i];
    }
    int ans=0;
    n<<=1;
    int pre=0;
    for (int i=1;i<=n;++i) {
        if (a[i]) ++pre;
        else pre=0;
        ans = max(ans,pre);
    }
    cout << ans << endl;
}