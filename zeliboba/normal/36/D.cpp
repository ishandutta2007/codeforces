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
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,k;
    cin >> t >> k;
    for (int test = 0; test < t; ++test) {
        int n, m;
        cin >> n >> m;
        if (n > m)
            swap(m, n);
        if (k == 1) {
            if (n % 2 == 1 && m % 2 == 1) {
                cout << "-\n";
            } else {
                cout << "+\n";
            }
        } else {
            if (n <= k) {
                if ((m + n) % 2 == 0) {
                    cout << "-\n";
                } else
                    cout << "+\n";
            } else {
                if (n % (k + 1) == 0) { 
                    cout << "+\n";
                } else {
                    n %= (2 * k + 2);
                    m %= (2 * k + 2);
                    if (n < k + 1) {
                        if ((m + n) % 2 == 1) {
                            cout << "+\n";
                        } else {
                            cout << "-\n";
                        }
                    } else {
                        if ((m + n) % 2 == 1) {
                            cout << "-\n";
                        } else {
                            cout << "+\n";
                        }
                    }
                }
            }
        }
    }
    return 0;
}