#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    int n,m;
    cin >> n >> m;
    int a[n];
    int mn = 1e9 + 7, mx = -(1e9 + 7);
    for (int i=0;n>i;i++) {
        cin >>a[i];
        mn = min(mn,a[i]);
        mx = max(mx,a[i]);
    }
    mn = a[0],mx = a[0];
    for (int i=1;n>i;i++) {
        mn = min(mn,a[i]);
        mx = max(mx,a[i]);
    }
    if (m==1) cout<<mn<<endl;
    else if (m==2) {
        if (a[0] == mx || a[n-1] == mx) cout<<mx<<endl;
        else {
            int pre[n],suf[n];
            pre[0] = a[0];
            for (int i=1;n>i;i++) {
                pre[i] = min(pre[i-1],a[i]);
            }
            suf[n-1] = a[n-1];
            for (int i=n-2;i>=0;i--) {
                suf[i] = min(suf[i+1],a[i]);
            }
            int ans=-1234567890;
            for (int i=0;n-1>i;i++) {
                ans = max(ans,max(pre[i],suf[i+1]) );
            }
            cout<<ans<<endl;
        }
    }
    else cout<<mx<<endl;
}