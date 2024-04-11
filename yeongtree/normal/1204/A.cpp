#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    if(n == 1 && s[0] == '0') {cout << 0; return 0;}
    if(n & 1)
    {
        bool flag = false;
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == '1') flag = true;
        }
        if(!flag) --n;
    }
    cout << (n + 1) / 2;
}