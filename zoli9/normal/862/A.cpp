#include <iostream>

using namespace std;

int main()
{
    int n,x,z;
    cin>>n>>x;
    int a[n];

    z=x;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        if (a[i]<x) z--;
        if (a[i]==x) z++;
    }
    cout<<z;
}