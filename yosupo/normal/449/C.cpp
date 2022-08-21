#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;

const int MN = 101000;

template <int N>
struct Primes {
    bool used[N];
    vector<int> p;
    Primes() {
        used[0] = used[1] = true;
        for (int i = 2; i < N; i++) {
            if (!used[i]) {
                p.push_back(i);
            }
            for (int j = 2*i; j < N; j += i) {
                used[j] = true;
            }
        }
    }
};
typedef pair<int, int> P;
Primes<MN> p;
vector<P> res;
int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    reverse(p.p.begin(), p.p.end());
    for (int d: p.p) {
        set<int> u;
        for (int i = d; i <= n; i+= d) {
            if (s.count(i)) {
                u.insert(i);
            }
        }
        if (u.size() < 2) continue;
        if (u.size() % 2 == 1) {
            u.erase(d*2);
        }
        vector<int> v(u.begin(), u.end());
        for (int i = 0; i < v.size()/2; i++) {
            s.erase(v[i*2]); s.erase(v[i*2+1]);
            res.push_back(P(v[i*2], v[i*2+1]));
        }
    }

    cout << res.size() << endl;
    for (P p: res) {
        printf("%d %d\n", p.first, p.second);
    }
}