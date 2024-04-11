#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAX_N = 1506;

int a[MAX_N];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=1;n>=i;i++) {
        a[i] = s[i-1];
    }
    int q;
    cin >> q;
    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        if (m>n) {
            cout<<n<<'\n';
            continue;
        }
        int sz=0;
        int ans=m;
        int last=1;
        for (int i=1;n>=i;i++) {
            if (a[i] == c) ;
            else {
                if (sz < m) sz++;
                else {
                    while (a[last] == c) last++;
                    last++;
                }
            }
            ans = max(ans,i-last+1);
        }
        cout<<ans<<'\n';
    }
}