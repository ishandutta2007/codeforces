#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const int MN = 1000100;
int n;
ll b;
ll a[MN];
int cwe[MN];
int cwc[MN];
int cwce[MN];
void calccwe() {
    ll u = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < 2*n && u+a[j - ((j < n) ? 0 : n)] <= b) {
            u += a[j%n];
            j++;
        }
        cwe[i] = j;
//        printf("cwe %d %d\n", i, cwe[i]);
        u -= a[i];
    }
}

void calccwcount() {
    for (int i = n-1; i >= 0; i--) {
        int u = cwe[i];
        if (u >= n) {
            cwc[i] = 1;
            cwce[i] = u;
        } else {
            cwc[i] = cwc[u]+1;
            cwce[i] = cwce[u];
        }
//        printf("cwc %d %d %d\n", i, cwc[i], cwce[i]);
    }
}

int calc() {
    calccwe();
    calccwcount();
    ll u = 0;
    int res = MN;
    for (int i = 0; i < n; i++) {
        if (u > b) break;
        int r = cwc[i];
        if (cwce[i] - n < i) r++;
        res = min(res, r);
        u += a[i];
    }
    return res;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        int aa;
        scanf("%d", &aa);
        a[i] = aa;
    }
    for (int i = 0; i < q; i++) {
        cin >> b;
        cout << calc() << endl;
    }
    return 0;
}