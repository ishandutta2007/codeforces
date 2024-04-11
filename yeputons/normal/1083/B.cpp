// Based on https://codeforces.com/contest/1083/submission/46870087
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::max;
using std::min;
using std::string;
using std::to_string;

int main()
{
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string t;
    cin >> t;
    long long v1 = 0;
    long long v2 = 0;
    long long ans = 0;
    bool cont = true;
    for (int i = 0; i < n; i++)
    {
            if (cont)
            {
                    v1 = v1 * 2;
                    v2 = v2 * 2;
                    if (s[i] == 'b')
                        v1 = v1 + 1;
                    if (t[i] == 'b')
                        v2 = v2 + 1;
                    if (v2 - v1 + 1 < k)
                    {
                            ans = ans + v2 - v1 + 1;
                    }
                    else
                    {
                            ans = ans + k;
                            cont = false;
                    }
            }
            else
            {
                    ans = ans + k;
            }
    }
    cout << ans << "\n";
    return 0;
}