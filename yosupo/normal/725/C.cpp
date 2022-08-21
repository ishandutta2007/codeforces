#include <iostream>

using namespace std;

string s;

char res[26];
/*
 0,1,2,...,12
 25,24,...,13
 */

void solve(int l, int r) {
    int di = r-l-1;
    int pos = 12-di/2;
    int i = l;
    while (true) {
        if (i != r) {
            res[pos] = s[i];
            pos = (pos+1)%26;
        }
        i = (i+1)%27;
        if (i == l) break;
    }
}

int main() {
    cin >> s;
    int used[26];
    fill_n(used, 26, -1);
    for (int i = 0; i < 27; i++) {
        int c = s[i]-'A';
        if (used[c] == -1) {
            used[c] = i;
            continue;
        }
        if (used[c] == i-1) {
            cout << "Impossible" << endl;
        } else {
            solve(used[c], i);
            for (int i = 0; i < 13; i++) {
                cout << res[i];
            } cout << endl;
            for (int i = 25; i >= 13; i--) {
                cout << res[i];
            } cout << endl;
        }
        break;
    }
    return 0;
}