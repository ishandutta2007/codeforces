#include <iostream>

using namespace std;

int m, n;
char flag[101][101];

bool vodo();
bool svis();

int main()
{
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>flag[i][j];
    if(vodo() || svis())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
bool vodo()
{
    int r = 0, b = 0, g = 0;
    int lr = 0;
    char last = flag[0][0];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(flag[i][j] != last)
            {
                if(last == 'R' && !r && j == 0)
                {
                    r = i-lr;
                    lr = i;
                    last = flag[i][j];
                    continue;
                }
                if(last == 'G' && !g && j == 0)
                {
                    g = i-lr;
                    lr = i;
                    last = flag[i][j];
                    continue;
                }
                if(last == 'B' && !b && j == 0)
                {
                    b = i-lr;
                    lr = i;
                    last = flag[i][j];
                    continue;
                }
                return false;
            }
        }
    }
    if(last == 'R' && !r && r == 0)
    {
        r = n-lr;
    }
    else if(last == 'G' && !g && g == 0)
    {
        g = n-lr;
    }
    else if(last == 'B' && !b && b == 0)
    {
        b = n-lr;
    }
    else
    {
        return false;
    }
    if(r == b && b == g)
        return true;
    return false;
}
bool svis()
{
    int r = 0, b = 0, g = 0;
    int lr = 0;
    char last = flag[0][0];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(flag[j][i] != last)
            {
                if(last == 'R' && !r && j == 0)
                {
                    r = i-lr;
                    lr = i;
                    last = flag[j][i];
                    continue;
                }
                if(last == 'G' && !g && j == 0)
                {
                    g = i-lr;
                    lr = i;
                    last = flag[j][i];
                    continue;
                }
                if(last == 'B' && !b && j == 0)
                {
                    b = i-lr;
                    lr = i;
                    last = flag[j][i];
                    continue;
                }
                return false;
            }
        }
    }
    if(last == 'R' && !r && r == 0)
    {
        r = m-lr;
    }
    else if(last == 'G' && !g && g == 0)
    {
        g = m-lr;
    }
    else if(last == 'B' && !b && b == 0)
    {
        b = m-lr;
    }
    else
    {
        return false;
    }
    if(r == b && b == g)
        return true;
    return false;
}