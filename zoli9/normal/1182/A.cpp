#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2)
    {
        cout<<0<<endl;
        return 0;
    }
    long long a=1;
    for(int i=1; i<=n; i+=2)
    {
        a*=2;
    }
    cout<<a<<endl;

    return 0;
}