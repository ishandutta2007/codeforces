#include <iostream>
#include <string>
using namespace std;

const int N = 150;
const int E = 26;

int D[N][E * N];

const int MOD = 1000 * 1000 * 1000 + 7;

int main()
{
    D[0][0] = 1;
    for (int i = 1; i < N - 10; i++)
        for (int j = 0; j < N * E; j++)
            for (int k = 0; k < E && j - k >= 0; k++)
                D[i][j] = (D[i][j] + D[i - 1][j - k]) % MOD;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        int q = 0;
        for (int j = 0; j < s.size(); j++)
            q += s[j] - 'a';
        cout << D[s.size()][q] - 1 << endl;
    }
    return 0;

}