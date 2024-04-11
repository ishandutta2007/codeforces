#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
const int N = 2100000;

char s1[N],s2[N];

int main() {
    int n;
    cin >> n;
    scanf("%s%s",s1,s2);
    int a[2][2];
    memset(a,0,sizeof(a));
    for (int i = 0; i < 2*n; ++i)
        a[s1[i]-'0'][s2[i]-'0']++;
    int m = min(a[1][0],a[0][1]);
    a[1][0] -= m;
    a[0][1] -= m;
    if (a[1][1] & 1) {
        if (a[0][1] == 0) {
            cout << "First\n";
            return 0;
        } else {
            --a[0][1];
        }
    }
    if (a[1][0] > 0) {
        cout << "First\n";
        return 0;
    }
    if (a[0][1] <= 1) {
        cout << "Draw\n";
        return 0;
    }
    cout << "Second\n";
    return 0;
}