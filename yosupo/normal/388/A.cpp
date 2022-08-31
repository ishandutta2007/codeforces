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

using namespace std;
typedef long long ll;

int main() {
    int n;
    int x[102] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        x[d]++;
    }
    int n2 = n;
    int r = 0;
    while (n2) {
        r++;
        int c = 0;
        for (int i = 0; i < 102; i++) {
            while (x[i] && c <= i) {
                x[i]--;
                c++;
                n2--;
            }
        }
    }
    cout << r << endl;
    return 0;
}