#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, top;

ll t;

double mx, lim[N];

struct Node {
    double a, b, p, x, y;    

    bool operator < (const Node &tmp) const {
        return fabs(x - tmp.x) < 1e-12 ? y > tmp.y : x < tmp.x;
    }
} a[N], b[N];

struct Mat {
    double v[3][3];
    int n, m;

    void init_(int _n, int _m) {
        n = _n, m = _m;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[i][j] = 0;
            }
        }
    }
} g[45];

Mat operator * (Mat A, Mat B) {
    Mat C;
    C.init_(A.n, B.m);

    for (int i = 0; i < A.n; i++) {
        for (int k = 0; k < A.m; k++) {
            for (int j = 0; j < B.m; j++) {
                C.v[i][j] += A.v[i][k]*B.v[k][j];
            }
        }
    }

    return C;
}

double calc_(Node a, Node b) {
    return (b.y - a.y)/(b.x - a.x);
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>t;

    for (int i = 1; i <= n; i++) {
        cin>>a[i].a>>a[i].b>>a[i].p;
        mx = max(mx, a[i].p*a[i].b);
    }

    for (int i = 1; i <= n; i++) {
        a[i].x = a[i].p;
        a[i].y = a[i].p*a[i].a - a[i].p*mx;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        if (i > 1 && fabs(a[i].x - a[i - 1].x) < 1e-12) {
            continue;
        }

        while (top > 1 && calc_(b[top], a[i]) >= lim[top]) {
            top--;
        }

        b[++top] = a[i];
        lim[top] = calc_(b[top - 1], b[top]);
    }

    ll cnt = 0;
    Mat ans;
    ans.init_(1, 3);
    ans.v[0][2] = 1; 

    for (int i = 1; i <= top; i++) {
        double k = ans.v[0][0] - mx*(cnt + 1);

        if (i < top && lim[i + 1] >= k) {
            continue;
        }

        Mat res = ans;
        g[0].init_(3, 3);
        g[0].v[0][0] = 1 - b[i].p;
        g[0].v[1][0] = mx*b[i].p;
        g[0].v[2][0] = b[i].a*b[i].p;
        g[0].v[1][1] = g[0].v[2][1] = g[0].v[2][2] = 1;

        for (int j = 1; j <= 35; j++) {
            g[j] = g[j - 1]*g[j - 1];
        } 

        ll tot = 0;

        for (int j = 35; j >= 0; j--) {
            Mat cur = res*g[j];

            if (i == top || lim[i + 1]/mx < cur.v[0][0]/mx - (cur.v[0][1] + 1)) {
                res = cur;
                tot += 1ll<<j;
            }
        }

        tot = min(t - cnt, tot + 1);

        for (int j = 35; j >= 0; j--) {
            if (tot&(1ll<<j)) {
                ans = ans*g[j];
            }
        }

        cnt += tot;

        if (cnt == t) {
            break;
        }
    }

    cout<<fixed<<setprecision(9)<<ans.v[0][0]<<'\n';
}