// https://codeforces.com/problemset/problem/1584/D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int n;

map<pair<int, int>, long long> mp;

long long ask(int l, int r){
    if (r > n) return -1;
    if (l + 1 == r) return 0;
    if (mp.find({l, r}) != mp.end()) return mp[{l, r}];
    cout << "? " << l + 1 << " " << r << endl;
    fflush(stdout);
    long long res;
    cin >> res;
    return mp[{l, r}] = res;
}

void answer(int l, int r, int k){
    cout << "! " << l + 1 << " " << r + 1 << " " << k + 1 << endl;
    fflush(stdout);
}

int get(long long total){
    int x = sqrtl(2 * total);
    if (x * 1ll * x + x > 2 * total) x--;
    return x;
    // l * l + l = 2total
}

void solve(int test_ind){
    mp.clear();
    cin >> n;
    int l = 1, r = n;
    long long total = ask(0, n);
    while (l + 1 < r){
        int m = (l + r) / 2;
        if (ask(0, m) == 0){
            l = m;
        } else {
            r = m;
        }
    }
    l--;
    // 0 to l - 1 is ok, then l to j-1 is reversed then j to k is reversed
    // total = j * (j+1) / 2 + (k - j) * (k - j + 1) / 2

    // a * (a + 1) / 2 + b * (b + 1) / 2 = total
    int dl = ask(l, n) - ask(l + 1, n); // 2 1
    int dr = ask(l + dl + 1, n) - ask(l + dl + 2, n);
    answer(l, l + dl + 1, l + dl + dr + 1);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}