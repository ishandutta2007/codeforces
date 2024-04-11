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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, k;
    cin >> n >> k;
    char s[100005];
    scanf("%s", s);
    int last = -1, cnt = 0;
    for (int i = 1; i < n && cnt < k; i += 2) {
        if (s[i] == '4' && i + 1 < n && s[i + 1] == '7') {
            ++cnt;
            s[i] = '7';
            if (i == last) {
                if ((k - cnt) % 2)
                    s[i] = '4';
                cnt = k;
            }
            last = i;
            i -= 2;
        } else if (s[i] == '7' && i && s[i - 1] == '4') {
            ++cnt;
            s[i] = '4';
            if (i == last) {
                if ((k - cnt) % 2)
                    s[i] = '7';
                cnt = k;
            }
            last = i;
            i -= 2;
        }
    }
    printf("%s\n", s);
    return 0;
}