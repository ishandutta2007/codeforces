#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n;

ll s[N];

vector <int> ans;

ll ask1_(int u, int v, int w) {
    cout<<1<<' '<<u<<' '<<v<<' '<<w<<'\n';
    cout.flush();
    ll res;
    cin>>res;
    return res;
}

int ask2_(int u, int v, int w) {
    cout<<2<<' '<<u<<' '<<v<<' '<<w<<'\n';
    cout.flush();
    int res;
    cin>>res;
    return res;
}

bool cmp_(int u, int v) {
    return s[u] > s[v];
}

void work_(int l, int r, vector <int> id) {
    sort(id.begin(), id.end(), cmp_);
    ans.push_back(l);

    if (!id.size()) {
        return;
    }

    int x = id[0];
    vector <int> L, R;

    for (int i = 1; i < id.size(); i++) {
        if (ask2_(l, x, id[i]) > 0) {
            L.push_back(id[i]);
        } else {
            R.push_back(id[i]);
        }
    }

    reverse(L.begin(), L.end());

    for (int x : L) {
        ans.push_back(x);
    }

    ans.push_back(x);

    for (int x : R) {
        ans.push_back(x);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    vector <int> A, B;

    for (int i = 2; i < n; i++) {
        if (ask2_(1, n, i) > 0) {
            A.push_back(i);
        } else {
            B.push_back(i);
        }

        s[i] = ask1_(1, n, i);
    }

    work_(1, n, A);
    work_(n, 1, B);

    cout<<0<<' '<<1<<' ';
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < n - 1; i++) {
        cout<<ans[i]<<' ';
    }

    cout<<'\n';
    cout.flush();
}