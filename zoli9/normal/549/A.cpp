#include <iostream>
using namespace std;
int n, m;
int db=0;
char c[59][59];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>c[i][j];
        }
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            bool v[30];
            for(int aa=0; aa<=25; aa++)
            {
                v[aa]=false;
            }
            v[c[i][j]-'a']=true;
            v[c[i+1][j]-'a']=true;
            v[c[i][j+1]-'a']=true;
            v[c[i+1][j+1]-'a']=true;
            if(v[0] and v[2] and v[4] and v[5])
            {
                db++;
            }
        }
    }
    cout<<db;

    return 0;
}