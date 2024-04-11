#include <iostream>
#include <string>
#include <map>
using namespace std;

const double EPS = 5e-5;

map<string, int> M;

int main()
{
    int n, m;
    double k;
    cin >> n >> m >> k;
    string s;
    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> v;
        double b = v * k;
        if (b + EPS < 100)
        {
            b = 0;
            continue;
        }
        M[s] = (int)(b + EPS);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (M.find(s) == M.end())
            M[s] = 0;
    }
    cout << M.size() << endl;
    for (map<string, int> ::iterator it = M.begin(); it != M.end(); it++)
        cout << it->first << ' ' << it->second << endl;
}