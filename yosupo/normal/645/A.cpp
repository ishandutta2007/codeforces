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
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

void rot(string &s1, string &s2) {
    if (s1[0] == 'X') {
        swap(s1[0], s1[1]);
        return;
    }
    if (s1[1] == 'X') {
        swap(s1[1], s2[1]);
        return;
    }
    if (s2[1] == 'X') {
        swap(s2[1], s2[0]);
        return;
    }
    if (s2[0] == 'X') {
        swap(s2[0], s1[0]);
        return;
    }
}
int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    for (int i = 0; i < 10000; i++) {
        rot(s3, s4);
//        cout << s3 << endl << s4 << endl;
        if (s1 == s3 and s2 == s4) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}