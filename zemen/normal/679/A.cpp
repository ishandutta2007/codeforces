#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

bool isPrime(int x) {
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

bool ask(int x) {
    cout << x << endl;
    string res;
    cin >> res;
    return res == "yes";
}

void solve(int N, int k) {
    for (int i = 2; i <= N; ++i) {
        if (!isPrime(i))
            continue;
        if (ask(k * i)) {
            cout << "composite" << endl;
            exit(0);
        }
    }
    cout << "prime" << endl;
    exit(0);
}

int main() {
    const int N = 100;
    //int c = 1;
    for (int i = 2; i <= N / 2; ++i) {
        if (isPrime(i)) {
            auto res = ask(i);
            if (res)
                solve(N / i, i);
            //cerr << c++ << ": " << i << '\n';
        }
    }
    cout << "prime" << endl;
}