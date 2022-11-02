#include <iostream>
using namespace std;
char c[102][102];
int n, m;
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
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(c[i][j]=='-')
            {
                cout<<"-";
            }
            else if(i%2==j%2)
            {
                cout<<"B";
            }
            else
            {
                cout<<"W";
            }
        }
        cout<<endl;
    }
    return 0;
}