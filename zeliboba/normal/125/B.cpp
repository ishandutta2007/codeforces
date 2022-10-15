#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main () {
    string s;
    cin >> s;
    int h = 0;
    for (int i = 0; i < s.size(); ++i) {
//        cerr << i << " " << s[i] << endl;
        if (s[i + 1] == '/') {
            h -= 2;
            string s1(s.begin() + i, s.begin() + i + 4);
            cout << string(h, ' ') << s1;
            i += 3;
        } else {
            string s1(s.begin() + i, s.begin() + i + 3);
            cout << string(h, ' ') << s1;
            h += 2;
            i += 2;
        }
        cout << endl;
    }
    return 0;
}