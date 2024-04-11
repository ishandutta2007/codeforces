#include <iostream>
using namespace std;
long long n;
long long hat(long long x)
{
    if(x==0)
    {
        return 1;
    }
    return 10*hat(x-1);
}
long long ans=0;
int main()
{
    cin>>n;
    for(int i=1; i<=12; i++)
    {
        if(!(n>=hat(i)))
        {
            ans+=(n-hat(i-1)+1)*i;
            cout<<ans;
            return 0;
        }
        ans+=(hat(i)-hat(i-1))*i;
    }
    return 0;
}