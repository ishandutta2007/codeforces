#include <bits/stdc++.h>
using namespace std;

const int INF = 123456789;

int p[8];

int main ()
{
    int n;
    cin >> n;
    for (int i=0;i<8;++i)
    {
        p[i] = INF;
    }
    while (n--)
    {
        int x;
        string s;
        cin >> x >> s;
        int mask = 0;
        for (char i:s)
        {
            mask |= (1<<(i-'A'));
        }
        p[mask] = min(p[mask],x);
    }
    int cost = INF;
    for (int i=0;i<8;++i)
    {
        if (i == 7)
        {
            cost = min(cost,p[i]);
        }
    }
    for (int i=0;i<8;++i)
    {
        for (int j=0;j<8;++j)
        {
            if ((i|j) == 7)
            {
                cost = min(cost,p[i]+p[j]);
            }
        }
    }
    for (int i=0;i<8;++i)
    {
        for (int j=0;j<8;++j)
        {
            for (int k=0;k<8;++k)
            {
                if ((i|j|k) == 7)
                {
                    cost = min(cost,p[i]+p[j]+p[k]);
                }
            }
        }
    }
    if (cost == INF) cout << -1 << endl;
    else cout << cost << endl;
}