#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int N = 105;

int a[N][N];

int n;

void show() {
    puts("YES");
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            printf("%d%c",a[i][j]," \n"[j==n-1]);
        }
    }
    exit(0);
}

void no() {
    puts("NO");
    exit(0);
}

int main () {
    cin >> n;
    map<int,int> mp;
    for (int i=0;i<n*n;++i) {
        int x; cin >> x;
        mp[x]++;
    }
    if (n%2 == 0) {
        int ptr=0;
        for (pii p:mp) {
            if (p.S % 4 != 0) no();
            int cnt = p.S / 4;
            while (cnt--) {
                int i = ptr/(n/2),j = ptr%(n/2);
                a[i][j] = p.F;
                a[i][n-j-1] = p.F;
                a[n-i-1][j] = p.F;
                a[n-i-1][n-j-1] = p.F;
                ++ptr;
            }
        }
        show();
    }
    int cnt=0;
    for (pii p:mp) {
        if (p.S % 2 == 1) ++cnt;
    }
    if (cnt >1) no();
    vector<pii> v;
    for (pii p:mp) v.push_back(p);
    for (pii &p:v) {
        if (p.S % 2 == 1) {
            --p.S;
            a[n/2][n/2] = p.F;
        }
    }
    int cnt2 = n - 1;
    for (pii p:v) {
        if (p.S % 4 == 2) {
            --cnt2;
        }
    }
    if (cnt2 < 0) no();
    int row=0,col=0;
    for (int times=0;times<1000;++times) {
        for (pii &p:v) {
            //cout << p.F << ' ' << p.S << endl;
            if (p.S % 4 == 2 || p.S % 4 == 0 && cnt2 > 0) {
                if (row == n/2) {
                    a[col][n/2] = p.F;
                    a[n - col - 1][n/2] = p.F;
                    ++col;
                }
                else {
                    a[n/2][row] = p.F;
                    a[n/2][n-row-1] = p.F;
                    ++row;
                }
                p.S -= 2;
                if (p.S % 4 == 2)cnt2 -= 2;
            }
        }
    }
    int ptr=0;
    for (pii p:v) {
        if (p.S % 4 != 0) no();
        int cnt = p.S / 4;
        while (cnt--) {
            int i = ptr/(n/2),j = ptr%(n/2);
            a[i][j] = p.F;
            a[i][n-j-1] = p.F;
            a[n-i-1][j] = p.F;
            a[n-i-1][n-j-1] = p.F;
            ++ptr;
        }
    }
    show();
}