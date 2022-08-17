#include <string>
#include <cassert>
#include <cstdio>
using namespace std;

const int N = 100500;
char buf[N];

int main()
{
    gets(buf);
    string s(buf);
    int n = s.size();
    string ones(n, '1');
    string ans;
    if (ones == s)
    {
        ones.resize(n - 1);
        ans = ones;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
            {
                ans = s.substr(0, i) + s.substr(i + 1);
                break;
            }
        assert(ans.empty() ^ 1);
    }
    printf("%s\n", ans.c_str());
    return 0;
}