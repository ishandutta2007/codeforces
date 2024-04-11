#include <iostream>
using namespace std;
int n, m, a, b;
int leg1, leg2;
int main()
{
    cin>>n>>m;
    cin>>a>>b;
    for(int i=1; i<=n; i++)
    {
        int z;
        cin>>z;
        if(i==a) leg1=z;
    }
    for(int i=m; i>=1; i--)
    {
        int z;
        cin>>z;
        if(i==b) leg2=z;
    }
    if(leg2>leg1) cout<<"YES";
    else cout<<"NO";
    return 0;
}