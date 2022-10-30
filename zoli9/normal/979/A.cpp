#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    n++;
    if(n%2==0)
    {
        cout<<(n/2)<<endl;
    }
    else cout<<n<<endl;

    return 0;
}