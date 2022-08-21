#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') break;
        ans++;
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '<') break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}