#include <iostream>
using namespace std;
int n, k, x;
int main()
{
    cin>>n>>k;
    x=n-1-k;
    for(int i=1; i<=x; i++)
    {
        cout<<i<<" ";
    }
    int z=n-x;
    if(z%2==0)
    {
        for(int i=1; i<=z/2; i++)
        {
            cout<<x+i<<" ";
            cout<<n+1-i<<" ";
        }
    }
        else
        {
            for(int i=1; i<=(z-1)/2; i++)
            {
            cout<<x+i<<" ";
            cout<<n+1-i<<" ";
            }
            cout<<x+(z+1)/2<<" ";
        }
   cout<<endl;





        return 0;
}