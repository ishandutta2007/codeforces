#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct Node {
    using NP = Node*;
    NP ch[2];
    int sz;
    Node() {
        ch[0] = ch[1] = nullptr;
        sz = 0;
    }
    void add(uint x, int k) {
        if (k == -1) {
            sz++;
            return;
        }
        int f = (x >> k) & 1;
        if (ch[f] == nullptr) {
            ch[f] = new Node();
        }
        ch[f]->add(x, k-1);
        sz++;
    }

    uint get(uint x, int k) {
        if (k == -1) {
            sz--;
            return 0;
        }
        int f = (x >> k) & 1;
        if (ch[f] == nullptr || ch[f]->sz == 0) {
            f = 1-f;
        }
        sz--;
        return ch[f]->get(x, k-1) + (f << k);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    Node* tr = new Node();
    V<uint> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        uint x;
        cin >> x;
        tr->add(x, 29);
    }

    for (int i = 0; i < n; i++) {
        cout << (a[i] ^ tr->get(a[i], 29)) << " ";
    }
    cout << endl;
    return 0;
}