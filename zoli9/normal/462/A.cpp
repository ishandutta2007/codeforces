#include <iostream>
#include <string>
using namespace std;
int n;
bool v=true;
char c[200][200];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>c[i][j];
        }
    }
    for(int i=0; i<=n+1; i++)
    {
        c[0][i]='A';
        c[n+1][i]='A';
        c[i][0]='A';
        c[i][n+1]='A';
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int db=0;
            if(c[i-1][j]=='o')
            {
                db++;
            }
            if(c[i+1][j]=='o')
            {
                db++;
            }
            if(c[i][j-1]=='o')
            {
                db++;
            }
            if(c[i][j+1]=='o')
            {
                db++;
            }
            if(db%2==1)
            {
                v=false;
            }
        }
    }
    if(v)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }



    return 0;
}