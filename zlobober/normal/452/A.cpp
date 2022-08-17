#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string P[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
    int n;
    cin >> n;
    string x;
    cin >> x;
    for (int i = 0; i < 8; i++)
    {
        if (P[i].size() == n)
        {
            bool bad = false;
            for (int j = 0; j < n; j++)
                if (P[i][j] != x[j] && x[j] != '.')
                    bad = true;
            if (!bad)
            {
                cout << P[i] << endl;
                return 0;
            }
        }
    }

}