#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,a,b;
    cin >> n >>a >>b;
    int na = a,nb = b;
    string s;
    cin >> s;
    char last = '.';
    int ans=0;
    for (char i:s)
    {
        if (i == '*')
        {
            last = '.';
        }
        else if (i == '.')
        {
            if (last == '.')
            {
                if (a>=b)
                {
                    last = 'A';
                    --a;
                }
                else if (a < b)
                {
                    last = 'B';
                    --b;
                }
            }
            else if (last == 'A')
            {
                last = 'B';
                --b;
            }
            else if (last == 'B')
            {
                last = 'A';
                --a;
            }
        }
    }
    //cout << "A = " << a << " , b = " << b << endl;
    a = max(a,0);
    b = max(b,0);
    cout << na + nb - a - b << endl;
}