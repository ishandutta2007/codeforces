#include <iostream>
using namespace std;
int n, m;
long double a[509];
long double maxi=0;
int main()
{
    cout.precision(15);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        if(maxi<(a[x]+a[y])/z)
        {
            maxi=(a[x]+a[y])/z;
        }
    }
    cout<<maxi;
    return 0;
}