#include <iostream>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    char c = s.back();
    s.pop_back();
    ll n = stoll(s); n--;
    ll off[6] = {4, 5, 6, 3, 2, 1};
    ll ans = off[c-'a'];
    ans += (n/4)*16;
    ans += (n%2)*7;
    cout << ans << endl;
    return 0;
}