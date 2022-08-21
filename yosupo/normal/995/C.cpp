#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

using D = int;
const D EPS = 0;

int sgn(D a) { return (abs(a) <= EPS) ? 0 : (a < 0 ? -1 : 1); }
int sgn(D a, D b) { return sgn(a-b); }
struct Pt2 {
    D x, y;
    Pt2(D _x = D(), D _y = D()) : x(_x), y(_y) {}
    Pt2 operator+(const Pt2 &r) const { return Pt2(x+r.x, y+r.y); }
    Pt2 operator-(const Pt2 &r) const { return Pt2(x-r.x, y-r.y); }
    Pt2 operator*(const Pt2 &r) const { return Pt2(x*r.x-y*r.y, x*r.y+y*r.x); }

    Pt2 operator*(const D &r) const { return Pt2(x*r, y*r); }

    Pt2& operator+=(const Pt2 &r) { return *this=*this+r; }
    Pt2& operator-=(const Pt2 &r) { return *this=*this-r; }
    Pt2& operator*=(const Pt2 &r) { return *this=*this*r; }
    Pt2& operator*=(const D &r) { return *this=*this*r; }
    
    Pt2 operator-() const { return Pt2(-x, -y); }

    bool operator<(const Pt2 &r) const { return 2*sgn(x, r.x)+sgn(y, r.y)<0; }
    bool operator==(const Pt2 &r) const { return sgn((*this-r).rabs()) == 0; }

    D norm() const { return x*x + y*y; }
    D rabs() const { return max(std::abs(x), std::abs(y)); } // robust abs

    pair<D, D> to_pair() const { return make_pair(x, y); }
};
using P = Pt2;


struct Node {
    P p;
    int id;
    bool neg;
    Node* l;
    Node* r;
};

Node* tr[3] = {nullptr, nullptr, nullptr};

int get_ty(P p) {
    if (p.x >= 0 && p.y <= 2 * p.x) return 0;
    if (p.x <= 0 && p.y <= -2 * p.x) return 2;
    return 1;
}

void add(Node *n) {
    if (n->p.y < 0) {
        n->p = -(n->p);
        n->neg = !(n->neg);
    }
    int ty = get_ty(n->p);
    auto m = tr[ty];
    if (m == nullptr) {
        tr[ty] = n;
        return;
    }
    n->neg = !(n->neg);
    tr[ty] = nullptr;
    add(new Node{m->p - n->p, -1, false, n, m});
}

V<char> sig;
void dfs(Node *n, bool neg) {
    if (n == nullptr) return;
    if (n->neg) neg = !neg;
    if (n->id >= 0) {
//        cout << "OK! " << n->id << " " << neg << endl;
        sig[n->id] = neg;
    }
    dfs(n->l, neg);
    dfs(n->r, neg);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n;
    cin >> n;
    sig = V<char>(n);
    V<P> mv(n);
    for (int ph = 0; ph < n; ph++) {
        D x, y;
        cin >> x >> y;
        mv[ph] = P(x, y);
        add(new Node{mv[ph], ph, false, nullptr, nullptr});
    }

    for (int ph = 0; ph < 3; ph++) {
//        cout << "FIND! " << ph << endl;
        dfs(tr[ph], (ph % 2) == 0);
    }

    P p = P(0, 0);
    for (int ph = 0; ph < n; ph++) {
        if (sig[ph]) p += mv[ph];
        else p -= mv[ph];
    }
//    cout << "LAST : " << p.x << " " << p.y << endl;

    for (int ph = 0; ph < n; ph++) {
        if (sig[ph]) cout << "1 ";
        else cout << "-1 ";
    }
    cout << endl;
    return 0;
}