#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<(1<<n);++i) {
        int x=0;
        for (int j=0;j<n;++j) {
            if (((1<<j)&i)!=0) x+=a[j];
            else x-=a[j];
        }
        if (x%360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}