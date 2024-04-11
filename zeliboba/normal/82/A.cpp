#include <cstdio>
#include <cstdlib>
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

int main() {
    int n;
    cin >> n;
    --n;
    vector<string> vs(5);
    vs[0] = "Sheldon";
    vs[1] = "Leonard";
    vs[2] = "Penny";
    vs[3] = "Rajesh";
    vs[4] = "Howard";
    ll cur = 5;
    while (n >= cur) {
        n -= cur;
        cur *= 2;
    }
    n /= (cur / 5);
    cout << vs[n] << endl;
    return 0;
}