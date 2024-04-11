#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int m, n;
char mapa[100][100];
int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int st[2], ex[2], p[2], perm[4] = {1,2,3,4};
string s;

bool isOk(int a, int b)
{
    if(a >= 0 && b >= 0 && a < n && b < m)
        return true;
    return false;
}

int main()
{
    cin>>n>>m;
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>mapa[i][j];
            if(mapa[i][j] == 'S')
            {
                st[0] = i;
                st[1] = j;
            }
        }
    }
    cin>>s;
    for(int i = 0; i < 24; i++)
    {
        bool ok = false;
        p[0] = st[0];
        p[1] = st[1];
        /*for(int j = 0; j < 4; j++)
            cout<<perm[j]<<" ";
        cout<<endl;*/
        for(int j = 0; j < s.size(); j++)
        {
            int dir[2];
            if(s[j] == '0')
            {
                dir[0] = d[perm[0]-1][0];
                dir[1] = d[perm[0]-1][1];
            }
            if(s[j] == '1')
            {
                dir[0] = d[perm[1]-1][0];
                dir[1] = d[perm[1]-1][1];
            }
            if(s[j] == '2')
            {
                dir[0] = d[perm[2]-1][0];
                dir[1] = d[perm[2]-1][1];
            }
            if(s[j] == '3')
            {
                dir[0] = d[perm[3]-1][0];
                dir[1] = d[perm[3]-1][1];
            }
            p[0] += dir[0];
            p[1] += dir[1];
            if(isOk(p[0], p[1]))
            {
                if(mapa[p[0]][p[1]] == 'E')
                {
                    ok = true;
                    break;
                }
                if(mapa[p[0]][p[1]] == '#')
                {
                    break;
                }
            }
            else
                break;
        }
        if(ok)
            x++;
        next_permutation(&perm[0], &perm[4]);
    }
    cout<<x<<endl;
    return 0;
}