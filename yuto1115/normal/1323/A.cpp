#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
    int t;
    cin >> t;
    rep(i,t) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        bool flag = false;
        rep(i,n) {
            if(a[i]%2 == 0) {
                cout << 1 << endl;
                cout << i+1 << endl;
                flag = true;
                break;
            }
        }
        if(!flag) {
            if(n == 1) cout << -1 << endl;
            else {
                cout << 2 << endl;
                cout << 1 << " " << 2 << endl;
            }
        }
    }
}