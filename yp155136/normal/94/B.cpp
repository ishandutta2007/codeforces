#include <bits/stdc++.h>
using namespace std;

bool adj[6][6];

int main ()
{
    int m;
    cin >> m;
    for (int i=0;m>i;i++)
    {
        int a,b;
        cin >> a >>b;
        adj[a][b] = adj[b][a] = true;
    }
    int n=5;
    for (int i=1;n>=i;i++)
    {
        for (int j=i+1;n>=j;j++)
        {
            for (int k=j+1;n>=k;k++)
            {
                if (adj[i][j] && adj[j][k] && adj[k][i] || !adj[i][j] && !adj[j][k] && !adj[k][i])
                {
                    //cout << "i = " << i << " , j = " << j << " , k = " << k << endl;
                    puts("WIN");
                    return 0;
                }
            }
        }
    }
    puts("FAIL");
    return 0;
}