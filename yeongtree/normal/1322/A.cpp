#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0;
    int ans = 0;
    for(auto i : s)
    {
        if(i == '(') ++a;
        else --a;
        if(a < 0 || b < 0) ++ans;
        b = a;
    }
    if(a) {cout << -1; return 0;}
    cout << ans; return 0;
}