#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T; cin >> n >> T;
    string s; cin >> s;
    int ps[n + 1]{};
    for(int i = 0; i < n; ++i) ps[i + 1] = ps[i] + s[i] - 'a' + 1;

    while(T--)
    {
        int l, r; cin >> l >> r; --l;
        cout << ps[r] - ps[l] << '\n';
    }
}