#include <iostream>
using namespace std;
int n, m, x;
int main()
{
    cin>>n>>m;
    x=(n+1)/2;
    for(int i=x; i<=n; i++)
    {
        if(i%m==0)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;


    return 0;
}