#include <iostream>
using namespace std;
int n;
char c[200];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    if(n%2==0)
    {
        for(int i=1; i<=(n/2)-1; i++)
        {
            cout<<c[2*i-1]<<c[2*i]<<"-";
        }
        cout<<c[n-1]<<c[n];
    }
    else
    {
        n--;
        for(int i=1; i<=(n/2)-1; i++)
        {
            cout<<c[2*i-1]<<c[2*i]<<"-";
        }
        cout<<c[n-1]<<c[n]<<c[n+1];
    }

    return 0;
}