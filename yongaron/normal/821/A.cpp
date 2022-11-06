#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int grid[55][55];
vector<int> rows[55];
vector<int> cols[55];

bool test(int x, int y);

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>grid[i][j];
            rows[i].push_back(grid[i][j]);
            cols[j].push_back(grid[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        sort(rows[i].begin(), rows[i].end());
        sort(cols[i].begin(), cols[i].end());
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!test(i, j))
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
bool test(int x, int y)
{
    if(grid[x][y] == 1)
        return true;
    int i = 0;
    int j = n-1;
    while(j >= 0 && i < n)
    {
        if(rows[x][i]+cols[y][j] == grid[x][y])
            return true;
        else if(rows[x][i]+cols[y][j] > grid[x][y])
            j--;
        else
            i++;
    }
    return false;
}