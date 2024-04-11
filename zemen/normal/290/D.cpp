#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

int main() {
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < (int) s.length(); ++i)
        if (tolower(s[i]) < 97 + n)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    cout << s;
}