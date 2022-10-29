#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

const int X = 200006;

string GG[X];

int main ()
{
    int n,k;
    cin >>n >> k;
    string s;
    cin >> s;
    if (!k)
    {
        cout << s <<endl;
        return 0;
    }
    int tmp=X;
    int now=0;
    int L=0;
    while (tmp--)
    {
        k--;
        bool found = false;
        for (;n-1>L;L++)
        {
            if (s[L] == '4' && s[L+1] == '7')
            {
                if (L%2 == 1)
                {
                    s[L] = '7';
                }
                else if (L%2==0)
                {
                    s[L+1] = '4';
                }
                found = true;
                L -= 5;
                break;
            }
        }
        L = max(L,0);
        if (!found)
        {
            cout << s << endl;
            return 0;
        }
        if (!k) break;
    }
    if (!k)
    {
        cout << s << endl;
        return 0;
    }
    if (true)
    {
        L=0;
        map<string,int> mp;
        int T=0;
        while (mp.find(s) == mp.end())
        {
            GG[T] = s;
            mp[s] = T;
            T++;
            for (;n-1>L;L++)
            {
                if (s[L] == '4' && s[L+1] == '7')
                {
                    if (L%2 == 1)
                    {
                        s[L] = '7';
                    }
                    else if (L%2==0)
                    {
                        s[L+1] = '4';
                    }
                    L -= 5;
                    L = max(L,0);
                    break;
                }
            }
        }
        int cycle = T;
        k %= T;
        cout << GG[k] << endl;
        return 0;
    }
}