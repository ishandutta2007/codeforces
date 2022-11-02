#include <iostream>
using namespace std;
int n;
int db=2;
long long maxi;
long long x[100009];
long long h[100009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>h[i];
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    maxi=x[1];
    for(int i=2; i<n; i++)
    {
        if(x[i]-h[i]>maxi)
        {
            db++;
            maxi=x[i];
        }
        else if(x[i]+h[i]<x[i+1])
        {
            db++;
            maxi=x[i]+h[i];
        }
        else
        {
            maxi=x[i];
        }
    }
    cout<<db;
    return 0;
}