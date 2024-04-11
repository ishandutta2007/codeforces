#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
#include <string>

using namespace std;
typedef long long ll;

template <int N>
struct Primes {
    bool used[N];
    Primes() {
        used[0] = used[1] = true;
        for (int i = 2; i < N; i++) {
            for (int j = 2*i; j < N; j += i) {
                used[j] = true;
            }
        }
    }
};

const int MN = 2000000;
typedef long double R;
Primes<MN> pr;
int c1[MN], c2[MN];

string tostring(int i) {
    if (!i) {
        return "0";
    }
    string s;
    while (i) {
        s += '0' + (i % 10);
        i /= 10;
    }
    return s;
}
int main() {
    c1[0] = 0; c2[0] = 0;
    for (int i = 1; i < MN; i++) {
        c1[i] = c1[i-1]; c2[i] = c2[i-1];
        if (!pr.used[i]) {
            c1[i]++;
        }
        string s = tostring(i);
        string rs = s;
        reverse(s.begin(), s.end());
        if (s == rs) {
            c2[i]++;
        }
    }

    ll a, b;
    cin >> a >> b;
    int ma = -1;
    for (int i = 1; i < MN; i++) {
        if (b*c1[i] <= a*c2[i]) {
            ma = max(ma, i);
        }
    }
    cout << ma << endl;
    return 0;
}