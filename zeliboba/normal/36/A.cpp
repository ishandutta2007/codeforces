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
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int last = -1, per = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            if (last != -1) {
                if (per != -1) {
                    if (per != i - last) {
                        cout << "NO\n";
                        return 0;
                    }
                }
                per = i - last;
            }
            last = i;
        }
    }
    cout << "YES\n";
    return 0;
}