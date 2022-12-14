#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <complex>
#include <array>
#include <ctime>
#include <cassert>
#include <set>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;
int a[7];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int k; cin >> k;
        for (int i = 0; i < 7; i++) cin >> a[i];
        int t = 0;
        for (int i = 0; i < 7; i++) t += a[i];
        int num_weeks = (k - 1) / t;
        int remain = k - num_weeks * t;
        int minPass = 7;
        for (int i = 0; i < 7; i++) {
            int cur = 0;
            for (int j = 0; j < 7; j++) {
                int at = (i + j) % 7;
                cur += a[at];
                if (cur >= remain) {
                    minPass = min(minPass,j + 1);
                    break;
                }
            }
        }
        cout << num_weeks * 7 + minPass << "\n";
    }
}