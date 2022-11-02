#include <iostream>
using namespace std;
int u, d, n;
int main()
{
    cin>>u;
    cin>>d;
    n=u+d+1;
    for(int i=n-u; i<=n; i++)
    {
        cout<<i<<" ";
    }
    for(int i=n-u-1; i>=1; i--)
    {
        cout<<i<<" ";
    }
    cout<<endl;




    return 0;
}