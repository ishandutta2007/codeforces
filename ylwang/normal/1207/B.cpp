#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,a[52][52],ans,x[2505],y[2505];
bool c[52][52];
int main()
{
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) cin >> a[i][j];
    for( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++)
        {
            if ( a[i][j] == 1 )
            {
                if( a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1 )
                {
                    ans++;//
                    x[ans] = i;
                    y[ans] = j;
                    c[i][j] = true;//
                    c[i+1][j] = true;
                    c[i][j+1] = true;
                    c[i+1][j+1] = true;
                }
                if( ( a[i+1][j] != 1 || a[i][j+1] != 1 || a[i+1][j+1] != 1 ) && !c[i][j]) 
                {
                    cout << -1 << endl;//
                    return 0;
                }
            }
        }
    cout << ans << endl;//
    for(int i = 1; i <= ans; i++)
    {
        cout << x[i] << " " << y[i] << endl;
    }
    return 0;
}