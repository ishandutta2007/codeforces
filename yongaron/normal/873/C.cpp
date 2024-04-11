#include <iostream>

using namespace std;

int n, m, k;
int a[105][105], s[105][105];
int ma[105], mai[105];

int main()
{
    cin>>n>>m>>k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            s[j][i] = 0;
            if(a[j][i] == 1)
            {
                for(int l = 0; l < k && j+l < n; l++)
                {
                    if(a[j+l][i] == 1)
                        s[j][i]++;
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        ma[i] = 0;
        mai[i] = -1;
        for(int j = 0; j < n; j++)
        {
            if(s[j][i] > ma[i])
            {
                ma[i] = s[j][i];
                mai[i] = j;
            }
        }
    }
    int x = 0, y = 0;
    for(int i = 0; i < m; i++)
    {
        x += ma[i];
        for(int j = 0; j < mai[i]; j++)
        {
            if(a[j][i] == 1)
                y++;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}