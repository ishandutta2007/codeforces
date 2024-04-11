#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--)
    {
        int a,b;
        char c,d;
        cin >>a>>b>>c>>d;
        --a;
        --b;
        for (int i=a;b>=i;i++)
        {
            if (s[i] == c) s[i] = d;
        }
    }
    cout << s << endl;
}