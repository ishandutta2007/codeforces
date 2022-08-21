#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
set<char> cs;
string s;
int n;
bool solve() {
    if (n%2) {
        if (!cs.count(s[n/2])) {
            return false;
        }
    }
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) return false;
        if (!cs.count(s[i])) return false;
    }
    return true;
}

int main() {
    cin >> s;
    string css = "AHIMOTUVWXY";
    for (char c: css) {
        cs.insert(c);
    }
    n = s.size();
    if (solve()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}