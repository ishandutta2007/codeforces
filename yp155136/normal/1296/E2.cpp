#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
const int P = 2 * N;

int lc[P], rc[P], mx[P];
int ptr = 0;

void build(int now, int L, int R) {
    if (L == R) {
        return;
    }
    int mid = (L + R) >> 1;
    lc[now] = (++ptr);
    build(lc[now], L, mid);
    rc[now] = (++ptr);
    build(rc[now], mid + 1, R);
    return;
}

void modify(int now, int L, int R, int pos, int val) {
    if (L == R) {
        mx[now] = val;
        return;
    }
    int mid = (L + R) >> 1;
    if (pos <= mid) modify(lc[now], L, mid, pos, val);
    else modify(rc[now], mid + 1, R, pos, val);
    mx[now] = max(mx[ lc[now] ], mx[ rc[now] ]);
}

int query(int now, int L, int R, int l, int r) {
    if (l > R || L > r) return 0;
    else if (l <= L && R <= r) return mx[now];
    int mid = (L + R) >> 1;
    return max(query(lc[now], L, mid, l, r), query(rc[now], mid + 1, R, l, r));
}

vector<int> pos[26];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int root = (++ptr);
    build(root, 1, n);
    for (int i = 1; i <= n; ++i) {
        char c = s[i - 1];
        pos[ c - 'a' ].push_back(i);
    }
    for (int i = 0; i < 26; ++i) {
        for (int id: pos[i]) {
            int val = query(root, 1, n, id, n);
            modify(root, 1, n, id, val + 1);
        }
    }
    cout << query(root, 1, n, 1, n) << endl;
    for (int i = 1; i <= n; ++i) {
        cout << query(root, 1, n, i, i) << " \n"[i == n];
    }
}