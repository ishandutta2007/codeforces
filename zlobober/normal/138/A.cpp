#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

int k;
char vow[256];
int cnt = 0;

string suff(string s)
{
    int was = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (vow[s[i]])
            was++;
        if (was == k)
            return s.substr(i);
    }
    s.resize(4);
    for (int i = 0; i < 4; i++)
        s[i] = rand();
    return s;
}

int main()
{
    vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = 1;
    int n;
    cin >> n >> k;
    int was = 0;
    for (int i = 0; i < n; i++)
    {
        string s[4];
        for (int j = 0; j < 4; j++)
            cin >> s[j], cerr << (s[j] = suff(s[j])) << endl;
        if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
            was |= 8;
        else if (s[0] == s[1] && s[2] == s[3])
            was |= 4;
        else if (s[0] == s[2] && s[1] == s[3])
            was |= 2;
        else if (s[0] == s[3] && s[1] == s[2])
            was |= 1;
        else
            was = -1;
    }
    if (was == -1)
        cout << "NO";
    else if ((was & 3) == 3 || (was & 5) == 5 || (was & 6) == 6)
        cout << "NO";
    else if (was == 8)
        cout << "aaaa";
    else if ((was & 1) == 1)
        cout << "abba";
    else if ((was & 2) == 2)
        cout << "abab";
    else if ((was & 4) == 4)
        cout << "aabb";
    else
        assert(0);
}