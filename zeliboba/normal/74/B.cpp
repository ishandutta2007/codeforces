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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n, z, k, dir = 1;
    cin >> n >> z >> k;
    string s;
    cin >> s >> s;
    if (s[0] == 'h')
        dir = -1;
    cin >> s;
    int laststep = 1;
    if (s.size() == 1) {
        cout << "Stowaway\n";
        return 0;
    }
    bool nostop = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (dir > 0 && z > k || dir < 0 && z > k) {
                z = n;
            } else
                z = 1;
        } else {
            if (dir > 0 && k != n || k == 1) {
                z = 1;
            } else {
                z = n;
            }
        }
        if (k + dir > 0 && k + dir <= n)
            k += dir;
        else {
            dir = -dir;
            k += dir;
        }
        if (k == z) {
            laststep = i + 1;
            nostop = true;
            break;
        }
    }
    if (nostop) {
        cout << "Controller " << laststep << "\n";
        return 0;
    }
    cout << "Stowaway\n";
    return 0;
}