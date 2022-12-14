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

void out(int x, int y) {
    cout << char('a' - 1 + x) << y << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int x = 1, y = 1;
    out(x, y);
    bool at = false;
    bool st = false;
    bool special = n == 63;
    if (n == 63) n = 61;
    while (n > 2) {
        if (x == 1 && y == 7) {
            st = true;
            at = false;
        }
        if (st) {
            if (!at) {
                if (y < 8) y++;
                else x++, at = true;
            } else {
                if (y > 7) y--;
                else x++, at = false;
            }
        } else {
            if (!at) {
                if (x < 8) x++;
                else y++, at = true;
            } else {
                if (x > 1) x--;
                else y++, at = false;
            }
        }
        out(x, y);
        n--;
    }
    if (special) {
        out(8, 7);
        out(7, 7);
        out(7, 8);
        out(8, 8);
        return 0;
    }
    if (st) {
        if (y == 7) {
            out(8, 7);
            out(8, 8);
        } else {
            out(7, 8);
            out(8, 8);
        }
    } else {
        if (x == 8) {
            out(8, 7);
            out(8, 8);
        } else {
            out(x, 8);
            out(8, 8);
        }
    }

}