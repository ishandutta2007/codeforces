#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;

void out (vi & v) {
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vi p(n + 1);
    p.back() = 1;
    vi c(n);
    c[0] = 1;
    if (n == 2) {
        p[1] = 1;
    }
    if (n == 3) {
        p[1] = 1;
    }
    if (n == 4) {
        p[1] = 1;
    }
    if (n == 5) {
        p[2] = 1;
    }
    if (n == 6) {
        p[1] = 1;
    }
    if (n == 7) {
        p[3] = 1;
    }
    if (n == 8) {
        p[2] = 1;
        p[3] = 1;
        p[4] = 1;
    }
    if (n == 9) {
        p[4] = 1;
    }
    if (n == 10) {
        p[3] = 1;
    }
    if (n == 11) {
        p[2] = 1;
    }
    if (n == 12) {
        p[6] = 1;
        p[4] = 1;
        p[1] = 1;
    }
    if (n == 13) {
//        GF(2^13) x^13+x^4+x^3+x+1
        p[4] = 1;
        p[3] = 1;
        p[1] = 1;
    }
    if (n == 14) {
//        GF(2^14) x^14+x^10+x^6+x+1
        p[6] = 1;
        p[1] = 1;
        p[10] = 1;
    }
    if (n == 15) {
//        GF(2^15) x^15+x+1
        p[1] = 1;
    }
    if (n == 16) {
//        GF(2^16) x^16+x^12+x^3+x+1
        p[1] = 1;
        p[3] = 1;
        p[12] = 1;
    }
    if (n == 17) {
//        GF(2^17) x^17+x^3+1
        p[3] = 1;
    }
    if (n == 18) {
//        GF(2^18) x^18+x^7+1
        p[7] = 1;
    }
    if (n == 19) {
//        GF(2^19) x^19+x^5+x^2+x+1
        p[1] = 1;
        p[2] = 1;
        p[5] = 1;
    }
    if (n == 20) {
//        GF(2^20) x^20+x^3+1
        p[3] = 1;
    }
    if (n == 21) {
//        GF(2^21) x^21+x^2+1
        p[2] = 1;
    }
    if (n == 22) {
//        GF(2^22) x^22+x+1
        p[1] = 1;
    }
    if (n == 23) {
//        GF(2^23) x^23+x^5+1
        p[5] = 1;
    }
    if (n == 24) {
//        GF(2^24) x^24+x^7+x^2+x+1
        p[1] = 1;
        p[2] = 1;
        p[7] = 1;
    }
    if (n == 25) {
//        GF(2^25) x^25+x^3+1
        p[3] = 1;
    }
    if (n == 26) {
//        GF(2^26) x^26+x^6+x^2+x+1
        p[1] = 1;
        p[2] = 1;
        p[6] = 1;
    }
    if (n == 27) {
//        GF(2^27) x^27+x^5+x^2+x+1
        p[1] = 1;
        p[2] = 1;
        p[5] = 1;
    }
    if (n == 28) {
//        GF(2^28) x^28+x^3+1
        p[3] = 1;
    }
    if (n == 29) {
//        GF(2^29) x^29+x^2+1
        p[2] = 1;
    }
    if (n == 30) {
//        GF(2^30) x^30+x^23+x^2+x+1
        p[1] = 1;
        p[2] = 1;
        p[23] = 1;
    }
    if (n == 31) {
//        GF(2^31) x^31+x^3+1
        p[3] = 1;
    }
    if (n == 32) {
//        GF(2^32) x^32+x^22+x^2+x+1
        p[1] = 1;
        p[2] = 1;
        p[22] = 1;
    }
    if (n == 33) {
//        GF(2^33) x^33+x^13+1
        p[13] = 1;
    }
    if (n == 34) {
//        GF(2^34) x^34+x^8+x^4+x^3+1
        p[3] = 1;
        p[4] = 1;
        p[8] = 1;
    }
    if (n == 35) {
//        GF(2^35) x^35+x^2+1
        p[2] = 1;
    }
    if (n == 36) {
//        GF(2^36) x^36+x^11+1
        p[11] = 1;
    }
    if (n == 37) {
//        GF(2^37) x^37+x^6+x^4+x+1
        p[1] = 1;
        p[4] = 1;
        p[6] = 1;
    }
    if (n == 38) {
//        GF(2^38) x^38+x^6+x^5+x+1
        p[1] = 1;
        p[5] = 1;
        p[6] = 1;
    }
    if (n == 39) {
//        GF(2^39) x^39+x^4+1
        p[4] = 1;
    }
    if (n == 40) {
//        GF(2^40) x^40+x^5+x^4+x^3+1
        p[3] = 1;
        p[4] = 1;
        p[5] = 1;
    }
    if (n == 41) {
//        GF(2^41) x^41+x^3+1
        p[3] = 1;
    }
    if (n == 42) {
//        GF(2^42) x^42+x^7+x^4+x^3+1
        p[3] = 1;
        p[4] = 1;
        p[7] = 1;
    }
    if (n == 43) {
//        GF(2^43) x^43+x^6+x^4+x^3+1
        p[3] = 1;
        p[4] = 1;
        p[6] = 1;
    }
    if (n == 44) {
//        GF(2^44) x^44+x^6+x^5+x^2+1
        p[2] = 1;
        p[5] = 1;
        p[6] = 1;
    }
    if (n == 45) {
//        GF(2^45) x^45+x^4+x^3+x+1
        p[1] = 1;
        p[3] = 1;
        p[4] = 1;
    }
    if (n == 46) {
//        GF(2^46) x^46+x^8+x^7+x^6+1
        p[6] = 1;
        p[7] = 1;
        p[8] = 1;
    }
    if (n == 47) {
//        GF(2^47) x^47+x^5+1
        p[5] = 1;
    }
    if (n == 48) {
//        GF(2^48) x^48+x^9+x^7+x^4+1
        p[4] = 1;
        p[7] = 1;
        p[9] = 1;
    }
    if (n == 49) {
//        GF(2^49) x^49+x^9+1
        p[9] = 1;
    }
    if (n == 50) {
//        GF(2^50) x^50+x^4+x^3+x^2+1
        p[2] = 1;
        p[3] = 1;
        p[4] = 1;
    }
    for (int i = 1; i < p.size(); ++i)
        cout << p[i] << " ";
    cout << endl;
    out(c);
    return 0;
}