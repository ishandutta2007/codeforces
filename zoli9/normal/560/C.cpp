#include <iostream>
using namespace std;
int a, b, c, d, e, f;
int egyik, masik;
int ans;
int main()
{
    cin>>a>>b>>c>>d>>e>>f;
    ans=0;
    ans=(a+b)*(c+d);
    ans*=2;
    egyik=a*a;
    masik=d*d;
    ans-=egyik;
    ans-=masik;
    cout<<ans;
    return 0;
}