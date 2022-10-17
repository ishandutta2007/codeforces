#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;
    for(int i = 1; i < n; ++i)
    {
        if(s[i - 1] > s[i]){cout << "YES\n" << i << ' ' << i + 1; return 0;}
    }

    cout << "NO";
    return 0;
}