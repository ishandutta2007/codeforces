#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    char now = 'a';
    for (char &c:s)
    {
        if (c <= now)
        {
            c = now;
            now++;
            if (now == 'z' + 1)
            {
                cout <<s <<endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}