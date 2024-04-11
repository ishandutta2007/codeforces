#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 250;
bool wub[N];

int main()
{
    string S;
    cin >> S;
    int n = S.size();
    string T;
    for (int i = 0; i < n; i++)
    {
        if (S.substr(i, 3) == "WUB")
            T.push_back(' '), i += 2;
        else
            T.push_back(S[i]);
    }

    while (!T.empty() && T[0] == ' ')
        T = T.substr(1);
    while (!T.empty() && T[T.size() - 1] == ' ')
        T.resize(T.size() - 1);
    for (int i = 0; i < T.size(); i++)
        while (T[i] == ' ' && T[i + 1] == ' ')
            T = T.substr(0, i) + ' ' + T.substr(i + 2);
    cout << T << endl;
}