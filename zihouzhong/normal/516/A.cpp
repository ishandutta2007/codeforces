#include <bits/stdc++.h>
using namespace std;

int n, cnt[10][10], num[10];
string s;

int main() {
    cnt[2][2]++;
    cnt[3][3]++;
    cnt[4][2] += 2, cnt[4][3]++;
    cnt[5][5]++;
    cnt[6][3]++, cnt[6][5]++;
    cnt[7][7]++;
    cnt[8][2] += 3, cnt[8][7]++;
    cnt[9][2]++, cnt[9][3] += 2, cnt[9][7]++;
    cin >> n >> s;
    for (char c : s) {
        for (int i = 0; i < 10; i++) {
            num[i] += cnt[c - '0'][i];
        }
    }
    cout << string(num[7], '7') + string(num[5], '5') + string(num[3], '3') + string(num[2], '2') << '\n';
    return 0;
}