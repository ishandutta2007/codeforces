#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    string s[n], t[m];
    for(auto &i : s) cin >> i;
    for(auto &i : t) cin >> i;

    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        --x;
        cout << s[x % n] << t[x % m] << '\n';
    }
}