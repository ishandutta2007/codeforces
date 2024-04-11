#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
const int MAX_N = 990, MAX_I = 32;
bool e[MAX_N][MAX_N] = {};
int main(int argc, char *argv[]) {
    ll k;
    cin >> k;

    e[0][2] = true;
    e[0][3] = true;
    if (k & 1) {
        e[0][4] = true;
    }
    int l = 2;
    int nl;
    for (ll i = 1; i < MAX_I; i++) {
        nl = l+i+2;
        e[l][nl] = true;
        e[l][nl+1] = true;
        e[l+1][nl] = true;
        e[l+1][nl+1] = true;
        if (k & (1 << i)) {
            e[l][nl+2] = true;
            e[l+1][nl+2] = true;
        }
        for (int j = l+2; j < nl; j++) {
            e[j][nl+j-l+1] = true;
        }
        l = nl;
    }
    if (k&(1LL << MAX_I)) {
        e[nl][1] = true;
        e[nl+1][1] = true;
    }
    for (int i = nl+2; i < nl+MAX_I+2; i++) {
        e[i][1] = true;
    }
    cout << nl+MAX_I+2 << endl;
    for (int i = 0; i < nl+MAX_I+2; i++) {
        for (int j = 0; j < nl+MAX_I+2; j++) {
            cout << ((e[i][j] || e[j][i]) ? 'Y' : 'N');
        }
        cout << endl;
    }
    return 0;
}