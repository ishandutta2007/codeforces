#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int m, n;

int pole[5005][5005];

bool prime(int p)
{
    int o = (int)sqrt(p);
    for(int i = 2; i <= o; i++)
        if(!(p%i))
            return false;
    return true;
}

int main()
{
    char c;
    cin>>n>>m;
    for(int i = 0; i <= 2*max(m, n); i++)
        for(int j = 0; j <= 2*max(m, n); j++)
            pole[i][j] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%c", &c);
            //cout<<c;
            //cin>>c;
            if(c == '1')
                pole[i][j] = 1;
            else if(c == '0')
                pole[i][j] = 0;
            else
                j--;
        }
    }
    for(int i = 1; i <= 2*max(m, n); i++)
        for(int j = 1; j <= 2*max(m, n); j++)
            pole[i][j] += pole[i-1][j]+pole[i][j-1]-pole[i-1][j-1];
    int s, mi = 99999999, x, y;
    for(int k = 2; k <= min(m, n); k++)
    {
        if(!prime(k))
            continue;
        s = 0;
        for(int i = k; i < n+k && s < mi; i += k)
        {
            for(int j = k; j < m+k && s < mi; j += k)
            {
                x = pole[i][j]-pole[i-k][j]-pole[i][j-k]+pole[i-k][j-k];
                s += min(x, k*k-x);
            }
        }
        if(s < mi)
            mi = s;
    }
    cout<<mi<<endl;
    return 0;
}