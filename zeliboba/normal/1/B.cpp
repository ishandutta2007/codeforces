#include<iostream>
#include<string>
using namespace std;

bool isdig (char c) {
    return c >= '0' && c <= '9';
}

long long mpow (int x, int n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2)
            res *= x;
        n /= 2;
        x *= x;
    }
    return res;
}

long long count (int n) {
    return 26 * (mpow(26, n) - 1) / 25;
}

string getstring (int n) {
    int l = 0, r = 7;
    while (r - l > 1) {
        int x = (r + l) / 2;
        if (count(x) < n)
            l = x;
        else
            r = x;
    }
    n -= count(l) + 1;
    string s(l + 1, 'A');
    for (int i = 0; i <= l; ++i) {
        s[l - i] = (n % 26) + 'A';
        n /= 26;
    }
    return s;
}

int main () {
    int n;
    cin >> n;
    for (int test = 0; test < n; ++test) {
        string s;
        cin >> s;
        bool rctype = (s[0] == 'R');
        int curpos = 1, n1 = 0, n2 = 0;
        while (curpos < s.size() && isdig(s[curpos])) {
            n1 = n1 * 10 + s[curpos] - '0';
            ++curpos;
        }
        if (curpos >= s.size() || s[curpos] != 'C')
            rctype = false;
        ++curpos;
        while (curpos < s.size() && isdig(s[curpos])) {
            n2 = n2 * 10 + s[curpos] - '0';
            ++curpos;
        }
        if (curpos < s.size() || n1 == 0 || n2 == 0)
            rctype = false;
        if (rctype) {
            cout << getstring(n2) << n1 << endl;
        } else {
            long long curpos = 0;
            int n1 = 0;
            while (curpos < s.size() && !isdigit(s[curpos])) {
                n1 = n1 * 26 + s[curpos] - 'A';
                ++curpos;
            }
            cout << "R" << string(s.begin() + curpos, s.end()) << "C" << count(curpos - 1) + n1 + 1 << endl; 
        }
    }
    return 0;
}