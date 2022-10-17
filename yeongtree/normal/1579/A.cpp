#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;
        int a = 0, b = 0, c = 0;
        for(auto d : s)
        {
            if(d == 'A') ++a;
            if(d == 'B') ++b;
            if(d == 'C') ++c;
        }
        cout << (a + c == b ? "YES" : "NO") << '\n';
    }
}