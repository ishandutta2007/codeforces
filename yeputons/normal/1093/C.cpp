// Based on https://codeforces.com/contest/1093/submission/47096734
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
    vector<long long> b((n / 2) + 1);
    vector<long long> a(n + 1);
    for (int i = 1; i < (int)b.size(); i++)
        cin >> b[i];
    int k = 0;
    for (int i = (int)a.size() - 1; i >= (n / 2) + 1; i--)
    {
            a[i] = b[k + 1];
            k = k + 1;
    }
    a[n / 2] = a[(n / 2) + 1] / 2;
    if (a[(n / 2) + 1] % 2 == 1)
        a[(n / 2) + 1] = (a[(n / 2) + 1] / 2) + 1;
    else
        a[(n / 2) + 1] = a[(n / 2) + 1] / 2;
    for (int i = (n / 2) + 2; i < (int)a.size(); i++)
    {
            long long temp = a[i - 1];
            long long t = a[(int)a.size() - i + 1];
            long long temp2 = a[i] - temp;
            long long t2 = a[i] - t;
            if (temp2 <= a[(int)a.size() - i + 1])
            {
                    a[(int)a.size() - i] = temp2;
                    a[i] = temp;
            }
            else
                if (t2 >= a[i - 1])
                {
                        a[i] = t2;
                        a[(int)a.size() - i] = t;
                }
    }
    for (int i = 1; i < (int)a.size(); i++)
        cout << to_string(a[i]) + " ";
    cout << "\n";
    return 0;
}