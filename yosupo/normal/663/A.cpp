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

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

int main() {
    ll a = 0, b = 0;
    bool f = true;
    vector<pair<string, string>> v;
    while (true) {
        string s, t;
        cin >> s >> t;
        v.push_back(make_pair(s, t));
        if (f) {
            a++;
        } else {
            b++;
        }
        if (t == "=") break;
        if (t == "+") f = true;
        else f = false;
    }
    ll n;
    cin >> n;
    ll x = a, y = a*n;
    ll z = n+b, w = n+b*n;
    if (z <= x and x <= w) {
        cout << "Possible" << endl;
        ll u = x - z;
        bool f = true;
        for (auto st: v) {
            string s, t;
            tie(s, t) = st;
            ll d = 0;
            if (f) {
                d = 1;
            } else {
                d = 1;
                ll o = min(n-1, u);
                d += o;
                u -= o;
            }
            cout << d << " " << t << " ";
            if (t == "+") f = true;
            else f = false;
        }
        cout << n << endl;
        return 0;
    }
    if (x <= z and z <= y) {
        cout << "Possible" << endl;
        ll u = z - x;
        bool f = true;
        for (auto st: v) {
            string s, t;
            tie(s, t) = st;
            ll d = 0;
            if (f) {
                d = 1;
                ll o = min(n-1, u);
                d += o;
                u -= o;
            } else {
                d = 1;
            }
            cout << d << " " << t << " ";
            if (t == "+") f = true;
            else f = false;
        }
        cout << n << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}