// https://codeforces.com/contest/1093/submission/47171526
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
    for (int i = 0; i < n; i++)
    {
            int q;
            cin >> q;
            cout << q / 2 << "\n";
    }
    return 0;
}